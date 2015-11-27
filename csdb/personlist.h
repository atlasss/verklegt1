#ifndef PERSONLIST_H
#define PERSONLIST_H

#include<iostream>
#include<vector>
#include "person.h"

using namespace std;

class personlist
{
private:
    vector<person> pList;
    int NOInList;

public:
    personlist();
    ~personlist();
    //baeta person vid listann
    void addPerson();
    //birta allan listann, radad eftir id
    void displayList();
    //birta allan listann radad i stafrofsrod
    void displayListAlpha();
    //birta listann ut fra nafni
    void displayListByName(string n);
    //birta listan ut fra kyni
    void displayListByGender(int g);
};

#endif // PERSONLIST_H
