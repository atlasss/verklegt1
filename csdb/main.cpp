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
string commands[] = {"find","add","sort","display","quit","help","edit"};
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
    int tid;
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
        //edit
        case 6:
            cin >> tid;
            List.editPerson(tid);
            List.overwriteFile(fileName);
            break;
        default:
            cout << "'"<< command << "'" << " is not a valid command." << endl;
            break;

    }

}

void printWelcome(){
    cout << "                  ...::              ." << endl;
    cout << "               .:::   :             .:::." << endl;
    cout << "            .:':      ::::::::::::  :::::::." << endl;
    cout << "          .:''        '  ::::::::  ::::::::::." << endl;
    cout << "        .::'  .:.     ::::::::::: .::::::::::::." << endl;
    cout << "      .:   .::::.     :::::::::  :::::::::::::::" << endl;
    cout << "      :'   ::::::::    :::::::::.:::::::::::::::::" << endl;
    cout << "     :''  ::::::::::.  ::::::::::::::::::::::::'''" << endl;
    cout << "    .:   :::::::::::::  :::::::::::::::::::::::." << endl;
    cout << "    :'' :::::::::   '::. '''''''::::::::::::::::" << endl;
    cout << "   ''''.::::::::     .:'         ::::::::::::::::" << endl;
    cout << "       ''':'''':::...:            ::''' :::::::::" << endl;
    cout << "          :..........'            :.    :::::::::" << endl;
    cout << "                 ....:            :     :::::::::" << endl;
    cout << "         ....::::::::::.         ::..  .'''::::::" << endl;
    cout << "    ....::::::::::::::::: .....:::::::.::::..'''" << endl;
    cout << "    '::::::::::::::::::: . :::::::::::::::::::::..." << endl;
    cout << "     :::::::::::::::'::  '.::::::::::::::::::::::::" << endl;
    cout << "      ::::::::''::'    .: ::::::::::::::::::::::::" << endl;
    cout << "       '::::'   ''     :'  ::::::::::::  ':::::::" << endl;
    cout << "        ':'           :'   :::::::::::::.  ':::'" << endl;
    cout << "                     ::   :::::::::::::'     '" << endl;
    cout << "                    .'    ::::::::'''." << endl;
    cout << "                   .'                :." << endl;
    cout << "                   ''::..::::::..::'''" << endl;
    cout << "                               " << endl;

}

int main()
{
    string tname, tgender, tbirth, tdeath;
    int tid;

    ifstream data(fileName, ios::in);

    if (data.is_open()){

        while(data >> tid >> tname >> tgender >> tbirth >> tdeath ){
            List.addPerson(person(tid, tname, tgender, tbirth, tdeath));
        }


        data.close();
    }
    else{
        cout << strerror(errno) << endl;
    }
    printWelcome();
    loop = true;
    string c;
    while(loop){
        cout << "Enter a command ('help' for list of commands): ";
        cin >> c;
        transform(c.begin(), c.end(), c.begin(), ::tolower);
        readCommand(c);
    }

    return 0;
}

