#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include "display.h"
#include "personlist.h"
#include "person.h"

class controller
{
private:
    bool end;
    display listDisplay;
    personlist list;
    //reads user command and determines which action should be executed
    void readCommand(string command);
public:
    controller();
    ~controller();
    //reads user command and passes it to readCommand
    void read();
    QString getFileName()const;
};

#endif // CONTROLLER_H
