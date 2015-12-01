#ifndef PERSON
#define PERSON

#include <iostream>
using namespace std;

class person{
private:
    int id;
    string name;
    string dateBirth;
    string dateDeath;
    string gender;
public:
    person();
    ~person();
    person(string lname, string lgender, string lbirth, string ldeath);
    person(int lid, string lname, string lgender, string lbirth, string ldeath);

    std::string getName()const;
    string getDateBirth()const;
    string getDateDeath()const;
    string getGender()const;
    int getId()const;
    //returns string with data which is saved to file
    string getData();

    void setName(string lname);
    void setId(int id);
    //validates date string
    bool isDateBirthValid();
    //validates date string
    bool isDateDeathValid();
    //validates gender string
    bool isGenderValid();
    friend istream& operator>> (istream& in, person& rhs);
    friend ostream& operator<< (ostream& out, const person& rhs);
};



#endif // PERSON


