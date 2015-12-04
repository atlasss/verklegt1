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
public:
    computerlist();
    ~computerlist();
    void addComputer();
    void editComputer();
    void deleteComputer();
    void readFile(QString dbName);
    //appends string with details of a person  in pList to txt file
    void writeToFile(QString dbName, computer newComputer);
    //overwrites  txt file with all details in pList
    void overwriteFile(QString dbName);
};

#endif // COMPUTERLIST_H
