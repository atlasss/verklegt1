#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    dbMain.open();
    ui->setupUi(this);

    displayAllPersons();
}

MainWindow::~MainWindow()
{
    dbMain.close();
    delete ui;
}

void MainWindow::displayAllPersons(){
    listPerson.readFile(dbMain.readDb());
    vector<person> persons = listPerson.getFullList();
    displayPersons(persons);
}
void MainWindow::displayPersons(vector<person> persons){
    ui->table_person->clearContents();

    ui->table_person->setRowCount(persons.size());

    for (unsigned int row = 0; row < persons.size(); row++){
        person currentPerson = persons[row];

        QString id = QString::number(currentPerson.getId());
        QString name = QString::fromStdString(currentPerson.getName());
        QString dBirth = QString::fromStdString(currentPerson.getDateBirth());
        QString dDeath = QString::fromStdString(currentPerson.getDateDeath());

        ui->table_person->setItem(row,0, new QTableWidgetItem(id));
        ui->table_person->setItem(row,1, new QTableWidgetItem(name));
        ui->table_person->setItem(row, 2, new QTableWidgetItem(dBirth));
        ui->table_person->setItem(row, 3, new QTableWidgetItem(dDeath));
    }

        displayedPersons = persons;
}


