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
class computerlist
{
private:
    vector<computer> cList;
    int NOInList;
public:
    computerlist();
    ~computerlist();
    void addComputer(QSqlDatabase& dbMain, computer newComputer);
    void editComputer(int i, computer editComputer, QSqlDatabase& dbMain);
    void deleteComputer(int index, QSqlDatabase& dbMain);
    vector<computer> getFullList();
    bool idExists(int i);
    crel getRel(int i, QSqlDatabase& dbMain);

    void readFile(QSqlDatabase& dbMain);
    void readFileAlpha(QSqlDatabase& dbMain);
    void readFileAlphaDec(QSqlDatabase& dbMain);
    void readFileAge(string m, QSqlDatabase& dbMain);
    void readFileName(string n, QSqlDatabase& dbMain);
    void readFileId(int i, QSqlDatabase& dbMain);

    void writeToFile(QSqlDatabase& dbMain, computer newComputer);
};

#endif // COMPUTERLIST_H
