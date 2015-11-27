#include <QCoreApplication>
#include <iostream>
#include <stdio.h>
#include <vector>
#include "person.h"
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    vector <person> personList;
    int n = 0;
    cin >> n;

    cout << "test" << endl;

    return a.exec();
}

