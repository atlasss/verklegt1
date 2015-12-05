#include "display.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include "personlist.h"
#include <sstream>
#include <windows.h>

HANDLE hCon;

enum Color { DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE };

void SetColor(Color c){
    if(hCon == NULL)
            hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon, c);
}

display::display(){

}

display::~display(){

}

void display::printSingle(person personToPrint){
    //colors in table
    Color c1 = RED, c2 = DARKYELLOW, c3 = YELLOW, c4 = TEAL;
    //width of the columns in the table
    unsigned int l1 = 9, l2 = 15;
    //overwrites default value for column 2 if the length fields 'Name' or 'Known for' exceed the original size
    //length of column 1 always stays the same
    if(personToPrint.getKnownFor().size() > l2)
        l2 = personToPrint.getKnownFor().size();
    if(personToPrint.getName().size() > l2)
        l2 = personToPrint.getName().size();

    string fields[] = {"Name","Gender","Born","Died", "Known for"};
    SetColor(c4);
    printf("id:%d \tage:%d\n", personToPrint.getId(),int(personToPrint.getAge()/365.25));
    for(unsigned int i = 0; i < sizeof(fields)/sizeof(*fields); i++){
        SetColor(c2);
        cout << '+';
        for(unsigned int k = 0; k < l1; k++){
            cout << '-';
        }
        cout << '+';
        for(unsigned int k = 0; k < l2; k++){
            cout << '-';
        }
        cout << "+\n|";
        SetColor(c3);
        cout << fields[i];
        SetColor(c2);
        for(auto k = fields[i].size(); k < l1; k++){
            cout << ' ';
        }
        cout << '|';

        switch(i){
            //name
            case 0:
                SetColor(c1);
                cout << personToPrint.getName();
                SetColor(c2);
                for(auto k = personToPrint.getName().size(); k < l2; k++){
                    cout << ' ';
                }
                cout << "|\n";
            break;
            //gender
            case 1:
                SetColor(c1);
                cout << personToPrint.getGender();
                SetColor(c2);
                for(auto k = personToPrint.getGender().size(); k < l2; k++){
                    cout << ' ';
                }
                cout << "|\n";
            break;
            //born
            case 2:
                SetColor(c1);
                cout << personToPrint.getDateBirth();
                SetColor(c2);
                for(auto k = personToPrint.getDateBirth().size(); k < l2; k++){
                    cout << ' ';
                }
                cout << "|\n";
            break;
            //died
            case 3:
                SetColor(c1);
                cout << personToPrint.getDateDeath();
                SetColor(c2);
                for(auto k = personToPrint.getDateDeath().size(); k < l2; k++){
                    cout << ' ';
                }
                cout << "|\n";
            break;
            //known for
            case 4:
                SetColor(c1);
                cout << personToPrint.getKnownFor();
                SetColor(c2);
                for(auto k = personToPrint.getKnownFor().size(); k < l2; k++){
                   cout << ' ';
                }
                cout << "|\n";\
            break;

            default:
                cout << "Error. " << endl;
            break;
        }

    }
    SetColor(c2);
    cout << '+';
    for(unsigned int k = 0; k < l1; k++){
        cout << '-';
    }
    cout << '+';
    for(unsigned int k = 0; k < l2; k++){
        cout << '-';
    }
    cout << "+\n";
    SetColor(WHITE);
}

person display::fillFormPerson(){
    bool valid = false, lastspace = false;
    string tname, tgender, tbirth, tdeath, tknown;
    char pos;
    person newPerson;

    cout << "Enter name(enter '-' to end input): "<< endl;
    //goes through each character in user input
    do {
        cin.get(pos);
        if (isspace(pos) && !lastspace && tname.size() > 0){
            tname += ' ';
            lastspace = true;
        }
        //'-' to end user input
        else if(pos == '-'){
            valid = true;
        }
        //if the character is neither '-' or ' ' it is appended to the name string
        else if(!isspace(pos)){
            tname += pos;
            lastspace = false;
        }

    } while (!valid);

    valid = false;
    lastspace = false;
    newPerson.setName(tname);

    cout << "Enter gender(Male/Female): " << endl;
    do{
        cin >> tgender;
        //changes user input so it isn't case sensitive
        transform(tgender.begin(), tgender.end(), tgender.begin(), ::tolower);
        if(tgender[0] == 'f')
            tgender[0] = 'F';
        else if(tgender[0] == 'm')
            tgender[0] = 'M';
        newPerson.setGender(tgender);
        valid = newPerson.isGenderValid();
        if(!valid)
            cout << "The gender you have entered is not valid. " << endl;
    }while(!valid);

    valid = false;

    cout << "Enter date of birth(dd/mm/yyyy): " << endl;
    do{
        cin >> tbirth;
        newPerson.setDateBirth(tbirth);
        valid = newPerson.isDateBirthValid();
        if(!valid)
            cout << "The date you have entered is not valid." << endl;
    }while(!valid);

    valid = false;

    cout << "Enter date of death(dd/mm/yyyy) or -1 if the person is still alive:" << endl;
    do{
        cin >> tdeath;
        newPerson.setDateDeath(tdeath);
        valid = newPerson.isDateDeathValid();
        if(!valid)
            cout << "The date you have entered is not valid." << endl;
    }while(!valid);

    valid = false;

    cout << "Enter what the person was known for(enter '-' to end input):" << endl;
    do {
        cin.get(pos);
        if (isspace(pos) && !lastspace && tknown.size() > 0){
            tknown += ' ';
            lastspace = true;
        }
        else if(pos == '-'){
            valid = true;
        }
        else if(!isspace(pos)){
            tknown += pos;
            lastspace = false;
        }

    }while (!valid);

    newPerson.setKnownFor(tknown);

    return newPerson;
}

