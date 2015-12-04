#include "person.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cctype>

using namespace std;

person::person(){

    name = "missing";
    dateBirth = "missing";
    dateDeath = "missing";
    gender = "missing";
    knownFor = "missing";
    id = -1;
    age = -1;
}

person::person(string lname, string lgender, string lbirth, string ldeath, string lknown){
    name = lname;
    dateBirth = lbirth;
    dateDeath = ldeath;
    gender = lgender;
    knownFor = lknown;
    id = -1;
}


person::person(int lid, string lname, string lgender, string lbirth, string ldeath, string lknown){
    id = lid;
    name = lname;
    dateBirth = lbirth;
    dateDeath = ldeath;
    gender = lgender;
    knownFor = lknown;
}

person::~person(){

}


string person::getName()const{
    return name;
}
string person::getDateBirth()const{
    return dateBirth;
}
string person::getDateDeath()const{
    return dateDeath;
}
string person::getGender()const{
    return gender;
}

string person::getKnownFor()const{
    return knownFor;
}

int person::getId()const{
    return id;
}

double person::getAge()const{
    return age;
}

string person::getData(){
    string s = to_string(id);
    s.append("\t" + name);
    s.append("\t" + gender);
    s.append("\t" + dateBirth);
    s.append("\t" + dateDeath);
    s.append("\t" + knownFor);
    return s;
}

void person::setId(int ID){
    id = ID;
}

void person::setName(string lname){
    name = lname;
}

void person::setDateBirth(string lbirth){
    dateBirth = lbirth;
}
void person::setDateDeath(string ldeath){
    dateDeath = ldeath;
}
void person::setGender(string lgender){
    gender = lgender;
}

void person::setKnownFor(string lknown){
    knownFor = lknown;
}

bool person::isGenderValid(){
    string temp = gender;
    if(temp == "Male" || temp == "Female"){
        return true;
    }
    else
        return false;
}


bool person::isDateBirthValid(){
    //checks each character in the date string to confirm wether they are the correct ascii values
    if(dateBirth[0] < 48 || dateBirth[0] > 51)//xd/mm/yyyy
        return false;
    if(dateBirth[1] < 48 || dateBirth[1] > 57)//xx/mm/yyyy
        return false;
    if(dateBirth[2] != 47)
        return false;
    if(dateBirth[3] < 48 || dateBirth[3] > 49)//xx/xm/yyyy
        return false;
    if(dateBirth[3] == 49 && (dateBirth[4] < 48 || dateBirth[4]  > 50))//xx/xx/yyyy
        return false;
    else if(dateBirth[4] < 48 || dateBirth[4] > 57)//xx/xx/yyyy
        return false;
    if(dateBirth[5] != 47)
        return false;
    if(dateBirth[6] < 49 || dateBirth[6] > 50)//xx/xx/xyyy
        return false;
    if(dateBirth[7] < 48 || dateBirth[7] > 57)//xx/xx/xxyy
        return false;
    if(dateBirth[8] < 48 || dateBirth[8] > 57)//xx/xx/xxxy
        return false;
    if(dateBirth[9] < 48 || dateBirth[9] > 57)//xx/xx/xxxx
        return false;

    bval  = ((dateBirth[6] - 48)* 1000 + (dateBirth[7]- 48) * 100 + (dateBirth[8]- 48) * 10 + (dateBirth[9]- 48)) * 365.25;
    bval += ((dateBirth[3] - 48) * 10 + (dateBirth[4] - 48)) * 30.4375;
    bval += ((dateBirth[0] - 48) * 10 + (dateBirth[1] - 48));
    return true;
}

bool person::isDateDeathValid(){    
    double maxAge = 2015 * 365.25 + 12 * 30.4375 + 4;
    age = maxAge - bval;
    if (dateDeath == "-1"){
        dateDeath = "Alive";
        return true;
    }
    if(dateDeath[0] < 48 || dateDeath[0] > 51)//xd/mm/yyyy
        return false;
    if(dateDeath[1] < 48 || dateDeath[1] > 57)//xx/mm/yyyy
        return false;
    if(dateDeath[2] != 47)
        return false;
    if(dateDeath[3] < 48 || dateDeath[3] > 49)//xx/xm/yyyy
        return false;
    if(dateDeath[3] == 49 && (dateDeath[4] < 48 || dateDeath[4]  > 50))//xx/xx/yyyy
        return false;
    else if(dateDeath[4] < 48 || dateDeath[4] > 57)//xx/xx/yyyy
        return false;
    if(dateDeath[5] != 47)
        return false;
    if(dateDeath[6] < 49 || dateDeath[6] > 50)//xx/xx/xyyy
        return false;
    if(dateDeath[7] < 48 || dateDeath[7] > 57)//xx/xx/xxyy
        return false;
    if(dateDeath[8] < 48 || dateDeath[8] > 57)//xx/xx/xxxy
        return false;
    if(dateDeath[9] < 48 || dateDeath[9] > 57)//xx/xx/xxxx
        return false;

    dval  = ((dateDeath[6]- 48) * 1000 + (dateDeath[7]- 48) * 100 + (dateDeath[8]- 48) * 10 + (dateDeath[9]- 48)) * 365.25;
    dval += (dateDeath[3]- 48) * 10 + (dateDeath[4] - 48)*30.4375;
    dval += (dateDeath[0]- 48) * 10 + (dateDeath[1] - 48);

    if(bval > dval)
        return false;

    age = dval - bval;
    return true;
}

ostream& operator<< (ostream& out, const person& rhs){
    out << "Name: " << rhs.getName() << "\tId: " << rhs.getId()
        << "\nDetails: "
        << "\n\tGender: " << rhs.getGender()
        << "\n\tBirth: " << rhs.getDateBirth()
        << "\n\tDeath: " << rhs.getDateDeath()
        << "\n\tKnown for: " << rhs.getKnownFor()
        << endl;
    return out;
}

istream& operator>> (istream& in, person& rhs){
    bool valid = false;
    cout << "Enter name: "<< endl;
    in >> rhs.name;
    cout << "Enter gender(Male/Female): " << endl;
    do{
        in >> rhs.gender;

        transform(rhs.gender.begin(), rhs.gender.end(), rhs.gender.begin(), ::tolower);

        if(rhs.gender[0] == 'f')
            rhs.gender[0] = 'F';
        else if(rhs.gender[0] == 'm')
            rhs.gender[0] = 'M';

        valid = rhs.isGenderValid();
        if(!valid)
            cout << "The gender you have entered is not valid. " << endl;
    }while(!valid);
    cout << "Enter date of birth(dd/mm/yyyy): " << endl;
    do{
        in >> rhs.dateBirth;
        valid = rhs.isDateBirthValid();
        if(!valid)
            cout << "The date you have entered is not valid." << endl;
    }while(!valid);

    cout << "Enter date of death (dd/mm/yyyy) or -1 if the person is still alive:" << endl;
    do{
        in >> rhs.dateDeath;
        valid = rhs.isDateDeathValid();
        if(!valid)
            cout << "The date you have entered is not valid." << endl;
    }while(!valid);

    return in;
}

