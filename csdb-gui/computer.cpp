#include "computer.h"

computer::computer(){
    id = -1;
    name = "missing";
    yearBuilt = -1;
    type = "missing";
    built = false;
    weight = -1;
}

computer::computer(string lname, int lyearBuilt, string ltype, bool lbuilt, double lweight, QByteArray lpic){
    id = -1;
    name = lname;
    yearBuilt = lyearBuilt;
    type = ltype;
    built = lbuilt;
    weight = lweight;
    pic = lpic;
}

computer::computer(int lid, string lname, int lyearBuilt, string ltype, bool lbuilt, double lweight, QByteArray lpic){
    id = lid;
    name = lname;
    yearBuilt = lyearBuilt;
    type = ltype;
    built = lbuilt;
    weight = lweight;
    pic = lpic;
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

QByteArray computer::getPic() const{
    return pic;
}
int computer::wasBuilt()const{
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
void computer::setBuilt(int b){
    built = b;
}
void computer::setWeight(double w){
    if(w < 0)
        weight = -1;
    else
        weight = w;
}

void computer::setPic(QByteArray lpic){
    pic = lpic;
}

bool computer::isYearBuiltValid(){
    if(yearBuilt >= 1600 && yearBuilt <= 2015){
        built = 1;
        return true;
    }
    else if(yearBuilt == -1){
        built = 0;
        yearBuilt = 0;
        return true;
    }
    else
        return false;
}

bool computer::isTypeValid(){
    string types[] = {"electromechanical","electronic","mechanical","transistor"};

    for(unsigned int i = 0; i < 4; i++){
        if (type == types[i])
            return true;
    }
    return false;
}