void display::printSingleComputer(computer computerToPrint){
    //colors in table
    Color c1 = RED, c2 = DARKYELLOW, c3 = YELLOW, c4 = TEAL;
    //width of the columns in the table
    unsigned int l1 = 11, l2 = 15;
    //overwrites default value for column 2 if the length fields 'Name' or 'Known for' exceed the original size
    //length of column 1 always stays the same
    if(computerToPrint.getType().size() > l2)
        l2 = computerToPrint.getType().size();
    if(computerToPrint.getName().size() > l2)
        l2 = computerToPrint.getName().size();

    string fields[] = {"Name","Year built","Type","Built"};
    SetColor(c4);
    printf("id:%d\n", computerToPrint.getId());
    for(unsigned int i = 0; i < sizeof(fields)/sizeof(*fields); i++){
        SetColor(c2);
        cout << '+';
        for(unsigned int k = 0; k < l1; k++){
            cout << '-';
        }
        cout << '+';
        for(unsigned int k = 0; k < l2; k++){
            cout << '-';
        }
        cout << "+\n|";
        SetColor(c3);
        cout << fields[i];
        SetColor(c2);
        for(auto k = fields[i].size(); k < l1; k++){
            cout << ' ';
        }
        cout << '|';

        switch(i){
            //name
            case 0:
                SetColor(c1);
                cout << computerToPrint.getName();
                SetColor(c2);
                for(auto k = computerToPrint.getName().size(); k < l2; k++){
                    cout << ' ';
                }
                cout << "|\n";
            break;
            //gender
            case 1:
                if(!computerToPrint.wasBuilt()){
                    SetColor(c1);
                    cout << computerToPrint.getYearBuilt();
                    SetColor(c2);
                    for(auto k = 4; k < l2; k++){
                        cout << ' ';
                    }
                    cout << "|\n";
                }
                else{
                    SetColor(c1);
                    cout << "N/A";
                    SetColor(c2);
                    for(auto k = 3; k < l2; k++){
                        cout << ' ';
                    }
                    cout << "|\n";
                }
            break;
            //born
            case 2:
                SetColor(c1);
                cout << computerToPrint.getType();
                SetColor(c2);
                for(auto k = computerToPrint.getType().size(); k < l2; k++){
                    cout << ' ';
                }
                cout << "|\n";
            break;
            //died
            case 3:
                if(!computerToPrint.wasBuilt()){
                    SetColor(c1);
                    cout << "Yes";
                    SetColor(c2);
                    for(auto k = 3 ; k < l2; k++){
                        cout << ' ';
                    }
                    cout << "|\n";
                }
                else{
                    SetColor(c1);
                    cout << "No";
                    SetColor(c2);
                    for(auto k = 2; k < l2; k++){
                        cout << ' ';
                    }
                    cout << "|\n";
                }
            break;

            default:
                cout << "Error. " << endl;
            break;
        }

    }
    SetColor(c2);
    cout << '+';
    for(unsigned int k = 0; k < l1; k++){
        cout << '-';
    }
    cout << '+';
    for(unsigned int k = 0; k < l2; k++){
        cout << '-';
    }
    cout << "+\n";
    SetColor(WHITE);
}

computer display::fillFormComputer(){
    bool valid = false, lastspace = false;
    string tname;
    int tyearBuilt, ttype;

    computer newComputer;
    char pos;
    cout << "Enter name(enter '-' to end input):" << endl;
    do{
        cin.get(pos);
        if (isspace(pos) && !lastspace && tname.size() > 0){
            tname += ' ';
            lastspace = true;
        }
        //'-' to end user input
        else if(pos == '-'){
            valid = true;
        }
        //if the character is neither '-' or ' ' it is appended to the name string
        else if(!isspace(pos)){
            tname += pos;
            lastspace = false;
        }

    }while(!valid);
    newComputer.setName(tname);
    valid = false;
    cout << "Enter year built (between 1600 and 2015):" << endl;
    do{
        cin >> tyearBuilt;
        if(cin.fail()) {
                cout << "Year built needs to be an integer." << endl;
                cin.clear();
                cin.ignore(256,'\n');

            }
        else{
            newComputer.setYearBuilt(tyearBuilt);
            valid = newComputer.isYearBuiltValid();
            if(!valid)
                cout << "The year you have entered is not valid. " << endl;
        }
    }while(!valid);
    valid = false;
    cout << "Enter type 1)'transistor', 2)'electromechanical', 3)'electronic', 4)'electric':" << endl;
    do{
        cin >> ttype;
        if(cin.fail()) {
                cout << "Type needs to be an integer." << endl;
                cin.clear();
                cin.ignore(256,'\n');

            }
        else{
            newComputer.setYearBuilt(tyearBuilt);
            valid = newComputer.isTypeValid(ttype-1);
            if(!valid)
                cout << "The type you have entered is not valid. " << endl;
        }

    }while(!valid);
    newComputer.setType(ttype);

    return newComputer;
}

