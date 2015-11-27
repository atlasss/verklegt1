#include "person.h"

#include <iostream>
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


string person::getName(){
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


