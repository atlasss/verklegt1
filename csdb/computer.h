#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>

using namespace std;

class computer
{
private:
string name;
int yearBuilt;
string type;
bool built;

public:
    computer();
    computer(string lname, int lyearBuilt, string ltype, bool built);
    ~computer();


    string getName();
    int getYearBuilt();
    string getType();
    bool wasBuilt();

    bool isYearBuiltValid();
    bool isTypeValid();
};

#endif // COMPUTER_H
