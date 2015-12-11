#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <addperson.h>

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
    ui->table_person->setSortingEnabled(false);

    for (unsigned int row = 0; row < persons.size(); row++){
        person currentPerson = persons[row];

        //QString id =());
        QString name = QString::fromStdString(currentPerson.getName());
        QString dBirth = QString::fromStdString(currentPerson.getDateBirth());
        QString dDeath = QString::fromStdString(currentPerson.getDateDeath());

        ui->table_person->setItem(row,0, new QTableWidgetItem(QString::number(currentPerson.getId())));
        ui->table_person->setItem(row,1, new QTableWidgetItem(name));
        ui->table_person->setItem(row, 2, new QTableWidgetItem(dBirth));
        ui->table_person->setItem(row, 3, new QTableWidgetItem(dDeath));
    }

        displayedPersons = persons;

        ui->table_person->setSortingEnabled(true);
}



void MainWindow::on_search_person_textChanged(const QString &arg1)
{
    string input = ui->search_person->text().toStdString();
    listPerson.readFileName(input, dbMain.readDb());
    vector<person> persons = listPerson.getFullList();
    displayPersons(persons);
}

void MainWindow::on_table_person_itemSelectionChanged()
{
    int selectedPersonIndex = ui->table_person->currentIndex().row();
    person selectedPerson = displayedPersons[selectedPersonIndex];
    prel selectedPersonRelations = listPerson.getRel(selectedPerson.getId(),dbMain.readDb());

    ui->table_person_connections->clearContents();
    ui->table_person_connections->setRowCount(selectedPersonRelations.cName.size());

    ui->person_name->setText(QString::fromStdString(selectedPerson.getName()));
    ui->person_age->setText(QString::number((int)(selectedPerson.getAge()/365.25)));
    ui->person_known_for->setText(QString::fromStdString(selectedPerson.getKnownFor()));
    ui->person_birth->setText(QString::fromStdString(selectedPerson.getDateBirth()));
    ui->person_death->setText(QString::fromStdString(selectedPerson.getDateDeath()));
    ui->person_age->setStyleSheet("background-color: rgb(255,130,0);");

    for(unsigned int row = 0; row < selectedPersonRelations.cName.size(); row++){
        QString relatedComputerId = QString::number(selectedPersonRelations.cId[row]);
        QString relatedComputerName = QString::fromStdString(selectedPersonRelations.cName[row]);

        ui->table_person_connections->setItem(row,0, new QTableWidgetItem(relatedComputerId));
        ui->table_person_connections->setItem(row,1, new QTableWidgetItem(relatedComputerName));
    }
}


void MainWindow::on_add_person_clicked()
{
    addPerson addPersonForm;
    int formOpen = addPersonForm.exec();

    if (formOpen == 0)
    {
        ui->search_person->setText("");
        displayAllPersons();

        ui->statusBar->showMessage("Successfully added person", 1500);
    }
    else
    {
        // there was an error
    }
}
