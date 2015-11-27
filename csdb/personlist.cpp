#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "personlist.h"

personlist::personlist()
{
    int NOInList = 0;

}

personlist::~personlist(){

}

//baeta person vid listann
void personlist::addPerson(string lname, int lbirthy, int ldeathy, int lgender){
    pList.push_back(new person(NOInList, lname, lbirthy, ldeathy, lgender));
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
    for(int i = 0; i < NOInList; i++){
        if(pList[i].getName == n)
            cout << pList[i];
    }
}

//birta listan ut fra kyni
void personlist::displayListByGender(int g){
    for(int i = 0; i < NOInList; i++){
        if(pList[i].getName == n)
            cout << pList[i];
    }
}
