#ifndef PERSON
#define PERSON

#include <iostream>
using namespace std;

class person{
private:
    std::string name;
    int id;
    string dateBirth;
    string dateDeath;
    int gender;
public:
    person();
    ~person();
    person(std::string lname, int lgender, string lbirth, string ldeath);
    person(int lid, std::string lname, int lgender, string lbirth, string ldeath);

    std::string getName()const;
    string getDateBirth()const;
    string getDateDeath()const;
    int getGender()const;
    int getId()const;
    string getData();

    void setName(string lname);
    void setId(int id);

    bool isDateValid(string date);

    friend istream& operator>> (istream& in, person& rhs);
    friend ostream& operator<< (ostream& out, const person& rhs);
};



#endif // PERSON


