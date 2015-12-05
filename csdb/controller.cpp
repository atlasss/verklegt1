#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include "controller.h"


string commands[] = {"search","add","display","quit","help","edit","delete"};
string subCommands[] = {"-e","-a","-d","-g","-i"};
string subTypeCommands[] = {"-p","-c"};
QString dbName = "csdb.sqlite";
controller::controller(){
    end = false;
    dbMain = QSqlDatabase::addDatabase("QSQLITE");
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
    string temp, temp2;
    int tid;
    person tempPerson;
    computer tempComputer;
    switch(cnumber)
    {
        //search
        case 0:

                cin >> temp;
                for(unsigned int i = 0; i < (sizeof(subTypeCommands)/sizeof(*subTypeCommands)); i++){
                        if(subTypeCommands[i] == temp){
                            subnumber = i;
                        }
                }
                cin >> temp2;
                switch(subnumber){
                    case 0:
                        listDisplay.displayListByName(temp2,listPerson.getFullList());
                        break;
                    case 1:
                        listComp.readFileName(temp2, dbMain);
                        listDisplay.displayListComputer(listComp.getFullList());
                        break;
                    default:
                        printf("'%s %s' is not a valid command.\n",command.c_str(), temp.c_str());
                        break;
                }

                listDisplay.displayListByName(temp, listPerson.getFullList());
            break;
        //add
        case 1:
            cin >> temp;
            for(unsigned int i = 0; i < (sizeof(subTypeCommands)/sizeof(*subTypeCommands)); i++){
                    if(subTypeCommands[i] == temp){
                        subnumber = i;
                    }
            }
            switch(subnumber){
                case 0:
                    tempPerson = listDisplay.fillFormPerson();
                    listPerson.addPerson(dbMain, tempPerson);
                break;
                case 1:
                    tempComputer = listDisplay.fillFormComputer();
                    listComp.addComputer(dbMain, tempComputer);
                break;
                default:
                    printf("'%s %s' is not a valid command.\n",command.c_str(), temp.c_str());
                break;
            }

            break;
        //display
        case 2:
            cin >> temp;
            for(unsigned int i = 0; i < (sizeof(subTypeCommands)/sizeof(*subTypeCommands)); i++){
                    if(subTypeCommands[i] == temp){
                        subnumber = i;
                    }
            }


            switch(subnumber){
            case 0:
                cin >> temp2;
                for(unsigned int i = 0; i < (sizeof(subCommands)/sizeof(*subCommands)); i++){
                    if(subCommands[i] == temp2)
                        subnumber = i;
                };
                switch(subnumber){
                    //full list in order of id
                    case 0:
                        listDisplay.displayList(listPerson.getFullList());
                        break;
                    //ascending
                    case 1:
                        listDisplay.displayListAlpha(listPerson.getFullList());
                        break;
                    //descending
                    case 2:
                        listDisplay.displayListAlphaDesc(listPerson.getFullList());
                        break;
                    //gender
                    case 3:
                        cin >> temp;
                        listDisplay.displayListByGender(temp, listPerson.getFullList());
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
                            listDisplay.displayById(tid, listPerson.getFullList());
                        break;
                    default:
                        printf("'%s %s %s' is not a valid command.\n",command.c_str(), temp.c_str(), temp2.c_str());
                        break;
                    }
            case 1:
                cin >> temp2;
                for(unsigned int i = 0; i < (sizeof(subCommands)/sizeof(*subCommands)); i++){
                    if(subCommands[i] == temp2)
                        subnumber = i;
                };
                switch(subnumber){
                    //full list in order of id
                    case 0:
                        listComp.readFile(dbMain);
                        listDisplay.displayListComputer(listComp.getFullList());
                        break;
                    //ascending
                    case 1:
                        listComp.readFileAlpha(dbMain);
                        listDisplay.displayListComputer(listComp.getFullList());
                        break;
                    //descending
                    case 2:
                        listComp.readFileAlphaDec(dbMain);
                        listDisplay.displayListComputer(listComp.getFullList());
                        break;
                    //gender
                    case 3:
                        printf("'%s %s %s' is not a valid command.\n",command.c_str(), temp.c_str(), temp2.c_str());
                        break;
                    //id
                    case 4:
                        cin >> tid;
                        if(cin.fail()) {
                                cout << "Requested id needs to be an integer." << endl;
                                cin.clear();
                                cin.ignore(256,'\n');

                            }
                        else{
                                listComp.readFileId(tid, dbMain);
                                listDisplay.displayListComputer(listComp.getFullList());
                            }
                            break;
                    default:
                        printf("'%s %s %s' is not a valid command.\n",command.c_str(), temp.c_str(), temp2.c_str());
                        break;
                    }
                break;

            default:
                printf("'%s %s %s' is not a valid command.\n",command.c_str(), temp.c_str(), temp2.c_str());
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
                if(listPerson.idExists(tid)){
                    tempPerson = listDisplay.fillFormPerson();
                    listPerson.editPerson(tid, tempPerson, dbMain);
                    listPerson.overwriteFile(dbMain);
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
                if(listPerson.idExists(tid)){
                    listPerson.deletePerson(tid, dbMain);
                    listPerson.overwriteFile(dbMain);
                }
                else
                    printf("No person with id '%d'.\n",tid);
            }
        break;
        default:
            printf("'%s' is not a valid command.\n",command.c_str());
            break;

    }

}

void controller::read(){
    end = false;
    string c;
    dbMain.setDatabaseName(dbName);
    listPerson.readFile(dbMain);
    listComp.readFile(dbMain);
    listDisplay.printWelcome();
    //listPerson.overwriteFile(dbMain);
    while(!end){
        cout << "Enter a command ('help' for list of commands): ";
        cin >> c;
        transform(c.begin(), c.end(), c.begin(), ::tolower);
        readCommand(c);
    }
}
QString controller::getdbName()const{
    return dbName;
}
