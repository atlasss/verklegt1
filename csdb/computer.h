#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>

using namespace std;

class computer{
private:
    int id;
    string name;
    int yearBuilt;
    string type;
    bool built;
    double weight;

public:
    computer();
    computer(string lname, int lyearBuilt, string ltype, bool lbuilt, double lweight);
    computer(int lid,string lname, int lyearBuilt, string ltype, bool built, double lweight);
    ~computer();

    int getId()const;
    string getName()const;
    int getYearBuilt()const;
    string getType()const;
    double getWeight()const;
    bool wasBuilt()const;

    void setId(int i);
    void setName(string n);
    void setYearBuilt(int y);
    void setType(int t);
    void setBuilt(bool b);
    void setWeight(double w);
    //used to verify if yearbuilt is valid when user fills in form to create a new computer
    bool isYearBuiltValid();
    //used to verify if type is valid when user fills in form to create a new computer
    bool isTypeValid(int t);
};

#endif // COMPUTER_H
