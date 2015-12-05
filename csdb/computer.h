#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>

using namespace std;

class computer
{
private:
int id;
string name;
int yearBuilt;
string type;
bool built;

public:
    computer();
    computer(string lname, int lyearBuilt, string ltype, bool lbuilt);
    computer(int lid,string lname, int lyearBuilt, string ltype, bool built);
    ~computer();

    int getId()const;
    string getName()const;
    int getYearBuilt()const;
    string getType()const;
    bool wasBuilt()const;

    void setId(int i);
    void setName(string n);
    void setYearBuilt(int y);
    void setType(int t);
    void setBuilt(bool b);

    bool isYearBuiltValid();
    bool isTypeValid(int t);
};

#endif // COMPUTER_H
