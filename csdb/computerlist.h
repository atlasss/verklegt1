#ifndef COMPUTERLIST_H
#define COMPUTERLIST_H
#include <QSqlDatabase>
#include <vector>
#include <computer.h>

using namespace std;

class computerlist
{
private:
    vector<computer> cList;
    int NOInList;
public:
    computerlist();
    ~computerlist();
    void addComputer(QSqlDatabase& dbMain, computer newComputer);
    void editComputer(QSqlDatabase& dbMain, computer newComputer);
    void deleteComputer();
    vector<computer> getFullList();
    void readFile(QSqlDatabase& dbMain);
    void readFileAlpha(QSqlDatabase& dbMain);
    void readFileAlphaDec(QSqlDatabase& dbMain);
    void readFileId(int i, QSqlDatabase& dbMain);
    void writeToFile(QSqlDatabase& dbMain, computer newComputer);
};

#endif // COMPUTERLIST_H
