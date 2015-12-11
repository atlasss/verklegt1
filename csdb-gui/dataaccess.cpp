#include "dataaccess.h"

dataAccess::dataAccess(){
    dbName = "csdb.sqlite";
    dbMain = QSqlDatabase::addDatabase("QSQLITE");
}

dataAccess::~dataAccess(){

}

void dataAccess::open(){
    dbMain.setDatabaseName(dbName);
    dbMain.open();
}
QSqlDatabase& dataAccess::readDb(){
    return dbMain;
}

void dataAccess::close(){
    dbMain.close();
}
