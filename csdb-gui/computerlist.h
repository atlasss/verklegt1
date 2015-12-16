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
    bool addComputer(QSqlDatabase& dbMain, computer newComputer);
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
    void readFile(string n, string a, string t, int b, QSqlDatabase& dbMain, bool asc);
    void readFileAlpha(string n, string a, string t, int b, QSqlDatabase& dbMain, bool asc);
    void readFileAge(string n, string a, string t, int b, QSqlDatabase& dbMain, bool asc);
    void readFileId(int i, QSqlDatabase& dbMain);
    void readFileWeight(string n, string a, string t, int b, QSqlDatabase& dbMain, bool asc);

    bool writeToFile(QSqlDatabase& dbMain, computer newComputer);
};

#endif // COMPUTERLIST_H
