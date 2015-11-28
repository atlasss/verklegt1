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
    id = -1;
}

person::person(string lname, int lgender, int lbirthy, int ldeathy){
    name = lname;
    birthy = lbirthy;
    deathy = ldeathy;
    gender = lgender;
    id = -1;
}


person::person(int lid, string lname, int lgender, int lbirthy, int ldeathy){
    id = lid;
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
}
int person::getDeathy()const{
    return deathy;
}
int person::getGender()const{
    return gender;
}

int person::getId()const{
    return id;
}

string person::getData(){
    string s = to_string(id);
    s.append("\t" + name);
    s.append("\t\t" + to_string(gender));
    s.append("\t" + to_string(birthy));
    s.append("\t" + to_string(deathy));
    return s;
}

void person::setId(int ID){
    id = ID;
}


void person::setName(string lname){
    name = lname;
}

ostream& operator<< (ostream& out, const person& rhs){
    out << "Name: " << rhs.getName() << "\tId: " << rhs.getId()
        << "\nDetails: "
        << "\n\tGender: " << rhs.getGender()
        << "\n\tBirth: " << rhs.getBirthy()
        << "\n\tDeath: " << rhs.getDeathy()
        << endl;
    return out;
}

istream& operator>> (istream& in, person& rhs){

    cout << "Enter name: "<< endl;
    in >> rhs.name;
    cout << "Enter gender: (0/1)" << endl;
    in >> rhs.gender;
    cout << "Enter year of birth: " << endl;
    in >> rhs.birthy;
    cout << "Enter year of death (-1 if N/A):" << endl;
    in >> rhs.deathy;
    return in;
}

