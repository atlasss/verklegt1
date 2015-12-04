#include "computer.h"

computer::computer(){
    name = "missing";
    yearBuilt = -1;
    type = "missing";
    built = false;
}

computer::computer(string lname, int lyearBuilt, string ltype, bool lbuilt){
    name = lname;
    yearBuilt = lyearBuilt;
    type = ltype;
    built = lbuilt;
}
computer::~computer(){

}

string computer::getName(){
    return name;
}
int computer::getYearBuilt(){
    return yearBuilt;
}
string computer::getType(){
    return type;
}
bool computer::wasBuilt(){
    return built;
}

bool computer::isYearBuiltValid(){
    if(yearBuilt > 1600 && yearBuilt < 2015){
        return true;
        built = true;
    }
    else if(yearBuilt == -1){
        built = false;
        return true;
    }
}

bool computer::isTypeValid(){
    return false;
}

