#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "personlist.h"

personlist::personlist()
{
    NOInList = 0;
}

personlist::~personlist(){

}

//baeta person vid listann
void personlist::addPerson(){
    person newPerson;
    cin >> newPerson;
    newPerson.setId(NOInList);
    pList.push_back(newPerson);
    NOInList++;
}

void personlist::addPerson(person newPerson){
    newPerson.setId(NOInList);
    pList.push_back(newPerson);
    NOInList++;
}


//birta allan listann, radad eftir id
void personlist::displayList(){
    for(int i = 0; i < pList.size(); i++){
          cout << pList[i];
    }

}
//birta allan listann radad i stafrofsrod
void personlist::displayListAlpha(){
    vector<int> order;
    vector<string> names;

    for(int i = 0; i < NOInList; i++){
        order.push_back(i);
        names.push_back(pList[i].getName());
    }

    sort(names.begin(), names.end());

    for(int i = 0; i < NOInList; i++){
        cout << names[i] << endl;
    }
}
//birta listann ut fra nafni
void personlist::displayListByName(string n){
    bool personFound = false;
    for(int i = 0; i < NOInList; i++){
        if(pList[i].getName() == n){
            cout << pList[i];
            personFound = true;
        }
    }
    if(!personFound)
        cout << "Person not found. " << endl;
}

//birta listan ut fra kyni
void personlist::displayListByGender(int g){
    bool personFound = false;
    for(int i = 0; i < NOInList; i++){
        if(pList[i].getGender() == g){
            cout << pList[i];
            personFound = true;
        }
    }
    if(!personFound)
        cout << "Person not found. " << endl;
}
