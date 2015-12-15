#include <iostream>
#include <vector>
#include <string>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtSql>
#include <QVariant>
#include <algorithm>
#include <fstream>
#include <cstring>
#include "personlist.h"

personlist::personlist(){
    NOInList = 0;
    saved = 0;
}

personlist::~personlist(){

}

void personlist::addPerson(QSqlDatabase& dbMain, person newPerson){
    if(newPerson.getId() == -1){
        newPerson.setId(NOInList);
        writeToFile(dbMain, newPerson);
    }
    else{
        saved++;
    }
    pList.push_back(newPerson);
    if(newPerson.getId() > NOInList){
        NOInList = newPerson.getId();
    }
    NOInList++;
}

void personlist::deletePerson(int index, QSqlDatabase& dbMain){


    QSqlQuery query(dbMain);

    query.prepare("DELETE from personData WHERE id = :id");
    query.bindValue(":id", index);
    query.exec();

}

vector<person> personlist::getFullList()const{
    return pList;
}

void personlist::editPerson(int i, person editPerson, QSqlDatabase& dbMain){

    QSqlQuery query(dbMain);

    query.prepare("Update personData SET name = :name, gender = :gender, dateBirth = :dateBirth, dateDeath = :dateDeath, knownFor = :knownFor, age = :age, bVal = :bVal, personPic = :pic WHERE id = :id");

    query.bindValue(":id", i);
    query.bindValue(":name",  QString::fromStdString(editPerson.getName()));
    query.bindValue(":gender", QString::fromStdString(editPerson.getGender()));
    query.bindValue(":dateBirth", QString::fromStdString(editPerson.getDateBirth()));
    query.bindValue(":dateDeath", QString::fromStdString(editPerson.getDateDeath()));
    query.bindValue(":knownFor", QString::fromStdString(editPerson.getKnownFor()));
    query.bindValue(":age", editPerson.getAge());
    query.bindValue(":bVal", editPerson.getBVal());
    query.bindValue(":pic", editPerson.getPic());
    query.exec();
}

int personlist::getListSize()const{
    return NOInList;
}

bool personlist::idExists(int i){
    for(unsigned int k = 0; k < pList.size(); k++){
        if(pList[k].getId() == i)
            return true;
    }
    return false;
}


void personlist::addRel(int p, int c, QSqlDatabase& dbMain){

    QSqlQuery query(dbMain);
    query.prepare("INSERT INTO personToComputer (computerId, personId) "
                      "VALUES (:cid, :pid)");
    query.bindValue(":cid", c);
    query.bindValue(":pid", p);
    query.exec();
}

void personlist::removeRel(int p, int c, QSqlDatabase& dbMain){

    QSqlQuery query(dbMain);
    query.prepare("DELETE from personToComputer WHERE personId = :pid AND computerId = :cid");
    query.bindValue(":cid", c);
    query.bindValue(":pid", p);
    query.exec();
}

prel personlist::getRel(int i, QSqlDatabase& dbMain){

    prel n;
    QSqlQuery query(dbMain);
    query.prepare("SELECT p.name AS personName, p.id AS personId, c.name AS computerName, c.id AS computerId FROM personToComputer ptc JOIN personData p ON p.id = :id JOIN computerData c ON c.id = ptc.computerId AND ptc.personId = :id");
    query.bindValue(":id",i);
    if(query.exec()){
        while(query.next()){
            n.pName = query.value("personName").toString().toStdString();
            n.pId = query.value("personId").toUInt();
            n.cName.push_back(query.value("computerName").toString().toStdString());
            n.cId.push_back(query.value("computerId").toUInt());
        }
    }

    return n;
}


