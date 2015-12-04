#ifndef COMPUTERLIST_H
#define COMPUTERLIST_H
#include <QSqlDatabase>
#include <vector>
#include <computer.h>

using namespace std;

class computerlist
{
private:
    QSqlDatabase computerdb;
    vector<computer> cList;
    int NOInList;
public:
    computerlist();
    ~computerlist();
    void addComputer(QString dbName, computer newComputer);
    void editComputer(QString dbName, computer newComputer);
    void deleteComputer();
    void readFile(QString dbName);
    void readFileAlpha(QString dbName);
    void readFileAlphaDec(QString dbName);
    void writeToFile(QString dbName, computer newComputer);
};

#endif // COMPUTERLIST_H
