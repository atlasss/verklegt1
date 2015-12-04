#include "computerlist.h"

computerlist::computerlist(){
    computerdb = QSqlDatabase::addDatabase("QSQLITE");
}
computerlist::~computerlist(){

}
void computerlist::addComputer(){

}
void computerlist::editComputer(){

}
void computerlist::deleteComputer(){

}
void computerlist::readFile(QString dbName){

}

void computerlist::writeToFile(QString dbName, computer newComputer){

}

void computerlist::overwriteFile(QString dbName){

}