void personlist::readFile(string n, string g, string a, QSqlDatabase& dbMain, bool asc){
    int mid = 0;
    double low = 0, high = 0, s = 0;

    if(!a.empty()){
        for(unsigned int i = 0; i < a.size(); i++){
            if(a[i] == '-'){
                mid =  i;
                break;
                }
        }
        s = pow(10,mid-1);

        for(int i = 0; i < mid; i++){
            low += (a[i]-48) * s;
            s /= 10;
        }
        s = pow(10, (a.size() -1) - (mid+1));

        for(unsigned int i = mid+1; i < a.size(); i++){
            high += (a[i]-48) * s;
            s /= 10;
        }
        low *= 365.25;
        high*= 365.25;
    }
    else{
        low = 0;
        high= 2000 * 365.25;
    }

    pList.clear();
    NOInList = 0;
    //temporary variables
    string tname, tgender, tbirth, tdeath, tknown;
    int tid, tage;
    QByteArray tpic;

    QSqlQuery query(dbMain);
    if(asc){
        query.prepare("SELECT * from personData "
                      "where name LIKE '%'||:name||'%' "
                      "AND gender LIKE :gender||'%'"
                      "AND (age < :high AND age > :low)"
                      "ORDER BY id");
        query.bindValue(":name",QString::fromStdString(n));
        query.bindValue(":gender",QString::fromStdString(g));
        query.bindValue(":low",low);
        query.bindValue(":high",high);
        query.exec();
        }

    else{
        query.prepare("SELECT * from personData "
                      "where name LIKE '%'||:name||'%' "
                      "AND gender LIKE :gender||'%'"
                      "AND (age < :high AND age > :low)"
                      "ORDER BY id DESC");
        query.bindValue(":name",QString::fromStdString(n));
        query.bindValue(":gender",QString::fromStdString(g));
        query.bindValue(":low",low);
        query.bindValue(":high",high);
        query.exec();
    }

    while(query.next()){
        tid = query.value("id").toUInt();
        tname = query.value("name").toString().toStdString();
        tgender = query.value("gender").toString().toStdString();
        tbirth = query.value("dateBirth").toString().toStdString();
        tdeath = query.value("dateDeath").toString().toStdString();
        tknown = query.value("knownFor").toString().toStdString();
        tage = query.value("age").toUInt();
        tpic = query.value("personPic").toByteArray();
        addPerson(dbMain, person(tid, tname, tgender, tbirth, tdeath, tknown, tage, tpic));

    }
}

void personlist::readFileAlpha(string n, string g, string a, QSqlDatabase& dbMain, bool asc){
    int mid = 0;
    double low = 0, high = 0, s = 0;

    if(a != ""){
        for(unsigned int i = 0; i < a.size(); i++){
            if(a[i] == '-'){
                mid =  i;
                break;
                }
        }
        s = pow(10,mid-1);

        for(int i = 0; i < mid; i++){
            low += (a[i]-48) * s;
            s /= 10;
        }
        s = pow(10, (a.size() -1) - (mid+1));

        for(unsigned int i = mid+1; i < a.size(); i++){
            high += (a[i]-48) * s;
            s /= 10;
        }
        low *= 365.25;
        high*= 365.25;
    }
    else{
        low = 0;
        high= 2000 * 365.25;
    }

    pList.clear();
    NOInList = 0;
    //temporary variables
    string tname, tgender, tbirth, tdeath, tknown;
    int tid, tage;
    QByteArray tpic;


    QSqlQuery query(dbMain);

    if(asc){
        query.prepare("SELECT * from personData "
                      "where name LIKE '%'||:name||'%' "
                      "AND gender LIKE :gender||'%'"
                      "AND (age < :high AND age > :low)"
                      "ORDER BY name");
        query.bindValue(":name",QString::fromStdString(n));
        query.bindValue(":gender",QString::fromStdString(g));
        query.bindValue(":low",low);
        query.bindValue(":high",high);
        query.exec();
        }

    else{
        query.prepare("SELECT * from personData "
                      "where name LIKE '%'||:name||'%' "
                      "AND gender LIKE :gender||'%'"
                      "AND (age < :high AND age > :low)"
                      "ORDER BY name DESC");
        query.bindValue(":name",QString::fromStdString(n));
        query.bindValue(":gender",QString::fromStdString(g));
        query.bindValue(":low",low);
        query.bindValue(":high",high);
        query.exec();
    }

    while(query.next()){
        tid = query.value("id").toUInt();
        tname = query.value("name").toString().toStdString();
        tgender = query.value("gender").toString().toStdString();
        tbirth = query.value("dateBirth").toString().toStdString();
        tdeath = query.value("dateDeath").toString().toStdString();
        tknown = query.value("knownFor").toString().toStdString();
        tage = query.value("age").toUInt();
        tpic = query.value("personPic").toByteArray();
        addPerson(dbMain, person(tid, tname, tgender, tbirth, tdeath, tknown, tage, tpic));
    }

}

