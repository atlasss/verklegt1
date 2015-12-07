#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include "controller.h"


string commands[] = {"search","add","display","quit","help","edit","delete","rel"};
string subCommands[] = {"-e","-a","-d","-g","-i","-m"};
string subTypeCommands[] = {"-p","-c"};
string relCommands[] = {"-d","-n"};
QString dbName = "csdb.sqlite";







controller::controller(){
    end = false;
    dbMain = QSqlDatabase::addDatabase("QSQLITE");
}

controller::~controller(){


}

bool controller::validateAgeString(string a){
    bool midFound = false;

    for(unsigned int i = 0; i < a.size(); i++){
        if(a[i] == 47){
            if(!midFound)
                midFound = true;
            else
                return false;
        }
        else if(a[i] < 48 || a[i] > 57){
            return false;
        }
    }

    return midFound;
}


void controller::readCommand(string command){
    int cnumber = -1;
    int subnumber = -1;
    for(unsigned int i = 0; i < (sizeof(commands)/sizeof(*commands)); i++){
        if(commands[i] == command)
            cnumber = i;
    };
    string temp, temp2;
    int tid, tid2;
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
                        listPerson.readFileName(temp2,dbMain);
                        listDisplay.displayListPerson(listPerson.getFullList());
                        break;
                    case 1:
                        listComp.readFileName(temp2, dbMain);
                        listDisplay.displayListComputer(listComp.getFullList());
                        break;
                    default:
                        printf("'%s %s' is not a valid command.\n",command.c_str(), temp.c_str());
                        break;
                }
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
                        listPerson.readFile(dbMain);
                        listDisplay.displayListPerson(listPerson.getFullList());
                        break;
                    //ascending
                    case 1:
                        listPerson.readFileAlpha(dbMain);
                        listDisplay.displayListPerson(listPerson.getFullList());
                        break;
                    //descending
                    case 2:
                        listPerson.readFileAlphaDesc(dbMain);
                        listDisplay.displayListPerson(listPerson.getFullList());
                        break;
                    //gender
                    case 3:
                        cin >> temp;
                        listPerson.readFileGender(temp,dbMain);
                        listDisplay.displayListPerson(listPerson.getFullList());
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
                            listPerson.readFileId(tid,dbMain);
                            listDisplay.displayListPerson(listPerson.getFullList());

                        }
                        break;
                    //age
                    case 5:
                        cin >> temp;
                        if(!validateAgeString(temp)){
                            listPerson.readFileAge(temp,dbMain);
                            listDisplay.displayListPerson(listPerson.getFullList());
                        }
                        else{
                            printf("Incorrect format. \n");
                        }
                        break;
                    default:
                        printf("'%s %s %s' is not a valid command.\n",command.c_str(), temp.c_str(), temp2.c_str());
                        break;
                    }
                break;
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
                        listDisplay.printSecret();
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
                    //age
                    case 5:
                        cin >> temp;
                        if(!validateAgeString(temp)){
                            listComp.readFileAge(temp,dbMain);
                            listDisplay.displayListComputer(listComp.getFullList());
                        }
                        else{
                            printf("Incorrect format. \n");
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
                }
                else
                    printf("No person with id '%d'.\n",tid);
            }
        break;
        //rel
        case 7:
            cin >> temp;
            for(unsigned int i = 0; i < (sizeof(subTypeCommands)/sizeof(*subTypeCommands)); i++){
                    if(subTypeCommands[i] == temp){
                        subnumber = i;
                    }
            }
            for(unsigned int i = 0; i < (sizeof(relCommands)/sizeof(*relCommands)); i++){
                    if(relCommands[i] == temp){
                        subnumber = i+(sizeof(subTypeCommands)/sizeof(*subTypeCommands));
                    }
            }
            cin >> tid;
            if(cin.fail()) {
                    cout << "Id needs to be an integer." << endl;
                    cin.clear();
                    cin.ignore(256,'\n');

                }
            else{
                switch(subnumber){
                    //p
                    case 0:
                        listDisplay.displayRelPerson(listPerson.getRel(tid,dbMain));
                        break;
                    //c
                    case 1:
                        listDisplay.displayRelComputer(listComp.getRel(tid,dbMain));
                        break;
                    //d
                    case 2:
                        cin >> tid2;
                        if(cin.fail()) {
                                cout << "Id needs to be an integer." << endl;
                                cin.clear();
                                cin.ignore(256,'\n');

                            }
                        else
                            listPerson.removeRel(tid, tid2, dbMain);
                        break;
                    //n
                    case 3:
                        cin >> tid2;
                        if(cin.fail()) {
                                cout << "Id needs to be an integer." << endl;
                                cin.clear();
                                cin.ignore(256,'\n');

                            }
                        else
                            listPerson.addRel(tid, tid2, dbMain);
                        break;
                    default:
                        printf("'%s %s' is not a valid command.\n",command.c_str(), temp.c_str());
                        break;
                }
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
    //listPerson.addRel(5,5,dbMain);

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
