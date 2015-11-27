#include "person.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

person::person()
{
    name = "missing";
    birthy = 0;
    deathy = 0;
    gender = -1;
    id = 0;
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
int person::getBirthy()const{
    return birthy;
};
int person::getDeathy()const{
    return deathy;
};
int person::getGender()const{
    return gender;
};


void person::setName(string lname){
    name = lname;
};

ostream& operator<< (ostream& out, const person& rhs){
    out << "Name: " << rhs.getName()
        << "\nDetails: "
        << "\n\tBirth: " << rhs.getBirthy()
        << endl;
    return out;
}

istream& operator>> (istream& in, person& rhs){

    cout << "Enter name: " << endl;
    in >> rhs.name;
    cout << "Enter gender: (0/1)" << endl;
    in >> rhs.gender;
    cout << "Enter year of birth: " << endl;
    in >> rhs.birthy;
    cout << "Enter year of death (if appropriate):" << endl;
    in >> rhs.deathy;
    return in;
}

