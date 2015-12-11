#ifndef DATAACCESS_H
#define DATAACCESS_H
#include <iostream>
#include <QSqlDatabase>

class dataAccess
{
private:
    QSqlDatabase dbMain;
    QString dbName;
public:
    dataAccess();
    ~dataAccess();
    void open();
    void close();
    QSqlDatabase& readDb();
};

#endif // DATAACCESS_H
