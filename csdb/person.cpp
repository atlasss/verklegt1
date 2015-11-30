#include "person.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

person::person()
{

    name = "missing";
    dateBirth = "missing";
    dateDeath = "missing";
    gender = "missing";
    id = -1;
}

person::person(string lname, string lgender, string lbirth, string ldeath){
    name = lname;
    dateBirth = lbirth;
    dateDeath = ldeath;
    gender = lgender;
    id = -1;
}


person::person(int lid, string lname, string lgender, string lbirth, string ldeath){
    id = lid;
    name = lname;
    dateBirth = lbirth;
    dateDeath = ldeath;
    gender = lgender;
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

int person::getId()const{
    return id;
}

string person::getData(){
    string s = to_string(id);
    s.append("\t" + name);
    s.append("\t" + gender);
    s.append("\t" + dateBirth);
    s.append("\t" + dateDeath);
    cout << s << endl;
    return s;
}

void person::setId(int ID){
    id = ID;
}


void person::setName(string lname){
    name = lname;
}

bool person::isGenderValid(){
    string temp = gender;
    if(temp == "Male" || temp == "Female"){
        return true;
    }
    else
        return false;
}

bool person::isDateValid(string date){
    if(date[0] < 48 || date[0] > 51)//xd/mm/yyyy
        return false;
    if(date[1] < 48 || date[1] > 57)//xx/mm/yyyy
        return false;
    if(date[2] != 47)
        return false;
    if(date[3] < 48 || date[3] > 49)//xx/xm/yyyy
        return false;
    if(date[3] == 49 && (date[4] < 48 || date[4]  > 50))//xx/xx/yyyy
        return false;
    else if(date[4] < 49 || date[4] > 57)//xx/xx/yyyy
        return false;
    if(date[5] != 47)
        return false;
    if(date[6] < 49 || date[6] > 50)//xx/xx/xyyy
        return false;
     if(date[7] < 48 || date[7] > 57)//xx/xx/xxyy
         return false;
     if(date[8] < 48 || date[8] > 57)//xx/xx/xxxy
         return false;
     if(date[9] < 48 || date[9] > 57)//xx/xx/xxyy
         return false;

    return true;
}

ostream& operator<< (ostream& out, const person& rhs){
    out << "Name: " << rhs.getName() << "\tId: " << rhs.getId()
        << "\nDetails: "
        << "\n\tGender: " << rhs.getGender()
        << "\n\tBirth: " << rhs.getDateBirth()
        << "\n\tDeath: " << rhs.getDateDeath()
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
        valid = rhs.isDateValid(rhs.dateBirth);
        if(!valid)
            cout << "The date you have entered is not valid." << endl;
    }while(!valid);

    cout << "Enter date of death (dd/mm/yyyy):" << endl;
    do{
        in >> rhs.dateDeath;
        valid = rhs.isDateValid(rhs.dateDeath);
        if(!valid)
            cout << "The date you have entered is not valid." << endl;
    }while(!valid);
    return in;
}

