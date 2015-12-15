#include "computer.h"

computer::computer(){
    id = -1;
    name = "missing";
    yearBuilt = -1;
    type = "missing";
    built = false;
    weight = -1;
}

computer::computer(string lname, int lyearBuilt, string ltype, bool lbuilt, double lweight){
    id = -1;
    name = lname;
    yearBuilt = lyearBuilt;
    type = ltype;
    built = lbuilt;
    weight = lweight;
}

computer::computer(int lid, string lname, int lyearBuilt, string ltype, bool lbuilt, double lweight){
    id = lid;
    name = lname;
    yearBuilt = lyearBuilt;
    type = ltype;
    built = lbuilt;
    weight = lweight;
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
double computer::getWeight()const{
    return weight;
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
void computer::setType(string t){
    type = t;
}
void computer::setBuilt(bool b){
    built = b;
}
void computer::setWeight(double w){
    weight = w;
}

bool computer::isYearBuiltValid(){
    if(yearBuilt >= 1600 && yearBuilt <= 2015){
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
    if(t >= 0 && t <= 3)
        return true;
    else
        return false;
}

