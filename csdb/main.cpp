#include <QCoreApplication>
#include <iostream>
#include <stdio.h>
#include <vector>
#include "person.h"
#include <string>

using namespace std;

string commands[] = {"find","add","sort","display"};

//prentar ut upplysingar yfir commands
void printHelp(){

}
//les skipun fra notenda og skilar nr yfir hvada skipun eigi ad framkvaema
int readCommand(string command){
    int cnumber = -1;
    for(unsigned int i = 0; i < (sizeof(commands)/sizeof(*commands)); i++){
        if(commands[i] == command)
            cnumber = i;
    };

    switch(cnumber)
    {
        //find
        case 0:
            //statement
            break;
        //add
        case 1:
            //statement;
            break;
        //sort
        case 2:
            //statement;
            break;
        //display
        case 3:
            //statement
            break;
        default:
            cout << "teo";
            //statement;

    }
    return -1;

}

int main()
{


    person newPerson;
    cin >> newPerson;

    cout << newPerson;
    return 0;
}

