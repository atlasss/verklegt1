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
    string knownFor;
    int age;
public:
    person();
    ~person();
    person(string lname, string lgender, string lbirth, string ldeath, string lknown);
    person(int lid, string lname, string lgender, string lbirth, string ldeath, string lknown);

    std::string getName()const;
    string getDateBirth()const;
    string getDateDeath()const;
    string getGender()const;
    string getKnownFor()const;
    int getId()const;
    //returns string with all necessary data which is stored in the txt file
    string getData();

    void setName(string lname);
    void setDateBirth(string lbirth);
    void setDateDeath(string ldeath);
    void setGender(string lgender);
    void setKnownFor(string lknown);
    void setId(int id);
    //validates date string when filling out the form
    bool isDateBirthValid();
    //validates date string when filling out the form
    bool isDateDeathValid();
    //validates gender string when filling out the form
    bool isGenderValid();
    friend istream& operator>> (istream& in, person& rhs);
    friend ostream& operator<< (ostream& out, const person& rhs);
};



#endif // PERSON


