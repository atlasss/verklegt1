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
    dbMain.open();

    QSqlQuery query(dbMain);

    query.prepare("DELETE from personData"
               "WHERE id = :id");
    query.bindValue(":id", index);
    query.exec();

    dbMain.close();

    vector<person> newList;
    for(int i = 0; i < NOInList; i++){
        if(pList[i].getId() != index)
            newList.push_back(pList[i]);
    }
    pList.swap(newList);
    NOInList--;
}

vector<person> personlist::getFullList()const{
    return pList;
}

void personlist::editPerson(unsigned int i, person editPerson, QSqlDatabase& dbMain){
    if(i < NOInList){
        for(int k = 0; k < NOInList-1; k++){
            if(pList[k].getId() == i){
                pList[k].setName(editPerson.getName());
                pList[k].setDateBirth(editPerson.getDateBirth());
                pList[k].setDateDeath(editPerson.getDateDeath());
                pList[k].setGender(editPerson.getGender());
                pList[k].setKnownFor(editPerson.getKnownFor());
                break;
            }

        }
    }
    //dbMain.setDatabaseName(dbMain);
    dbMain.open();
    QSqlQuery query(dbMain);

    query.prepare("Update personData"
               "SET name = :name, gender = :gender, "
               "dateBirth = :dateBirth, dateDeath = :dateDeath, knownFor = :knownFor, age = :age "
               "WHERE id = :id");

    query.bindValue(":id", i);
    query.bindValue(":name",  QString::fromStdString(editPerson.getName()));
    query.bindValue(":gender", QString::fromStdString(editPerson.getGender()));
    query.bindValue(":dateBirth", QString::fromStdString(editPerson.getDateBirth()));
    query.bindValue(":dateDeath", QString::fromStdString(editPerson.getDateDeath()));
    query.bindValue(":knownFor", QString::fromStdString(editPerson.getKnownFor()));
    query.bindValue(":age", editPerson.getAge());
    if(query.exec())
        cout << "Person updated. " << endl;

}

int personlist::getListSize()const{
    return NOInList;
}

bool personlist::idExists(int i){
    for(int k = 0; k < NOInList; k++){
        if(pList[k].getId() == i)
            return true;
    }
    return false;
}

void personlist::readFile(QSqlDatabase& dbMain){
    pList.clear();
    //temporary variables
    string tname, tgender, tbirth, tdeath, tknown;
    int tid, tage;

    dbMain.open();

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
    dbMain.close();

}

void personlist::overwriteFile(QSqlDatabase& dbMain){
    dbMain.open();

    QSqlQuery query(dbMain);
    if(query.exec("DELETE FROM personData")){
        cout << "Overwrite..." << endl;
    }

    cout << pList.size() << endl;
    for(int i = 0; i < pList.size(); i++){
        pList[i].isDateBirthValid();
        pList[i].isDateDeathValid();
        cout << pList[i].getAge() << endl;
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

    dbMain.close();

}

void personlist::writeToFile(QSqlDatabase& dbMain, person newPerson){
    dbMain.open();

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
    if(query.exec()){
        cout << newPerson.getName()<< " has been added to db" << endl;

    }


    dbMain.close();
}
