#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include "controller.h"


string commands[] = {"search","add","display","quit","help","edit","delete","rel"};
string subCommands[] = {"-e","-a","-d","-g","-w"};
string subTypeCommands[] = {"-p","-c"};
string relCommands[] = {"-r","-n"};
string searchCommands[] = {"-i","-m"};

controller::controller(){
    end = false;
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
                    subnumber = -1;
                    for(unsigned int i = 0; i < (sizeof(searchCommands)/sizeof(*searchCommands)); i++){
                            if(searchCommands[i] == temp2){
                                subnumber = i;
                            }
                    }
                    switch(subnumber){
                        //id
                        case 0:
                            cin >> tid;
                            if(cin.fail()) {
                                cout << "Requested id needs to be an integer." << endl;
                                cin.clear();
                                cin.ignore(256,'\n');

                                }
                            else{
                                listPerson.readFileId(tid,db.readDb());
                                listDisplay.displayListPerson(listPerson.getFullList());

                            }
                        break;

                        //age
                        case 1:
                            cin >> temp;
                            if(!validateAgeString(temp)){
                                listPerson.readFileAge(temp,db.readDb());
                                listDisplay.displayListPerson(listPerson.getFullList());
                            }
                            else{
                                printf("Incorrect format. \n");
                            }
                        break;
                        //name
                        default:
                            listPerson.readFileName(temp2,db.readDb());
                            listDisplay.displayListPerson(listPerson.getFullList());
                        break;

                    }

                    break;
                case 1:
                    subnumber = -1;
                    for(unsigned int i = 0; i < (sizeof(searchCommands)/sizeof(*searchCommands)); i++){
                            if(searchCommands[i] == temp2){
                                subnumber = i;
                            }
                    }
                    switch(subnumber){
                        //id
                        case 0:
                            cin >> tid;
                            if(cin.fail()) {
                                cout << "Requested id needs to be an integer." << endl;
                                cin.clear();
                                cin.ignore(256,'\n');

                                }
                            else{
                                listComp.readFileId(tid, db.readDb());
                                listDisplay.displayListComputer(listComp.getFullList());
                                }
                        break;
                        //age
                        case 1:
                            cin >> temp;
                            if(!validateAgeString(temp)){
                                listComp.readFileAge(temp,db.readDb());
                                listDisplay.displayListComputer(listComp.getFullList());
                            }
                            else{
                                printf("Incorrect format. \n");
                            }
                        break;
                        //name
                        default:
                            listComp.readFileName(temp2, db.readDb());
                            listDisplay.displayListComputer(listComp.getFullList());
                        break;

                    }
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
                    listPerson.addPerson(db.readDb(), tempPerson);
                break;
                case 1:
                    tempComputer = listDisplay.fillFormComputer();
                    listComp.addComputer(db.readDb(), tempComputer);
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
                        listPerson.readFile(db.readDb());
                        listDisplay.displayListPerson(listPerson.getFullList());
                        break;
                    //ascending
                    case 1:
                        listPerson.readFileAlpha(db.readDb());
                        listDisplay.displayListPerson(listPerson.getFullList());
                        break;
                    //descending
                    case 2:
                        listPerson.readFileAlphaDesc(db.readDb());
                        listDisplay.displayListPerson(listPerson.getFullList());
                        break;
                    //gender
                    case 3:
                        cin >> temp;
                        listPerson.readFileGender(temp,db.readDb());
                        listDisplay.displayListPerson(listPerson.getFullList());
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
                        listComp.readFile(db.readDb());
                        listDisplay.displayListComputer(listComp.getFullList());
                        break;
                    //ascending
                    case 1:
                        listComp.readFileAlpha(db.readDb());
                        listDisplay.displayListComputer(listComp.getFullList());
                        break;
                    //descending
                    case 2:
                        listComp.readFileAlphaDec(db.readDb());
                        listDisplay.displayListComputer(listComp.getFullList());
                        break;
                    //gender
                    case 3:
                        listDisplay.printSecret();
                        break;
                    //weight
                    case 4:
                        listComp.readFileWeight(db.readDb());
                        listDisplay.displayListComputer(listComp.getFullList());
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
            cin >> temp;
            for(unsigned int i = 0; i < (sizeof(subTypeCommands)/sizeof(*subTypeCommands)); i++){
                    if(subTypeCommands[i] == temp){
                        subnumber = i;
                    }
            }
            switch(subnumber){
                case 0:
                    cin >> tid;
                    if(cin.fail()) {
                        cout << "Requested id needs to be an integer." << endl;
                        cin.clear();
                        cin.ignore(256,'\n');
                        }
                    else{
                        listPerson.readFile(db.readDb());
                        if(listPerson.idExists(tid)){
                            tempPerson = listDisplay.fillFormPerson();
                            listPerson.editPerson(tid, tempPerson, db.readDb());
                        }
                    }
                break;
                case 1:
                    cin >> tid;
                    if(cin.fail()) {
                        cout << "Requested id needs to be an integer." << endl;
                        cin.clear();
                        cin.ignore(256,'\n');
                        }
                    else{
                        listComp.readFile(db.readDb());
                        if(listComp.idExists(tid)){
                            tempComputer = listDisplay.fillFormComputer();
                            listComp.editComputer(tid, tempComputer, db.readDb());
                        }
                        else
                            printf("Computer with id %d not found. ",tid);
                    }
                break;
                default:
                    printf("'%s %s' is not a valid command.\n",command.c_str(), temp.c_str());
                break;
            }
        break;

        //delete
        case 6:
            cin >> temp;
            for(unsigned int i = 0; i < (sizeof(subTypeCommands)/sizeof(*subTypeCommands)); i++){
                    if(subTypeCommands[i] == temp){
                        subnumber = i;
                    }
            }
            switch(subnumber){
                case 0:
                    cin >> tid;
                    if(cin.fail()) {
                        cout << "Requested id needs to be an integer." << endl;
                        cin.clear();
                        cin.ignore(256,'\n');
                        }
                    else
                        listPerson.deletePerson(tid, db.readDb());

                break;
                case 1:
                    cin >> tid;
                    if(cin.fail()) {
                        cout << "Requested id needs to be an integer." << endl;
                        cin.clear();
                        cin.ignore(256,'\n');
                        }
                    else
                        listComp.deleteComputer(tid, db.readDb());
                break;
                default:
                    printf("'%s %s' is not a valid command.\n",command.c_str(), temp.c_str());
                break;
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
                        listDisplay.displayRelPerson(listPerson.getRel(tid,db.readDb()));
                        break;
                    //c
                    case 1:
                        listDisplay.displayRelComputer(listComp.getRel(tid,db.readDb()));
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
                            listPerson.removeRel(tid, tid2, db.readDb());
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
                            listPerson.addRel(tid, tid2, db.readDb());
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
    db.open();
    listPerson.readFile(db.readDb());
    listComp.readFile(db.readDb());
    listDisplay.printWelcome();
    while(!end){
        cout << "Enter a command ('help' for list of commands): ";
        cin >> c;
        transform(c.begin(), c.end(), c.begin(), ::tolower);
        readCommand(c);
    }

}
