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
}
computerlist::~computerlist(){

}
void computerlist::addComputer(QSqlDatabase& dbMain, computer newComputer){
    if(newComputer.getId() == -1){
        newComputer.setId(NOInList);
        writeToFile(dbMain, newComputer);
    }
    cList.push_back(newComputer);
    if(newComputer.getId() > NOInList){
        NOInList = newComputer.getId();
    }
    NOInList++;
}
void computerlist::editComputer(QSqlDatabase& dbMain, computer newComputer){

}
void computerlist::deleteComputer(){

}

vector<computer>computerlist::getFullList(){
    return cList;
}

void computerlist::readFile(QSqlDatabase& dbMain){
    cList.clear();
    NOInList = 0;
    //temporary variables
    string tname, ttype;
    bool tbuilt;
    int tid, tyearBuilt;

    dbMain.open();

    QSqlQuery query(dbMain);

    query.exec("SELECT * from computerData");

    while(query.next()){

        tid = query.value("id").toUInt();
        tname = query.value("name").toString().toStdString();
        tyearBuilt = query.value("yearBuilt").toString().toUInt();
        ttype = query.value("type").toString().toStdString();
        tbuilt = query.value("type").toString().toUInt();

        addComputer(dbMain, computer(tid, tname, tyearBuilt, ttype, tbuilt));
    }

    dbMain.close();
}

void computerlist::readFileAlpha(QSqlDatabase& dbMain){
    cList.clear();
    NOInList = 0;
    //temporary variables
    string tname, ttype;
    bool tbuilt;
    int tid, tyearBuilt;

    dbMain.open();

    QSqlQuery query(dbMain);

    query.exec("SELECT * from computerData"
               "ORDER BY name");

    while(query.next()){

        tid = query.value("id").toUInt();
        tname = query.value("name").toString().toStdString();
        tyearBuilt = query.value("yearBuilt").toString().toUInt();
        ttype = query.value("type").toString().toStdString();
        tbuilt = query.value("type").toString().toUInt();

        addComputer(dbMain, computer(tid, tname, tyearBuilt, ttype, tbuilt));
    }

    dbMain.close();
}
void computerlist::readFileAlphaDec(QSqlDatabase& dbMain){
    cList.clear();
    NOInList = 0;
    //temporary variables
    string tname, ttype;
    bool tbuilt;
    int tid, tyearBuilt;

    dbMain.open();

    QSqlQuery query(dbMain);

    query.exec("SELECT * from computerData"
               "ORDER BY name DESC");

    while(query.next()){

        tid = query.value("id").toUInt();
        tname = query.value("name").toString().toStdString();
        tyearBuilt = query.value("yearBuilt").toString().toUInt();
        ttype = query.value("type").toString().toStdString();
        tbuilt = query.value("type").toString().toUInt();

        addComputer(dbMain, computer(tid, tname, tyearBuilt, ttype, tbuilt));
    }

    dbMain.close();
}


void computerlist::readFileName(string n, QSqlDatabase& dbMain){
    cList.clear();
    NOInList = 0;
    //temporary variables
    string tname, ttype;
    bool tbuilt;
    int tid, tyearBuilt;

    dbMain.open();

    QSqlQuery query(dbMain);

    query.prepare("SELECT * from computerData WHERE name LIKE '%'||:name||'%'");
    query.bindValue(":name",QString::fromStdString(n));
    query.exec();
    while(query.next()){

        tid = query.value("id").toUInt();
        tname = query.value("name").toString().toStdString();
        tyearBuilt = query.value("yearBuilt").toString().toUInt();
        ttype = query.value("type").toString().toStdString();
        tbuilt = query.value("type").toString().toUInt();

        addComputer(dbMain, computer(tid, tname, tyearBuilt, ttype, tbuilt));
    }

    dbMain.close();
}

void computerlist::readFileId(int i, QSqlDatabase& dbMain){
    cList.clear();
    NOInList = 0;
    //temporary variables
    string tname, ttype;
    bool tbuilt;
    int tid, tyearBuilt;

    dbMain.open();

    QSqlQuery query(dbMain);

    query.prepare("SELECT * from computerData"
               "WHERE id = :id");
    query.bindValue(":id", i);
    if(query.next()){
        tid = query.value("id").toUInt();
        tname = query.value("name").toString().toStdString();
        tyearBuilt = query.value("yearBuilt").toString().toUInt();
        ttype = query.value("type").toString().toStdString();
        tbuilt = query.value("type").toString().toUInt();

        addComputer(dbMain, computer(tid, tname, tyearBuilt, ttype, tbuilt));
    }
    else{
        cout << "No person with this id found. " << endl;
    }

    dbMain.close();
}


void computerlist::writeToFile(QSqlDatabase& dbMain, computer newComputer){
    dbMain.open();

    QSqlQuery query(dbMain);

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


    dbMain.close();
}
