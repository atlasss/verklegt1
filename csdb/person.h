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
    person(std::string lname, int lgender, int lbirthy, int ldeathy);
    person(int lid, std::string lname, int lgender, int lbirthy, int ldeathy);

    std::string getName()const;
    int getBirthy()const;
    int getDeathy()const;
    int getGender()const;
    int getId()const;
    string getData();

    void setName(string lname);
    void setId(int id);
    friend istream& operator>> (istream& in, person& rhs);
    friend ostream& operator<< (ostream& out, const person& rhs);
};



#endif // PERSON


