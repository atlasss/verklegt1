#ifndef PERSONLIST_H
#define PERSONLIST_H
#include <QSqlDatabase>
#include<iostream>
#include<vector>
#include "person.h"

using namespace std;

struct prel{
    string pName;
    vector<string> cName;
    int pId;
    vector<int> cId;
};

class personlist{
private:
    vector<person> pList;    
    int NOInList;
    int saved;


public:
    personlist();
    ~personlist();
    //adds a new person to pList
    void addPerson(QSqlDatabase& dbMain, person newPerson);
    //edits a person already in the list
    void editPerson(int i, person editPerson, QSqlDatabase& dbMain);
    //removes a person from the list
    void deletePerson(int index, QSqlDatabase& dbMain);
    //returns the vector pList
    vector<person> getFullList()const;
    //create new connection between person and computer
    void addRel(int p, int c, QSqlDatabase& dbMain);
    //remove connection between a person and computer
    void removeRel(int p, int c, QSqlDatabase& dbMain);
    prel getRel(int i, QSqlDatabase& dbMain);
    //returns the number of persons in the list
    int getListSize()const;
    //returns true if id is found in pList
    bool idExists(int i);
    //adds persons from database file to pList
    void readFile(QSqlDatabase& dbMain);
    //adds persons from database alphabetically from database to pList
    void readFileAlpha(QSqlDatabase& dbMain);
    //adds persons from database alphabetically in descending order from database to pList
    void readFileAlphaDesc(QSqlDatabase& dbMain);
    void readFileId(int i,QSqlDatabase& dbMain);
    void readFileName(string n,QSqlDatabase& dbMain);
    void readFileGender(string g,QSqlDatabase& dbMain);
    void readFileAge(string m, QSqlDatabase& dbMain);
    //appends string with details of a person  in pList to txt file
    void writeToFile(QSqlDatabase& dbMain, person newPerson);
    //overwrites database with all details in pList
    void overwriteFile(QSqlDatabase& dbMain);
};

#endif // PERSONLIST_H

