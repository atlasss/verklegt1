#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>
#include <QByteArray>

using namespace std;

class computer{
private:
    int id;
    string name;
    int yearBuilt;
    string type;
    bool built;
    double weight;
    QByteArray pic;
public:
    computer();
    computer(string lname, int lyearBuilt, string ltype, bool lbuilt, double lweight, QByteArray lpic);
    computer(int lid,string lname, int lyearBuilt, string ltype, bool built, double lweight, QByteArray lpic);
    ~computer();

    int getId()const;
    string getName()const;
    int getYearBuilt()const;
    string getType()const;
    double getWeight()const;
    QByteArray getPic()const;
    int wasBuilt()const;

    void setId(int i);
    void setName(string n);
    void setYearBuilt(int y);
    void setType(string t);
    void setBuilt(int b);
    void setWeight(double w);
    void setPic(QByteArray lpic);

    //used to verify if yearbuilt is valid when user fills in form to create a new computer
    bool isYearBuiltValid();
    //used to verify if type is valid when user fills in form to create a new computer
    bool isTypeValid();
};

#endif // COMPUTER_H
