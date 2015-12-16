#include <iostream>
#include <vector>
#include <string>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtSql>
#include <QVariant>
#include <algorithm>
#include "computerlist.h"
#include <QMessageBox>
using namespace std;

computerlist::computerlist(){
    NOInList = 0;
}
computerlist::~computerlist(){

}
bool computerlist::addComputer(QSqlDatabase& dbMain, computer newComputer){
    bool success;

    if(newComputer.getId() == -1){
        newComputer.setId(NOInList);
        success = writeToFile(dbMain, newComputer);
    }
    cList.push_back(newComputer);
    if(newComputer.getId() > NOInList){
        NOInList = newComputer.getId();
    }
    NOInList++;
    return success;
}
void computerlist::editComputer(int i, computer editComputer,  QSqlDatabase& dbMain){

    QSqlQuery query(dbMain);

    query.prepare("Update computerData SET name = :name, yearBuilt = :yearBuilt, type = :type, built = :built, weight = :weight, computerPic = :pic WHERE id = :id");

    query.bindValue(":id", i);
    query.bindValue(":name",  QString::fromStdString(editComputer.getName()));
    query.bindValue(":yearBuilt", editComputer.getYearBuilt());
    query.bindValue(":type", QString::fromStdString(editComputer.getType()));
    query.bindValue(":built", editComputer.wasBuilt());
    query.bindValue(":weight", editComputer.getWeight());
    query.bindValue(":pic", editComputer.getPic());
    query.exec();
}
void computerlist::deleteComputer(int index, QSqlDatabase& dbMain){


    QSqlQuery query(dbMain);

    query.prepare("DELETE FROM computerData WHERE id = :id");
    query.bindValue(":id", index);
    query.exec();
}

vector<computer>computerlist::getFullList(){
    return cList;
}

bool computerlist::idExists(int i){
    for(int k = 0; k < NOInList; k++){
        if(cList[k].getId() == i)
            return true;
    }
    return false;
}

crel computerlist::getRel(int i, QSqlDatabase& dbMain){

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

    return n;
}

void computerlist::readFile(string n, string a, string t, int b, QSqlDatabase& dbMain, bool asc){
    int mid = 0, low = 0, high = 0, s = 0;
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

        for(int i = mid+1; i < a.size(); i++){
            high += (a[i]-48) * s;
            s /= 10;
        }
    }
    else{
        low = -2;
        high= 2015;
    }

    cList.clear();
    NOInList = 0;
    //temporary variables
    string tname, ttype;
    bool tbuilt;
    int tid, tyearBuilt;
    double tweight;
    QByteArray tpic;

    QSqlQuery query(dbMain);
    if(asc){
        query.prepare("SELECT * from computerData "
                      "WHERE name LIKE '%'||:name||'%' "
                      "AND type LIKE :type||'%' "
                      "AND (yearBuilt < :high AND yearBuilt > :low) "
                      "AND built = :built "
                      "ORDER BY id");
        query.bindValue(":name", QString::fromStdString(n));
        query.bindValue(":type", QString::fromStdString(t));
        query.bindValue(":high", high);
        query.bindValue(":low", -2000);
        query.bindValue(":built", b);
        query.exec();
    }
    else{
        query.prepare("SELECT * from computerData "
                      "WHERE name LIKE '%'||:name||'%' "
                      "AND type LIKE :type||'%' "
                      "AND (yearBuilt < :high AND yearBuilt > :low) "
                      "AND built = :built "
                      "ORDER BY id DESC");
        query.bindValue(":name", QString::fromStdString(n));
        query.bindValue(":type", QString::fromStdString(t));
        query.bindValue(":high", high);
        query.bindValue(":low", -2000);
        query.bindValue(":built", b);
        query.exec();
    }
    while(query.next()){
        tid = query.value("id").toUInt();
        tname = query.value("name").toString().toStdString();
        tyearBuilt = query.value("yearBuilt").toString().toUInt();
        ttype = query.value("type").toString().toStdString();
        tbuilt = query.value("built").toUInt();
        tweight = query.value("weight").toDouble();
        tpic = query.value("computerPic").toByteArray();
        addComputer(dbMain, computer(tid, tname, tyearBuilt, ttype, tbuilt, tweight,tpic));
    }


}

