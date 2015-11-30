#include "person.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

person::person()
{

    name = "missing";
    dateBirth = "missing";
    dateDeath = "missing";
    gender = -1;
    id = -1;
}

person::person(string lname, int lgender, string lbirth, string ldeath){
    name = lname;
    dateBirth = lbirth;
    dateDeath = ldeath;
    gender = lgender;
    id = -1;
}


person::person(int lid, string lname, int lgender, string lbirth, string ldeath){
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
int person::getGender()const{
    return gender;
}

int person::getId()const{
    return id;
}

string person::getData(){
    string s = to_string(id);
    s.append("\t" + name);
    s.append("\t" + to_string(gender));
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
    string temp;
    bool valid = false;
    cout << "Enter name: "<< endl;
    in >> rhs.name;
    cout << "Enter gender: (0/1)" << endl;
    in >> rhs.gender;
    cout << "Enter year of birth (format dd/mm/yyyy): " << endl;
    while(!valid){
        in >> rhs.dateBirth;
        valid = rhs.isDateValid(rhs.dateBirth);
        if(!valid)
            cout << "The date you have entered is not valid." << endl;
    }

    cout << "Enter year of death (format dd/mm/yyyy):" << endl;
    while(!valid){
        in >> rhs.dateDeath;
        valid = rhs.isDateValid(rhs.dateDeath);
        if(!valid)
            cout << "The date you have entered is not valid." << endl;
    }
    return in;
}

