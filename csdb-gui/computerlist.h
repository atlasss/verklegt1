#ifndef COMPUTERLIST_H
#define COMPUTERLIST_H
#include <QSqlDatabase>
#include <vector>
#include <computer.h>

using namespace std;
struct crel{
    string cName;
    vector<string> pName;
    int cId;
    vector<int> pId;
};
class computerlist{
private:
    vector<computer> cList;
    int NOInList;
public:
    computerlist();
    ~computerlist();
    //add a new computer to the list
    void addComputer(QSqlDatabase& dbMain, computer newComputer);
    //edit a computer already in the list
    void editComputer(int i, computer editComputer, QSqlDatabase& dbMain);
    //remove an existing computer from the list
    void deleteComputer(int index, QSqlDatabase& dbMain);
    //returns cList
    vector<computer> getFullList();
    //returns true if id exists in cList
    bool idExists(int i);
    //get persons connected to the computer that matches the id
    crel getRel(int i, QSqlDatabase& dbMain);
    void readFile(QSqlDatabase& dbMain);
    void readFileAlpha(QSqlDatabase& dbMain);
    void readFileAlphaDec(QSqlDatabase& dbMain);
    void readFileAge(string m, QSqlDatabase& dbMain);
    void readFileName(string n, QSqlDatabase& dbMain);
    void readFileId(int i, QSqlDatabase& dbMain);
    void readFileWeight(QSqlDatabase& dbMain);

    void writeToFile(QSqlDatabase& dbMain, computer newComputer);
};

#endif // COMPUTERLIST_H
