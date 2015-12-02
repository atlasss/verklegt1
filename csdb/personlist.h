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
    //adds a new person to pList
    void addPerson(person newPerson); 
    //edits a person already in the list
    void editPerson(int i, person editPerson);
    //removes a person from the list
    void deletePerson(int index);
    //returns the vector pList
    vector<person> getFullList()const;
    //returns the number of persons in the list
    int getListSize()const;
    //adds persons from txt file to pList
    void readFile(string fileName);
    //appends string with details of a person  in pList to txt file
    void writeToFile(string fileName);
    //overwrites  txt file with all details in pList
    void overwriteFile(string fileName);
};

#endif // PERSONLIST_H








/*removed:
    void printSingle(int index);
    //prints out a person that matches id
    void displayById(int i);
    //prints out the entire list, ordered by id
    void displayList();
    //prints the list in an alphabetical ascending order
    void displayListAlpha();
    //prints the list in an alphabetical descending order
    void displayListAlphaDesc();
    //prints the person that match string n
    void displayListByName(string n);
    //prints persons based on gender
    void displayListByGender(string g);
    void printWelcome();
    person fillForm();
*/
