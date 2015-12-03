#include <QtCore/QCoreApplication>
#include <iostream>
#include "controller.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    controller mainController;
    mainController.read();
    return 0;
}
