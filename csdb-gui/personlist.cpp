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

    query.prepare("Update personData SET name = :name, gender = :gender, dateBirth = :dateBirth, dateDeath = :dateDeath, knownFor = :knownFor, age = :age WHERE id = :id");

    query.bindValue(":id", i);
    query.bindValue(":name",  QString::fromStdString(editPerson.getName()));
    query.bindValue(":gender", QString::fromStdString(editPerson.getGender()));
    query.bindValue(":dateBirth", QString::fromStdString(editPerson.getDateBirth()));
    query.bindValue(":dateDeath", QString::fromStdString(editPerson.getDateDeath()));
    query.bindValue(":knownFor", QString::fromStdString(editPerson.getKnownFor()));
    query.bindValue(":age", editPerson.getAge());
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


void personlist::readFile(QSqlDatabase& dbMain){
    pList.clear();
    NOInList = 0;
    //temporary variables
    string tname, tgender, tbirth, tdeath, tknown;
    int tid, tage;



    QSqlQuery query(dbMain);

    query.exec("SELECT * from personData");

    while(query.next()){
        tid = query.value("id").toUInt();
        tname = query.value("name").toString().toStdString();
        tgender = query.value("gender").toString().toStdString();
        tbirth = query.value("dateBirth").toString().toStdString();
        tdeath = query.value("dateDeath").toString().toStdString();
        tknown = query.value("knownFor").toString().toStdString();
        tage = query.value("age").toUInt();
        addPerson(dbMain, person(tid, tname, tgender, tbirth, tdeath, tknown, tage));
    }

}

void personlist::readFileAlpha(QSqlDatabase& dbMain){
    pList.clear();
    NOInList = 0;
    //temporary variables
    string tname, tgender, tbirth, tdeath, tknown;
    int tid, tage;



    QSqlQuery query(dbMain);

    query.exec("SELECT * from personData ORDER BY name ");

    while(query.next()){
        tid = query.value("id").toUInt();
        tname = query.value("name").toString().toStdString();
        tgender = query.value("gender").toString().toStdString();
        tbirth = query.value("dateBirth").toString().toStdString();
        tdeath = query.value("dateDeath").toString().toStdString();
        tknown = query.value("knownFor").toString().toStdString();
        tage = query.value("age").toUInt();
        addPerson(dbMain, person(tid, tname, tgender, tbirth, tdeath, tknown, tage));
    }

}
void personlist::readFileAlphaDesc(QSqlDatabase& dbMain){
    pList.clear();
    NOInList = 0;
    //temporary variables
    string tname, tgender, tbirth, tdeath, tknown;
    int tid, tage;



    QSqlQuery query(dbMain);

    query.exec("SELECT * from personData ORDER BY name DESC");

    while(query.next()){
        tid = query.value("id").toUInt();
        tname = query.value("name").toString().toStdString();
        tgender = query.value("gender").toString().toStdString();
        tbirth = query.value("dateBirth").toString().toStdString();
        tdeath = query.value("dateDeath").toString().toStdString();
        tknown = query.value("knownFor").toString().toStdString();
        tage = query.value("age").toUInt();
        addPerson(dbMain, person(tid, tname, tgender, tbirth, tdeath, tknown, tage));
    }

}

void personlist::readFileId(int i,QSqlDatabase& dbMain){
    pList.clear();
    NOInList = 0;
    //temporary variables
    string tname, tgender, tbirth, tdeath, tknown;
    int tid, tage;



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
        addPerson(dbMain, person(tid, tname, tgender, tbirth, tdeath, tknown, tage));
    }

}

void personlist::readFileName(string n,QSqlDatabase& dbMain){
    pList.clear();
    NOInList = 0;
    //temporary variables
    string tname, tgender, tbirth, tdeath, tknown;
    int tid, tage;



    QSqlQuery query(dbMain);

    query.prepare("SELECT * from personData where name LIKE '%'||:name||'%'");
    query.bindValue(":name",QString::fromStdString(n));
    query.exec();
    while(query.next()){
        tid = query.value("id").toUInt();
        tname = query.value("name").toString().toStdString();
        tgender = query.value("gender").toString().toStdString();
        tbirth = query.value("dateBirth").toString().toStdString();
        tdeath = query.value("dateDeath").toString().toStdString();
        tknown = query.value("knownFor").toString().toStdString();
        tage = query.value("age").toUInt();
        addPerson(dbMain, person(tid, tname, tgender, tbirth, tdeath, tknown, tage));
    }

}

