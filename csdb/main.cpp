#include <QCoreApplication>
#include <iostream>
#include <stdio.h>
#include <vector>
#include "person.h"
#include <string>

using namespace std;

//prentar ut upplysingar yfir commands
void printHelp(){

}
//les skipun fra notenda og skilar nr yfir hvada skipun eigi ad framkvaema
int readCommand(string command){

    return -1;
}

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);
    person newPerson;
    cin >> newPerson;

    cout << newPerson;
    return a.exec();
}

