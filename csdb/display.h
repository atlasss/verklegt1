#ifndef DISPLAY_H
#define DISPLAY_H

#include<iostream>
#include<vector>
#include "person.h"

using namespace std;


class display
{
public:
    display();
    ~display();
    //requires user fills out a form to create one person that can be added to the list
    person fillForm();
    //prints out details of person p
    void printSingle(person personToPrint);

    //prints out a person that matches id
    void displayById(int i, vector<person> pList);

    //prints out the entire list, ordered by id
    void displayList(vector<person> pList);

    //prints the list in an alphabetical ascending order
    void displayListAlpha(vector<person> pList);

    //prints the list in an alphabetical descending order
    void displayListAlphaDesc(vector<person> pList);

    //prints the person that match string n
    void displayListByName(string n, vector<person> pList);

    //prints persons based on gender
    void displayListByGender(string g, vector<person> pList);

    //welcome screen which is printed out at the start of the program
    void printWelcome();

    //prints out description about how to use each available command
    void printHelp();
};

#endif // DISPLAY_H
