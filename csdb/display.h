#ifndef DISPLAY_H
#define DISPLAY_H

#include<iostream>
#include<vector>
#include "person.h"
#include "computer.h"
#include "computerlist.h"
#include "personlist.h"

using namespace std;


class display{
public:
    display();
    ~display();
    //requires user fills out a form to create one person that can be added to the list
    person fillFormPerson();
    //requires user fills out a form to create one computer that can be added to the list
    computer fillFormComputer();
    //prints out details of person p
    void printSingle(person personToPrint);
    void printSingleComputer(computer computerToPrint);
    //prints out person list
    void displayListPerson(vector<person> pList);
    //prints out coputer list
    void displayListComputer(vector<computer> cList);
    //prints out relations from computer to persons
    void displayRelComputer(crel c);
    //prints out relations from person to computers
    void displayRelPerson(prel p);
    //welcome screen which is printed out at the start of the program
    void printWelcome();
    void printSecret();
    //prints out description about how to use each available command
    void printHelp();
};

#endif // DISPLAY_H
