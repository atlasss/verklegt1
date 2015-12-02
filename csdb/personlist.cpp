#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include "personlist.h"

personlist::personlist(){
    NOInList = 0;
    saved = 0;
}

personlist::~personlist(){

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

void personlist::deletePerson(int index){
    vector<person> newList;
    for(int i = 0; i < NOInList; i++){
        if(pList[i].getId() != index)
            newList.push_back(pList[i]);
    }
    NOInList--;
    pList.swap(newList);
}

vector<person> personlist::getFullList()const{
    return pList;
}
//laga thetta
void personlist::editPerson(int i, person editPerson){
    if(i >= 0 && i < NOInList){
        for(int k = 0; k < NOInList; k++){
            if(pList[k].getId() == i){
                pList[k].setName(editPerson.getName());
                pList[k].setDateBirth(editPerson.getDateBirth());
                pList[k].setDateDeath(editPerson.getDateDeath());
                pList[k].setGender(editPerson.getGender());
                pList[k].setKnownFor(editPerson.getKnownFor());
                break;
            }

        }
    }
    else
        printf("Person with id %d was not found\n",i);
}

int personlist::getListSize()const{
    return NOInList;
}

bool personlist::idExists(int i){
    for(int k = 0; k < NOInList; k++){
        if(pList[k].getId() == i)
            return true;
    }
    return false;
}

void personlist::readFile(string fileName){
    //temporary variables
    string tname, tgender, tbirth, tdeath, tknown;
    int tid;

    ifstream data(fileName.c_str(), ios::in);

    if (data.is_open()){

        while(data >> tid >> tname >> tgender >> tbirth >> tdeath >> tknown){
            addPerson(person(tid, tname, tgender, tbirth, tdeath, tknown));
        }


        data.close();
    }
    else{
        cout << strerror(errno) << endl;
    }
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
