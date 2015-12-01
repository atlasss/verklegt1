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
    person fillForm();
public:
    personlist();
    ~personlist();
    //adds a new person to pList
    void addPerson();
    //adds a new person to pList
    void addPerson(person newPerson); 
    //prints one person from the list
    void printSingle(int index);
    //edits a person already in the list
    void editPerson(int i);
    //removes a person from the list
    void deletePerson(int index);
    //returns the number of persons in the list
    int getListSize();
    //prints out a person that matches id
    void displayById(int i);
    //prints out the entire list, ordered by id
    void displayList();
    //prints the list in alphabetical ascending order
    void displayListAlpha();
    //prints the person that match string n
    void displayListByName(string n);
    //prints persons based on gender
    void displayListByGender(string g);
    void printWelcome();
    //appends string with details of a person  in pList to txt file
    void writeToFile(string fileName);
    //overwrites  txt file with all details in pList
    void overwriteFile(string fileName);
};

#endif // PERSONLIST_H