void display::displayById(unsigned int i, vector<person> pList){
    if(i >= 0 && i < pList.size())
        for(int k = 0; k < pList.size(); k++){
            if(pList[k].getId() == i)
                printSingle(pList[k]);
        }
    else
        printf("Person with id %d was not found\n",i);
}

void display::displayList(vector<person> pList){
    for(int i = 0; i < pList.size(); i++){
          printSingle(pList[i]);
    }
}

void display::displayListComputer(vector<computer> cList){
    for(int i = 0; i < cList.size(); i++){
          printSingleComputer(cList[i]);
    }
}

void display::displayListAlpha(vector<person> pList){
    vector<string> names;
    vector<string> oNames;

    for(int i = 0; i < pList.size(); i++){
        names.push_back(pList[i].getName());
        oNames.push_back(pList[i].getName());
    }

    sort(names.begin(), names.end());

    for(int i = 0; i < pList.size(); i++){
        auto it=find(oNames.begin(), oNames.end(),names[i]);
        auto pos = distance(oNames.begin(), it);
        printSingle(pList[pos]);
    }
}

void display::displayListAlphaDesc(vector<person> pList){
    vector<string> names;
    vector<string> oNames;

    for(int i = 0; i < pList.size(); i++){
        names.push_back(pList[i].getName());
        oNames.push_back(pList[i].getName());
    }

    sort(names.begin(), names.end());

    for(auto i = pList.size()-1; i >= 0; i--){
        auto it = find(oNames.begin(), oNames.end(),names[i]);
        auto pos = distance(oNames.begin(), it);
        printSingle(pList[pos]);
    }
}

void display::displayListByName(string n, vector<person> pList){

    bool personFound = false;
    for(int i = 0; i < pList.size(); i++){

        if(pList[i].getName().find(n) != string::npos){
            printSingle(pList[i]);
            personFound = true;
        }
    }
    if(!personFound)
        cout << "Person not found. " << endl;
}

void display::displayListByGender(string g, vector<person> pList){

    transform(g.begin(), g.end(), g.begin(), ::tolower);

    if(g[0] == 'f')
        g[0] = 'F';
    else if(g[0] == 'm')
        g[0] = 'M';

    if(g == "Male" || g == "Female"){
        bool personFound = false;
        for(auto i = 0; i < pList.size(); i++){
            if(pList[i].getGender() == g){
                printSingle(pList[i]);
                personFound = true;
            }
        }
        if(!personFound)
            cout << "Person not found. " << endl;
    }
    else{
        cout << "Requested gender needs to be either \"Male\" or \"Female\"" << endl;
    }
}

void display::printWelcome(){
    SetColor(RED);
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
    cout << "                               " << endl;

    SetColor(WHITE);
}

void display::printHelp(){

    string commands[] = {"Search","Add","Display","Quit","Help","Edit","Delete"};
    string commandHelp[] = {"\t...(I.E. \"Search Bob\")","\t...(Type 'Add' to add a new person)","\t...Can display the list in the following ways:",
                            "\t...(Quits program)","\t...(List of commands)","\t...(Edit information by entering 'Id' I.E. \"Edit 1\")",
                            "\t...(Delete a person by entering 'Id' I.E. \"Delete 1\")"};
    string subCommands[] = {"-e","-a","-d","-g","-i"};
    string subCommandsHelp[] = {"...Full list ordered by id(\"Display -e\")"
                                ,"...Full list, in ascending order(\"Display -a\")",
                                "...Full list, in descending order(\"Display -d\")",
                                "...Only persons in list belonging to \n\t\t   requested gender(\"Display -g Male\")",
                                "...Single person in list, that matches\n\t\t   a specific Id(\"Display -i 2\")"};

    cout << "\n";
    for(unsigned int i = 0; i < (sizeof(commandHelp)/sizeof(*commandHelp)); i++){
        SetColor(GREEN);
        cout << commands[i];
        SetColor(WHITE);
        cout << commandHelp[i] << endl;
        if(i == 2){
            for(unsigned int k = 0; k < (sizeof(subCommands)/sizeof(*subCommands)); k++){
                SetColor(TEAL);
                cout << "\t" << subCommands[k];
                SetColor(WHITE);
                cout << "\t" << subCommandsHelp[k] << endl;
            }
        }
    }
    cout << "\n";
}