void personlist::readFileYearBorn(string n, string g, string a, QSqlDatabase &dbMain, bool asc){
    int mid = 0;
    double low = 0, high = 0, s = 0;

    if(a != ""){
        for(unsigned int i = 0; i < a.size(); i++){
            if(a[i] == '-'){
                mid =  i;
                break;
                }
        }
        s = pow(10,mid-1);

        for(int i = 0; i < mid; i++){
            low += (a[i]-48) * s;
            s /= 10;
        }
        s = pow(10, (a.size() -1) - (mid+1));

        for(unsigned int i = mid+1; i < a.size(); i++){
            high += (a[i]-48) * s;
            s /= 10;
        }
        low *= 365.25;
        high*= 365.25;
    }
    else{
        low = 0;
        high= 2000 * 365.25;
    }

    pList.clear();
    NOInList = 0;
    //temporary variables
    string tname, tgender, tbirth, tdeath, tknown;
    int tid, tage;
    QByteArray tpic;


    QSqlQuery query(dbMain);

    if(asc){
        query.prepare("SELECT * from personData "
                      "where name LIKE '%'||:name||'%' "
                      "AND gender LIKE :gender||'%'"
                      "AND (age < :high AND age > :low)"
                      "ORDER BY bVal");
        query.bindValue(":name",QString::fromStdString(n));
        query.bindValue(":gender",QString::fromStdString(g));
        query.bindValue(":low",low);
        query.bindValue(":high",high);
        query.exec();
        }

    else{
        query.prepare("SELECT * from personData "
                      "where name LIKE '%'||:name||'%' "
                      "AND gender LIKE :gender||'%'"
                      "AND (age < :high AND age > :low)"
                      "ORDER BY bVal DESC");
        query.bindValue(":name",QString::fromStdString(n));
        query.bindValue(":gender",QString::fromStdString(g));
        query.bindValue(":low",low);
        query.bindValue(":high",high);
        query.exec();
    }

    while(query.next()){
        tid = query.value("id").toUInt();
        tname = query.value("name").toString().toStdString();
        tgender = query.value("gender").toString().toStdString();
        tbirth = query.value("dateBirth").toString().toStdString();
        tdeath = query.value("dateDeath").toString().toStdString();
        tknown = query.value("knownFor").toString().toStdString();
        tage = query.value("age").toUInt();
        tpic = query.value("personPic").toByteArray();
        addPerson(dbMain, person(tid, tname, tgender, tbirth, tdeath, tknown, tage, tpic));
    }

}


void personlist::readFileId(int i,QSqlDatabase& dbMain){
    pList.clear();
    NOInList = 0;
    //temporary variables
    string tname, tgender, tbirth, tdeath, tknown;
    int tid, tage;
    QByteArray tpic;


    QSqlQuery query(dbMain);

    query.prepare("SELECT * from personData WHERE id = :id");
    query.bindValue(":id",i);
    query.exec();
    while(query.next()){
        tid = query.value("id").toUInt();
        tname = query.value("name").toString().toStdString();
        tgender = query.value("gender").toString().toStdString();
        tbirth = query.value("dateBirth").toString().toStdString();
        tdeath = query.value("dateDeath").toString().toStdString();
        tknown = query.value("knownFor").toString().toStdString();
        tage = query.value("age").toUInt();
        tpic = query.value("personPic").toByteArray();
        addPerson(dbMain, person(tid, tname, tgender, tbirth, tdeath, tknown, tage, tpic));
    }

}


void personlist::updateAge(QSqlDatabase& dbMain){


    QSqlQuery query(dbMain);

    //if(query.exec("DELETE FROM personData"))

    for(unsigned int i = 0; i < pList.size(); i++){
        pList[i].isDateBirthValid();
        pList[i].isDateDeathValid();
        query.prepare("UPDATE personData (age, bVal) "
                      "VALUES (:bVal,:bVal)"
                      "WHERE id = :id");
        query.bindValue(":age", pList[i].getAge());
        query.bindValue(":bVal", pList[i].getBVal());
        query.bindValue(":id",i);
        query.exec();

    }



}

void personlist::writeToFile(QSqlDatabase& dbMain, person newPerson){


    QSqlQuery query(dbMain);

    query.prepare("INSERT INTO personData (id, name, gender, dateBirth, dateDeath, knownFor, age, bVal, personPic) "
                      "VALUES (:id, :name, :gender, :dateBirth, :dateDeath, :knownFor, :age, :bVal, :pic)");
    query.bindValue(":id", newPerson.getId());
    query.bindValue(":name", QString::fromStdString(newPerson.getName()));
    query.bindValue(":gender",  QString::fromStdString(newPerson.getGender()));
    query.bindValue(":dateBirth", QString::fromStdString(newPerson.getDateBirth()));
    query.bindValue(":dateDeath", QString::fromStdString(newPerson.getDateDeath()));
    query.bindValue(":knownFor", QString::fromStdString(newPerson.getKnownFor()));
    query.bindValue(":age", newPerson.getAge());
    query.bindValue(":bVal", newPerson.getBVal());
    query.bindValue(":pic", newPerson.getPic());
    query.exec();
}
