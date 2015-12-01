#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include "personlist.h"

#ifdef WIN32
#include <windows.h>

HANDLE hCon;

enum Color { DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE };

void SetColor(Color c){
    if(hCon == NULL)
            hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon, c);
}
#else

#endif

personlist::personlist()
{
    NOInList = 0;
    saved = 0;
}

personlist::~personlist(){

}

void personlist::addPerson(){
    person newPerson = fillForm();
    newPerson.setId(NOInList);
    pList.push_back(newPerson); 
    NOInList++;
}
person personlist::fillForm(){
    bool valid = false, lastspace = false;
    string tname, tgender, tbirth, tdeath, tknown;
    char pos;
    person newPerson;

    cout << "Enter name(enter '-' to end input): "<< endl;
    do {
        cin.get(pos);
        if (isspace(pos) && !lastspace && tname.size() > 0){
            tname += ',';
            lastspace = true;
        }
        else if(pos == '-'){
            valid = true;
        }
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
            tknown += ',';
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

void personlist::addPerson(person newPerson){
    if(newPerson.getId() == -1)
        newPerson.setId(NOInList);
    else
        saved++;
    pList.push_back(newPerson);
    if(newPerson.getId() > NOInList){
        NOInList = newPerson.getId();
    }
    NOInList++;
}

void personlist::printSingle(int index){
    //colors in table
    Color c1 = RED, c2 = DARKYELLOW, c3 = YELLOW, c4 = TEAL;
    //width of table columns
    int l1 = 9, l2 = 15;
    string fields[] = {"Name","Gender","Born","Died", "Known for"};
    SetColor(c4);
    printf("id:%d\n", pList[index].getId());
    for(int i = 0; i < sizeof(fields)/sizeof(*fields); i++){
        SetColor(c2);
        cout << '+';
        for(int k = 0; k < l1; k++){
            cout << '-';
        }
        cout << '+';
        for(int k = 0; k < l2; k++){
            cout << '-';
        }
        cout << "+\n|";
        SetColor(c3);
        cout << fields[i];
        SetColor(c2);
        for(int k = fields[i].size(); k < l1; k++){
            cout << ' ';
        }
        cout << '|';

        switch(i){
            //name
            case 0:
                SetColor(c1);
                cout << pList[index].getName();
                SetColor(c2);
                for(int k = pList[index].getName().size(); k < l2; k++){
                    cout << ' ';
                }
                cout << "|\n";
            break;
            //gender
            case 1:
                SetColor(c1);
                cout << pList[index].getGender();
                SetColor(c2);
                for(int k = pList[index].getGender().size(); k < l2; k++){
                    cout << ' ';
                }
                cout << "|\n";
            break;
            //born
            case 2:
                SetColor(c1);
                cout << pList[index].getDateBirth();
                SetColor(c2);
                for(int k = pList[index].getDateBirth().size(); k < l2; k++){
                    cout << ' ';
                }
                cout << "|\n";
            break;
            //died
            case 3:
                SetColor(c1);
                cout << pList[index].getDateDeath();
                SetColor(c2);
                for(int k = pList[index].getDateDeath().size(); k < l2; k++){
                    cout << ' ';
                }
                cout << "|\n";
            break;
            //known for
            case 4:
                SetColor(c1);
                cout << pList[index].getKnownFor();
                SetColor(c2);
                for(int k = pList[index].getKnownFor().size(); k < l2; k++){
                   cout << ' ';
                }
                cout << "|\n";\
            break;

            default:
                cout << "Person was not found. " << endl;
            break;
        }

    }
    SetColor(c2);
    cout << '+';
    for(int k = 0; k < l1; k++){
        cout << '-';
    }
    cout << '+';
    for(int k = 0; k < l2; k++){
        cout << '-';
    }
    cout << "+\n";
    SetColor(WHITE);
}

void personlist::deletePerson(int index){
    vector<person> newList;
    for(int i = 0; i < NOInList; i++){
        if(pList[i].getId() != index)
            newList.push_back(pList[i]);
    }
    NOInList--;
    pList.swap(newList);
}

void personlist::editPerson(int i){
    if(i >= 0 && i < NOInList){
        for(int k = 0; k < NOInList; k++){
            if(pList[k].getId() == i)
                cin >> pList[k];
        }
    }
    else
        printf("Person with id %d was not found",i);
}

int personlist::getListSize(){
    return NOInList;
}

void personlist::displayById(int i){
    if(i >= 0 && i < NOInList)
        for(int k = 0; k < NOInList; k++){
            if(pList[k].getId() == i)
                printSingle(k);
        }
    else
        printf("Person with id %d was not found",i);
}

void personlist::displayList(){
    for(int i = 0; i < pList.size(); i++){
          printSingle(i);
    }
}

void personlist::displayListAlpha(){
    vector<string> names;
    vector<string> oNames;

    for(int i = 0; i < NOInList; i++){
        names.push_back(pList[i].getName());
        oNames.push_back(pList[i].getName());
    }

    sort(names.begin(), names.end());

    for(int i = 0; i < NOInList; i++){
        auto it=find(oNames.begin(), oNames.end(),names[i]);
        auto pos = distance(oNames.begin(), it);
        printSingle(pos);
    }
}

void personlist::displayListByName(string n){

    bool personFound = false;
    for(int i = 0; i < NOInList; i++){

        if(pList[i].getName().find(n) != string::npos){
            printSingle(i);
            personFound = true;
        }
    }
    if(!personFound)
        cout << "Person not found. " << endl;
}

void personlist::displayListByGender(string g){
    bool personFound = false;
    for(int i = 0; i < NOInList; i++){
        if(pList[i].getGender() == g){
            printSingle(i);
            personFound = true;
        }
    }
    if(!personFound)
        cout << "Person not found. " << endl;
}


void personlist::printWelcome(){
    SetColor(DARKRED);
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


void personlist::overwriteFile(string fileName){
    ofstream data (fileName);
    saved = 0;
    for(int i = saved; i < NOInList; i++){
        data << pList[i].getData() << endl;
        saved++;
    }
    data.close();
}

void personlist::writeToFile(string fileName){
    ofstream data (fileName,ios::app);
    for(int i = saved; i < NOInList; i++){
        data << pList[i].getData() << endl;
        saved++;
    }
    data.close();
}
