#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <QSqlDatabase>
#include "display.h"
#include "personlist.h"
#include "person.h"
#include "computer.h"
#include "computerlist.h"
class controller
{
private:
    bool end;
    display listDisplay;
    personlist listPerson;
    computerlist listComp;
    QSqlDatabase dbMain;
    //reads user command and determines which action should be executed
    void readCommand(string command);
public:
    controller();
    ~controller();
    //reads user command and passes it to readCommand
    void read();
    QString getdbName()const;
};

#endif // CONTROLLER_H
