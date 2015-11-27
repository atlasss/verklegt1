#include "person.h"

#include <iostream>
#include <string>
using namespace std;

person::person()
{
    name = "missing";
    birthy = 0;
    deathy = 0;
    gender = -1;
}

person::person(string lname, int lbirthy, int ldeathy, int lgender){
    name = lname;
    birthy = lbirthy;
    deathy = ldeathy;
    gender = lgender;
}
person::~person(){

}


string person::getName()const{
    return name;
}
int person::getBirthy(){
    return birthy;
};
int person::getDeathy(){
    return deathy;
};
int person::getGender(){
    return gender;
};



ostream& operator<< (ostream& out, const person& rhs){
    out << "Name: " << rhs.getName() << endl;
    return out;
}

//istream& operator>> (istream& in, const person& rhs);
