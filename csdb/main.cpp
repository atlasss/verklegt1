#include <QCoreApplication>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include "person.h"
#include "personlist.h"
#include <string>

using namespace std;

string commands[] = {"find","add","sort","display","quit","help"};
personlist List;
bool loop;

//prentar ut upplysingar yfir commands
void printHelp(){
    for(int i = 0; i < (sizeof(commands)/sizeof(*commands)); i++){
        cout << '-' << commands[i] << endl;
    }
}
//les skipun fra notenda og skilar nr yfir hvada skipun eigi ad framkvaema
void readCommand(string command){
    int cnumber = -1;
    for(unsigned int i = 0; i < (sizeof(commands)/sizeof(*commands)); i++){
        if(commands[i] == command)
            cnumber = i;
    };
    string nameToFind;
    switch(cnumber)
    {
        //find
        case 0:
            cin >> nameToFind;
            List.displayListByName(nameToFind);
            break;
        //add
        case 1:
            List.addPerson();
            break;
        //sort
        case 2:
            List.displayListAlpha();
            break;
        //display
        case 3:
            List.displayList();
            break;
        //quit
        case 4:
            loop = false;
            break;
        //help
        case 5:
            printHelp();
            break;
        default:
            cout << "Not a valid command." << endl;
            //statement;

    }

}

int main()
{
    loop = true;
    string c;//c fyrir command
    while(loop){
        cout << "Enter a command ('help' for list of commands): ";
        cin >> c;
        transform(c.begin(), c.end(), c.begin(), ::tolower);
        readCommand(c);
    }

    return 0;
}

