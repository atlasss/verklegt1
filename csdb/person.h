#ifndef PERSON
#define PERSON

#include <iostream>

class person{
private:
    std::string name;
    int birthy;
    int deathy;
    int gender;
public:
    person();
    ~person();
    person(std::string lname, int lbirthy, int ldeathy, int lgender);


    std::string getName();
    int getBirthy();
    int getDeathy();
    int getGender();
};

//ostream& operator<< (ostream& out, const person& rhs);

//istream& operator>> (istream& in, const person& rhs);

#endif // PERSON