void computerlist::readFileAlpha(string n, string a, string t, int b, QSqlDatabase& dbMain, bool asc){
    int mid = 0, low = 0, high = 0, s = 0;
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

        for(int i = mid+1; i < a.size(); i++){
            high += (a[i]-48) * s;
            s /= 10;
        }
    }
    else{
        low = -2;
        high= 2015;
    }


    cList.clear();
    NOInList = 0;
    //temporary variables
    string tname, ttype;
    bool tbuilt;
    int tid, tyearBuilt;
    double tweight;
    QByteArray tpic;

    QSqlQuery query(dbMain);
    if(asc){
        query.prepare("SELECT * from computerData "
                      "WHERE name LIKE '%'||:name||'%' "
                      "AND type LIKE :type||'%' "
                      "AND (yearBuilt < :high AND yearBuilt > :low) "
                      "AND built = :built "
                      "ORDER BY name COLLATE NOCASE");
        query.bindValue(":name", QString::fromStdString(n));
        query.bindValue(":type", QString::fromStdString(t));
        query.bindValue(":high", (high));
        query.bindValue(":low", low);
        query.bindValue(":built", b);
        query.exec();
    }
    else{
        query.prepare("SELECT * from computerData "
                      "WHERE name LIKE '%'||:name||'%' "
                      "AND type LIKE :type||'%' "
                      "AND (yearBuilt < :high AND yearBuilt > :low) "
                      "AND built = :built "
                      "ORDER BY name COLLATE NOCASE DESC");
        query.bindValue(":name", QString::fromStdString(n));
        query.bindValue(":type", QString::fromStdString(t));
        query.bindValue(":high", high);
        query.bindValue(":low", low);
        query.bindValue(":built", b);
        query.exec();
    }

    while(query.next()){
        tid = query.value("id").toUInt();
        tname = query.value("name").toString().toStdString();
        tyearBuilt = query.value("yearBuilt").toString().toUInt();
        ttype = query.value("type").toString().toStdString();
        tbuilt = query.value("built").toUInt();
        tweight = query.value("weight").toDouble();
        tpic = query.value("computerPic").toByteArray();
        addComputer(dbMain, computer(tid, tname, tyearBuilt, ttype, tbuilt, tweight,tpic));
    }
}

void computerlist::readFileAge(string n, string a, string t, int b, QSqlDatabase& dbMain, bool asc){
    int mid = 0, low = 0, high = 0, s = 0;
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

        for(int i = mid+1; i < a.size(); i++){
            high += (a[i]-48) * s;
            s /= 10;
        }
    }
    else{
        low = -2;
        high= 2015;
    }

    cList.clear();
    NOInList = 0;
    //temporary variables
    string tname, ttype;
    bool tbuilt;
    int tid, tyearBuilt;
    double tweight;
    QByteArray tpic;

    QSqlQuery query(dbMain);
    if(asc){
        query.prepare("SELECT * from computerData "
                      "WHERE name LIKE '%'||:name||'%' "
                      "AND type LIKE :type||'%' "
                      "AND (yearBuilt < :high AND yearBuilt > :low) "
                      "AND built = :built "
                      "ORDER BY yearBuilt");
        query.bindValue(":name", QString::fromStdString(n));
        query.bindValue(":type", QString::fromStdString(t));
        query.bindValue(":high", (high));
        query.bindValue(":low", low);
        query.bindValue(":built", b);
        query.exec();
    }
    else{
        query.prepare("SELECT * from computerData "
                      "WHERE name LIKE '%'||:name||'%' "
                      "AND type LIKE :type||'%' "
                      "AND (yearBuilt < :high AND yearBuilt > :low) "
                      "AND built = :built "
                      "ORDER BY yearBuilt DESC");
        query.bindValue(":name", QString::fromStdString(n));
        query.bindValue(":type", QString::fromStdString(t));
        query.bindValue(":high", high);
        query.bindValue(":low", low);
        query.bindValue(":built", b);
        query.exec();
    }

    while(query.next()){
        tid = query.value("id").toUInt();
        tname = query.value("name").toString().toStdString();
        tyearBuilt = query.value("yearBuilt").toString().toUInt();
        ttype = query.value("type").toString().toStdString();
        tbuilt = query.value("built").toUInt();
        tweight = query.value("weight").toDouble();
        tpic = query.value("computerPic").toByteArray();
        addComputer(dbMain, computer(tid, tname, tyearBuilt, ttype, tbuilt, tweight,tpic));
    }

}

