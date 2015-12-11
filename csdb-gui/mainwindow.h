#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dataaccess.h"
#include "computerlist.h"
#include "personlist.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

private:
    Ui::MainWindow *ui;
    dataAccess dbMain;
    computerlist listComputer;
    personlist listPerson;

    void displayAllPersons();
    void displayPersons(vector<person> persons);

    vector<person> displayedPersons;

};

#endif // MAINWINDOW_H
