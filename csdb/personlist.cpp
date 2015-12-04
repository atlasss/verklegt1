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
    persondb = QSqlDatabase::addDatabase("QSQLITE");
}

personlist::~personlist(){

}

void personlist::addPerson(QString dbName, person newPerson){
    if(newPerson.getId() == -1){
        newPerson.setId(NOInList);
        writeToFile(dbName, newPerson);
    }
    else{
        saved++;
        newPerson.isDateBirthValid();
        newPerson.isDateDeathValid();
    }
    pList.push_back(newPerson);
    if(newPerson.getId() > NOInList){
        NOInList = newPerson.getId();
    }
    NOInList++;
}

void personlist::deletePerson(int index, QString dbName){
    persondb.setDatabaseName(dbName);

    persondb.open();

    QSqlQuery query(persondb);

    query.prepare("DELETE from PersonData"
               "WHERE id = :id");
    query.bindValue(":id", index);
    query.exec();

    persondb.close();

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

void personlist::editPerson(int i, person editPerson, QString dbName){
    if(i >= 0 && i < NOInList){
        for(int k = 0; k < NOInList; k++){
            if(pList[k].getId() == i){
                pList[k].setName(editPerson.getName());
                pList[k].setDateBirth(editPerson.getDateBirth());
                pList[k].setDateDeath(editPerson.getDateDeath());
                pList[k].setGender(editPerson.getGender());
                pList[k].setKnownFor(editPerson.getKnownFor());


                persondb.setDatabaseName(dbName);
                persondb.open();
                QSqlQuery query(persondb);

                query.prepare("Update PersonData"
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
                persondb.close();

                break;
            }

        }
    }
    else{
        printf("Person with id %d was not found\n",i);
    }
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

void personlist::readFile(QString dbName){
    pList.clear();
    //temporary variables
    string tname, tgender, tbirth, tdeath, tknown;
    int tid;

    persondb.setDatabaseName(dbName);

    persondb.open();

    QSqlQuery query(persondb);

    query.exec("SELECT * from PersonData");

    while(query.next()){

        tid = query.value("id").toUInt();
        tname = query.value("name").toString().toStdString();
        tgender = query.value("gender").toString().toStdString();
        tbirth = query.value("dateBirth").toString().toStdString();
        tdeath = query.value("dateDeath").toString().toStdString();
        tknown = query.value("knownFor").toString().toStdString();

        addPerson(dbName, person(tid, tname, tgender, tbirth, tdeath, tknown));
    }

    persondb.close();

    /*
    ifstream data(fileName.c_str(), ios::in);

    if (data.is_open()){

        while(data >> tid >> tname >> tgender >> tbirth >> tdeath >> tknown){

        }


        data.close();
    }
    else{
        cout << strerror(errno) << endl;
    }
    */

}

void personlist::overwriteFile(QString dbName){
    persondb.setDatabaseName(dbName);

    persondb.open();

    QSqlQuery query(persondb);
    query.exec("DELETE * FROM PersonData");

    for(int i = 0; i < NOInList; i++){
        pList[i].isDateBirthValid();
        pList[i].isDateDeathValid();
        writeToFile(dbName, pList[i]);
    }

    /*
    ofstream data (fileName);
    saved = 0;
    for(int i = saved; i < NOInList; i++){
        data << pList[i].getData() << endl;
        saved++;
    }

    data.close();
    */
}

void personlist::writeToFile(QString dbName, person newPerson){

    persondb.setDatabaseName(dbName);

    persondb.open();

    QSqlQuery query(persondb);

    query.prepare("INSERT INTO PersonData (id, name, gender, dateBirth, dateDeath, knownFor, age) "
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


    persondb.close();
}
