#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include "controller.h"

string commands[] = {"search","add","display","quit","help","edit","delete"};
string subCommands[] = {"-e","-a","-d","-g","-i"};
string fileName = "data.txt";
controller::controller(){
    end = false;
}

controller::~controller(){


}


void controller::readCommand(string command){
    int cnumber = -1;
    int subnumber = -1;
    for(unsigned int i = 0; i < (sizeof(commands)/sizeof(*commands)); i++){
        if(commands[i] == command)
            cnumber = i;
    };
    string temp;
    int tid;
    person tempPerson;
    switch(cnumber)
    {
        //find
        case 0:
            cin >> temp;
            listDisplay.displayListByName(temp, list.getFullList());
            break;
        //add
        case 1:
            tempPerson = listDisplay.fillForm();
            list.addPerson(tempPerson);
            list.writeToFile(fileName);
            break;
        //display
        case 2:
            cin >> temp;
            for(unsigned int i = 0; i < (sizeof(subCommands)/sizeof(*subCommands)); i++){
                if(subCommands[i] == temp)
                    subnumber = i;
            };

            switch(subnumber){
                //full list in order of id
                case 0:
                    listDisplay.displayList(list.getFullList());
                    break;
                //ascending
                case 1:
                    listDisplay.displayListAlpha(list.getFullList());
                    break;
                //descending
                case 2:
                    listDisplay.displayListAlphaDesc(list.getFullList());
                    break;
                //gender
                case 3:
                    cin >> temp;
                    listDisplay.displayListByGender(temp, list.getFullList());
                    break;
                //id
                case 4:
                    cin >> tid;
                    if(cin.fail()) {
                            cout << "Requested id needs to be an integer." << endl;
                            cin.clear();
                            cin.ignore(256,'\n');

                        }
                    else
                        listDisplay.displayById(tid, list.getFullList());
                    break;
                default:
                    cout << "'"<< command << ' ' << temp << "'" << " is not a valid command." << endl;
                    break;
            }

            break;
        //quit
        case 3:
            end = true;
            break;
        //help
        case 4:
            listDisplay.printHelp();
            break;
        //edit
        case 5:
            cin >> tid;
            if(cin.fail()) {
                    cout << "Requested id needs to be an integer." << endl;
                    cin.clear();
                    cin.ignore(256,'\n');

                }
            else{
                if(list.idExists(tid)){
                    tempPerson = listDisplay.fillForm();
                    list.editPerson(tid, tempPerson);
                    list.overwriteFile(fileName);
                }
                else
                    printf("No person with id '%d'.\n",tid);
            }
            break;
        //delete
        case 6:
            cin >> tid;
            if(cin.fail()) {
                    cout << "Requested id needs to be an integer." << endl;
                    cin.clear();
                    cin.ignore(256,'\n');

                }
            else{
                if(list.idExists(tid)){
                    list.deletePerson(tid);
                    list.overwriteFile(fileName);
                }
                else
                    printf("No person with id '%d'.\n",tid);
            }
        break;
        default:
            cout << "'"<< command << "'" << " is not a valid command." << endl;
            break;

    }

}

void controller::read(){
    end = false;
    string c;
    list.readFile(fileName);
    listDisplay.printWelcome();

    while(!end){
        cout << "Enter a command ('help' for list of commands): ";
        cin >> c;
        transform(c.begin(), c.end(), c.begin(), ::tolower);
        readCommand(c);
    }
}
string controller::getFileName()const{
    return fileName;
}
