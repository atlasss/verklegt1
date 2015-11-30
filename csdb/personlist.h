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
    int saved;

public:
    personlist();
    ~personlist();
    //baeta person vid listann
    void addPerson();
    //baeta person vid listann
    void addPerson(person newPerson);
    //breytir personu
    void editPerson(int i);
    //skilar fjolda staka i listanum
    int getListSize();
    //Birta person sem passar vid id
    void displayById(int i);
    //birta allan listann, radad eftir id
    void displayList();
    //birta allan listann radad i stafrofsrod
    void displayListAlpha();
    //birta listann ut fra nafni
    void displayListByName(string n);
    //birta listan ut fra kyni
    void displayListByGender(string g);
    //vistar breytingar
    void writeToFile(string fileName);
    void overwriteFile(string fileName);
};

#endif // PERSONLIST_H