void personlist::readFileGender(string g, QSqlDatabase& dbMain){

    transform(g.begin(), g.end(), g.begin(), ::tolower);

    if(g[0] == 'f')
        g[0] = 'F';
    else if(g[0] == 'm')
        g[0] = 'M';

    if(g == "Male" || g == "Female"){
        pList.clear();
        NOInList = 0;
        //temporary variables
        string tname, tgender, tbirth, tdeath, tknown;
        int tid, tage;



        QSqlQuery query(dbMain);

        query.prepare("SELECT * from personData WHERE gender = :gender");
        query.bindValue(":gender",QString::fromStdString(g));
        query.exec();
        while(query.next()){
            tid = query.value("id").toUInt();
            tname = query.value("name").toString().toStdString();
            tgender = query.value("gender").toString().toStdString();
            tbirth = query.value("dateBirth").toString().toStdString();
            tdeath = query.value("dateDeath").toString().toStdString();
            tknown = query.value("knownFor").toString().toStdString();
            tage = query.value("age").toUInt();
            addPerson(dbMain, person(tid, tname, tgender, tbirth, tdeath, tknown, tage));
        }

    }
}
void personlist::readFileAge(string m,QSqlDatabase& dbMain){
    int mid = 0;
    double low = 0, high = 0, s = 0;

    for(unsigned int i = 0; i < m.size(); i++){
        if(m[i] == '-'){
            mid =  i;
            break;
            }
    }
    s = pow(10,mid-1);

    for(int i = 0; i < mid; i++){
        low += (m[i]-48) * s;
        s /= 10;
    }
    s = pow(10, (m.size() -1) - (mid+1));

    for(unsigned int i = mid+1; i < m.size(); i++){
        high += (m[i]-48) * s;
        s /= 10;
    }
    low *= 365.25;
    high*= 365.25;

    pList.clear();
    NOInList = 0;
    //temporary variables
    string tname, tgender, tbirth, tdeath, tknown;
    int tid, tage;



    QSqlQuery query(dbMain);

    query.prepare("SELECT * FROM personData WHERE age > :low AND age < :high ORDER BY age ASC");
    query.bindValue(":low",low);
    query.bindValue(":high",high);
    query.exec();
    while(query.next()){
        tid = query.value("id").toUInt();
        tname = query.value("name").toString().toStdString();
        tgender = query.value("gender").toString().toStdString();
        tbirth = query.value("dateBirth").toString().toStdString();
        tdeath = query.value("dateDeath").toString().toStdString();
        tknown = query.value("knownFor").toString().toStdString();
        tage = query.value("age").toUInt();
        addPerson(dbMain, person(tid, tname, tgender, tbirth, tdeath, tknown, tage));
    }


}


void personlist::overwriteFile(QSqlDatabase& dbMain){


    QSqlQuery query(dbMain);

    if(query.exec("DELETE FROM personData"))

    for(unsigned int i = 0; i < pList.size(); i++){
        pList[i].isDateBirthValid();
        pList[i].isDateDeathValid();
        query.prepare("INSERT INTO personData (id, name, gender, dateBirth, dateDeath, knownFor, age) "
                          "VALUES (:id, :name, :gender, :dateBirth, :dateDeath, :knownFor, :age)");
        query.bindValue(":id", pList[i].getId());
        query.bindValue(":name", QString::fromStdString(pList[i].getName()));
        query.bindValue(":gender",  QString::fromStdString(pList[i].getGender()));
        query.bindValue(":dateBirth", QString::fromStdString(pList[i].getDateBirth()));
        query.bindValue(":dateDeath", QString::fromStdString(pList[i].getDateDeath()));
        query.bindValue(":knownFor", QString::fromStdString(pList[i].getKnownFor()));
        query.bindValue(":age", pList[i].getAge());
        query.exec();

    }



}

void personlist::writeToFile(QSqlDatabase& dbMain, person newPerson){


    QSqlQuery query(dbMain);

    query.prepare("INSERT INTO personData (id, name, gender, dateBirth, dateDeath, knownFor, age) "
                      "VALUES (:id, :name, :gender, :dateBirth, :dateDeath, :knownFor, :age)");
    query.bindValue(":id", newPerson.getId());
    query.bindValue(":name", QString::fromStdString(newPerson.getName()));
    query.bindValue(":gender",  QString::fromStdString(newPerson.getGender()));
    query.bindValue(":dateBirth", QString::fromStdString(newPerson.getDateBirth()));
    query.bindValue(":dateDeath", QString::fromStdString(newPerson.getDateDeath()));
    query.bindValue(":knownFor", QString::fromStdString(newPerson.getKnownFor()));
    query.bindValue(":age", newPerson.getAge());
    query.exec();




}
