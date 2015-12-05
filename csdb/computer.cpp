#include "computer.h"

computer::computer(){
    id = -1;
    name = "missing";
    yearBuilt = -1;
    type = "missing";
    built = false;
}

computer::computer(string lname, int lyearBuilt, string ltype, bool lbuilt){
    id = -1;
    name = lname;
    yearBuilt = lyearBuilt;
    type = ltype;
    built = lbuilt;
}

computer::computer(int lid, string lname, int lyearBuilt, string ltype, bool lbuilt){
    id = lid;
    name = lname;
    yearBuilt = lyearBuilt;
    type = ltype;
    built = lbuilt;
}
computer::~computer(){

}

int computer::getId()const{
    return id;
}

string computer::getName()const{
    return name;
}
int computer::getYearBuilt()const{
    return yearBuilt;
}
string computer::getType()const{
    return type;
}
bool computer::wasBuilt()const{
    return built;
}

void computer::setId(int i){
    id = i;
}

void computer::setName(string n){
    name = n;
}
void computer::setYearBuilt(int y){
    yearBuilt = y;
}
void computer::setType(int t){
    string types[] = {"transistor","electromechanical","electronic","electric"};
    type = types[t];
}
void computer::setBuilt(bool b){
    built = b;
}

bool computer::isYearBuiltValid(){
    if(yearBuilt > 1600 && yearBuilt < 2015){
        built = true;
        return true;
    }
    else if(yearBuilt == -1){
        built = false;
        return true;
    }
    else
        return false;
}

bool computer::isTypeValid(int t){
    if(t > 0 && t <= 3)
        return true;
    else
        return false;
}

