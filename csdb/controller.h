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
    //decides
    void readCommand(string command);
public:
    controller();
    ~controller();
    //reads and executes a command from the user
    void read();
    string getFileName()const;
};

#endif // CONTROLLER_H
