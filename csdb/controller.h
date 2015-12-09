#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <QSqlDatabase>
#include "display.h"
#include "personlist.h"
#include "person.h"
#include "computer.h"
#include "computerlist.h"
#include "dataaccess.h"

class controller{
private:
    bool end;
    display listDisplay;
    personlist listPerson;
    computerlist listComp;
    dataAccess db;
    //reads user command and determines which action should be executed
    void readCommand(string command);
    //validates user search input for -m
    bool validateAgeString(string a);
public:
    controller();
    ~controller();
    //reads user command and passes it to readCommand
    void read();
};

#endif // CONTROLLER_H
