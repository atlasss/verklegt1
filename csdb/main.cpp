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
string commands[] = {"search","add","sort","display","quit","help","edit", "gender","delete"};
string commandHelp[] = {"Search\t(I.E. \"Search Bob Kendrick\")","Add\t(Type 'Add' to add a new person)","Sort\t(Sorts in ascending order)","Display\t(Displays full list)","Quit\t(Quits program)","Help\t(List of commands)","Edit\t(Edit information by entering 'Id' I.E. \"Edit 1\")","Gender\t(Sorts by gender I.E. \"Gender Female\")","Delete\t(Delete a person by entering 'Id' I.E. \"Delete 1\")"};
personlist List;
bool loop;

//prints list of commands
void printHelp(){
    for(unsigned int i = 0; i < (sizeof(commandHelp)/sizeof(*commandHelp)); i++){
        cout << commandHelp[i] << endl;
    }
}
//takes in string command and executes appropriate command
void readCommand(string command){
    int cnumber = -1;
    for(unsigned int i = 0; i < (sizeof(commands)/sizeof(*commands)); i++){
        if(commands[i] == command)
            cnumber = i;
    };
    string temp;
    int tid;
    switch(cnumber)
    {
        //find
        case 0:
            cin >> temp;
            List.displayListByName(temp);
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
        //gender
        case 7:
            cin >> temp;
            List.displayListByGender(temp);
            break;
        //delete
        case 8:
            cin >> tid;
            List.deletePerson(tid);
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
    //temporary variables
    string tname, tgender, tbirth, tdeath;
    int tid;

    ifstream data(fileName.c_str(), ios::in);

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

