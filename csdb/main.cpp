#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>

#include "person.h"
#include "personlist.h"


using namespace std;
string fileName = "data.txt";
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
            List.writeToFile(fileName);
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
            cout << "'"<< command << "'" << " is not a valid command." << endl;
            break;

    }

}

void printWelcome(){

    cout << "\nYb        dP 888888 88      dP\"\"b8  dP\"Yb  8b    d8 888888" << endl;
    cout << " Yb  db  dP  88__   88     dP   `\" dP   Yb 88b  d88 88__  "   <<endl;
    cout << "  YbdPYbdP   88\"\"   88  .o Yb      Yb   dP 88YbdP88 88\"\"  "<<endl;
    cout << "   YP  YP    888888 88ood8  YboodP  YbodP  88 YY 88 888888\n"    <<endl;

}

int main()
{
    string tname;
    int tbirth, tdeath, tgender, tid;

    ifstream data(fileName, ios::in);

    if (data.is_open()){
        while (data >> tid >> tname >> tgender >> tbirth >> tdeath)
        {
            List.addPerson(person(tid, tname, tgender, tbirth, tdeath));
        }
        data.close();
    }
    else{
        cout << strerror(errno) << endl;
    }
    printWelcome();
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

