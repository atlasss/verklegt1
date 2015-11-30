#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include "personlist.h"

personlist::personlist()
{
    NOInList = 0;
    saved = 0;
}

personlist::~personlist(){

}

//baeta person vid listann
void personlist::addPerson(){
    person newPerson;
    cin >> newPerson;
    newPerson.setId(NOInList);
    pList.push_back(newPerson); 
    newPerson.getData();
    NOInList++;
}

void personlist::addPerson(person newPerson){
    if(newPerson.getId() == -1)
        newPerson.setId(NOInList);
    else
        saved++;
    pList.push_back(newPerson);
    NOInList++;
}

void personlist::editPerson(int i){
    if(i >= 0 && i < NOInList)
        cin >> pList[i];
    else
        printf("Person with id %d was not found",i);
}

int personlist::getListSize(){
    return NOInList;
}

void personlist::displayById(int i){
    if(i >= 0 && i < NOInList)
        cout << pList[i]  << endl;
    else
        printf("Person with id %d was not found",i);
}

//birta allan listann, radad eftir id
void personlist::displayList(){
    for(int i = 0; i < pList.size(); i++){
          cout << pList[i];
    }
}
//birta allan listann radad i stafrofsrod
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
//birta listann ut fra nafni
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

//birta listan ut fra kyni
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
