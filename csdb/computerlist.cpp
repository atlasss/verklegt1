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

crel computerlist::getRel(int i, QSqlDatabase& dbMain){
    dbMain.open();
    crel n;
    QSqlQuery query(dbMain);
    query.prepare("SELECT p.name AS personName, p.id AS personId, c.name AS computerName, c.id AS computerId FROM personToComputer ptc JOIN computerData c ON c.id = :id JOIN personData p ON p.id = ptc.personId AND ptc.computerId = :id");
    query.bindValue(":id",i);
    if(query.exec()){
        while(query.next()){
            n.cName = query.value("computerName").toString().toStdString();
            n.cId = query.value("computerId").toUInt();
            n.pName.push_back(query.value("personName").toString().toStdString());
            n.pId.push_back(query.value("personId").toUInt());
        }
    }
    else{
        cout << "Not found" << endl;
    }
    return n;
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

    query.exec("SELECT * from computerData ORDER BY name");

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

    query.exec("SELECT * from computerData ORDER BY name DESC");

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

void computerlist::readFileAge(string m, QSqlDatabase& dbMain){
    int mid = 0, low = 0, high = 0, s = 0;

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

    for(int i = mid+1; i < m.size(); i++){
        high += (m[i]-48) * s;
        s /= 10;
    }


    cList.clear();
    NOInList = 0;
    //temporary variables
    string tname, ttype;
    bool tbuilt;
    int tid, tyearBuilt;

    dbMain.open();

    QSqlQuery query(dbMain);

    query.prepare("SELECT * FROM computerData WHERE yearBuilt > :low AND yearBuilt < :high ORDER BY yearBuilt ASC");
    query.bindValue(":low",low);
    query.bindValue(":high",high);
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

    query.prepare("SELECT * from computerData WHERE id = :id");
    query.bindValue(":id", i);
    query.exec();
    if(query.next()){
        tid = query.value("id").toUInt();
        tname = query.value("name").toString().toStdString();
        tyearBuilt = query.value("yearBuilt").toString().toUInt();
        ttype = query.value("type").toString().toStdString();
        tbuilt = query.value("type").toString().toUInt();

        addComputer(dbMain, computer(tid, tname, tyearBuilt, ttype, tbuilt));
    }
    else{
        cout << "No computer with this id found. " << endl;
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
