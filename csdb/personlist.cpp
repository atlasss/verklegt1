#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <windows.h>
#include "personlist.h"

HANDLE hCon;

enum Color { DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK, DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE };

void SetColor(Color c){
        if(hCon == NULL)
                hCon = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hCon, c);
}

personlist::personlist()
{
    NOInList = 0;
    saved = 0;
}

personlist::~personlist(){

}

void personlist::addPerson(){
    person newPerson;
    cin >> newPerson;
    newPerson.setId(NOInList);
    pList.push_back(newPerson); 
    NOInList++;
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
    int l1 = 9, l2 = 15;
    string fields[] = {"Name","Gender","Born","Died", "Known for"};
    SetColor(TEAL);
    printf("id:%d\n", pList[index].getId());
    for(int i = 0; i < sizeof(fields)/sizeof(*fields); i++){
        SetColor(DARKRED);
        cout << '+';
        for(int k = 0; k < l1; k++){
            cout << '-';
        }
        cout << '+';
        for(int k = 0; k < l2; k++){
            cout << '-';
        }
        cout << "+\n|";
        SetColor(DARKRED);
        cout << fields[i];
        SetColor(DARKRED);
        for(int k = fields[i].size(); k < l1; k++){
            cout << ' ';
        }
        cout << '|';

        switch(i){
            //name
            case 0:
                SetColor(RED);
                cout << pList[index].getName();
                SetColor(DARKRED);
                for(int k = pList[index].getName().size(); k < l2; k++){
                    cout << ' ';
                }
                cout << "|\n";
            break;
            //gender
            case 1:
                SetColor(RED);
                cout << pList[index].getGender();
                SetColor(DARKRED);
                for(int k = pList[index].getGender().size(); k < l2; k++){
                    cout << ' ';
                }
                cout << "|\n";
            break;
            //born
            case 2:
                SetColor(RED);
                cout << pList[index].getDateBirth();
                SetColor(DARKRED);
                for(int k = pList[index].getDateBirth().size(); k < l2; k++){
                    cout << ' ';
                }
                cout << "|\n";
            break;
            //died
            case 3:
                SetColor(RED);
                cout << pList[index].getDateDeath();
                SetColor(DARKRED);
                for(int k = pList[index].getDateDeath().size(); k < l2; k++){
                    cout << ' ';
                }
                cout << "|\n";
            break;
            //known for
            case 4:

                SetColor(DARKRED);
                for(int k = 0; k < l2; k++){
                   cout << ' ';
                }
                cout << "|\n";\
            break;

            default:
                cout << "Person was not found. " << endl;
            break;
        }

    }
    SetColor(DARKRED);
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
                cout << pList[k]  << endl;
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
        cout << pList[pos] << endl;
    }
}

void personlist::displayListByName(string n){

    bool personFound = false;
    for(int i = 0; i < NOInList; i++){

        if(pList[i].getName().find(n) != string::npos){
            cout << pList[i] << endl;
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
            cout << pList[i] << endl;
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
