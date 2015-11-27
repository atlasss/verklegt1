#ifndef PERSON
#define PERSON

#include <iostream>
using namespace std;

class person{
private:
    std::string name;
    int id;
    int birthy;
    int deathy;
    int gender;
public:
    person();
    ~person();
    person(std::string lname, int lbirthy, int ldeathy, int lgender);


    std::string getName()const;
    int getBirthy();
    int getDeathy();
    int getGender();
};

ostream& operator<< (ostream& out, const person& rhs);

//istream& operator>> (istream& in, const person& rhs);

#endif // PERSON