void computerlist::readFileId(int i, QSqlDatabase& dbMain){
    cList.clear();
    NOInList = 0;
    //temporary variables
    string tname, ttype;
    bool tbuilt;
    int tid, tyearBuilt;
    double tweight;
    QByteArray tpic;

    QSqlQuery query(dbMain);

    query.prepare("SELECT * from computerData WHERE id = :id");
    query.bindValue(":id", i);
    query.exec();
    if(query.next()){
        tid = query.value("id").toUInt();
        tname = query.value("name").toString().toStdString();
        tyearBuilt = query.value("yearBuilt").toString().toUInt();
        ttype = query.value("type").toString().toStdString();
        tbuilt = query.value("built").toUInt();
        tweight = query.value("weight").toDouble();
        tpic = query.value("computerPic").toByteArray();
        addComputer(dbMain, computer(tid, tname, tyearBuilt, ttype, tbuilt, tweight,tpic));
    }


}

void computerlist::readFileWeight(string n, string a, string t, int b, QSqlDatabase& dbMain, bool asc){
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
        low = -2;
        high= 2000 * 365.25;
    }

    cList.clear();
    NOInList = 0;
    //temporary variables
    string tname, ttype;
    bool tbuilt;
    int tid, tyearBuilt;
    double tweight;
    QByteArray tpic;

    QSqlQuery query(dbMain);
    if(asc){
        query.prepare("SELECT * from computerData "
                      "WHERE name LIKE '%'||:name||'%' "
                      "AND type LIKE :type||'%' "
                      "AND (yearBuilt < :high AND yearBuilt > :low) "
                      "AND built == :built "
                      "ORDER BY weight");
        query.bindValue(":name", QString::fromStdString(n));
        query.bindValue(":type", QString::fromStdString(t));
        query.bindValue(":high", (high));
        query.bindValue(":low", low);
        query.bindValue(":built", b);
        query.exec();
    }
    else{
        query.prepare("SELECT * from computerData "
                      "WHERE name LIKE '%'||:name||'%' "
                      "AND type LIKE :type||'%' "
                      "AND (yearBuilt < :high AND yearBuilt > :low) "
                      "AND built == :built "
                      "ORDER BY weight DESC");
        query.bindValue(":name", QString::fromStdString(n));
        query.bindValue(":type", QString::fromStdString(t));
        query.bindValue(":high", high);
        query.bindValue(":low", low);
        query.bindValue(":built", b);
        query.exec();
    }

    while(query.next()){
        tid = query.value("id").toUInt();
        tname = query.value("name").toString().toStdString();
        tyearBuilt = query.value("yearBuilt").toString().toUInt();
        ttype = query.value("type").toString().toStdString();
        tbuilt = query.value("built").toUInt();
        tweight = query.value("weight").toDouble();
        tpic = query.value("computerPic").toByteArray();
        addComputer(dbMain, computer(tid, tname, tyearBuilt, ttype, tbuilt, tweight,tpic));
    }
}

bool computerlist::writeToFile(QSqlDatabase& dbMain, computer newComputer){
    QSqlQuery query(dbMain);

    query.prepare("INSERT INTO computerData (id, name, yearBuilt, type, built, weight, computerPic) "
                      "VALUES (:id, :name, :yearBuilt, :type, :built, :weight, :pic)");
    query.bindValue(":id", newComputer.getId());
    query.bindValue(":name", QString::fromStdString(newComputer.getName()));
    query.bindValue(":yearBuilt",  newComputer.getYearBuilt());
    query.bindValue(":type", QString::fromStdString(newComputer.getType()));
    query.bindValue(":built", newComputer.wasBuilt());
    query.bindValue(":weight", newComputer.getWeight());
    query.bindValue(":pic", newComputer.getPic());
    if(query.exec())
        return true;
    else
        return false;

}

