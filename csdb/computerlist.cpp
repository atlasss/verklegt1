#include <iostream>
#include <vector>
#include <string>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtSql>
#include <QVariant>
#include <algorithm>
#include "computerlist.h"

using namespace std;

computerlist::computerlist(){
    NOInList = 0;
    //computerdb = QSqlDatabase::addDatabase("QSQLITE");
}
computerlist::~computerlist(){

}
void computerlist::addComputer(QString dbName, computer newComputer){
    if(newComputer.getId() == -1){
        newComputer.setId(NOInList);
        writeToFile(dbName, newComputer);
    }
    else{
        //newPerson.isDateBirthValid();
        //newPerson.isDateDeathValid();
    }
    cList.push_back(newComputer);
    if(newComputer.getId() > NOInList){
        NOInList = newComputer.getId();
    }
    NOInList++;
}
void computerlist::editComputer(QString dbName, computer newComputer){

}
void computerlist::deleteComputer(){

}
void computerlist::readFile(QString dbName){
    cList.clear();
    //temporary variables
    string tname, ttype;
    bool tbuilt;
    int tid, tyearBuilt;

    computerdb.setDatabaseName(dbName);

    computerdb.open();

    QSqlQuery query(computerdb);

    query.exec("SELECT * from ComputerData");

    while(query.next()){

        tid = query.value("id").toUInt();
        tname = query.value("name").toString().toStdString();
        tyearBuilt = query.value("yearBuilt").toString().toUInt();
        ttype = query.value("type").toString().toStdString();
        tbuilt = query.value("type").toString().toUInt();

        addComputer(dbName, computer(tid, tname, tyearBuilt, ttype, tbuilt));
    }

    computerdb.close();
}

void computerlist::readFileAlpha(QString dbName){

}
void computerlist::readFileAlphaDec(QString dbName){

}


void computerlist::writeToFile(QString dbName, computer newComputer){

    computerdb.setDatabaseName(dbName);

    computerdb.open();

    QSqlQuery query(computerdb);

    query.prepare("INSERT INTO computerData (id, name, yearBuilt, type, built) "
                      "VALUES (:id, :name, :yearBuilt, :type, :built)");
    query.bindValue(":id", newComputer.getId());
    query.bindValue(":name", QString::fromStdString(newComputer.getName()));
    query.bindValue(":yearBuilt",  newComputer.getYearBuilt());
    query.bindValue(":type", QString::fromStdString(newComputer.getType()));
    query.bindValue(":built", newComputer.wasBuilt());

    if(query.exec()){
        cout << newComputer.getName()<< " has been added to db" << endl;

    }
    else{
        cout << "error" << endl;
    }


    computerdb.close();
}
