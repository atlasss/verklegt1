#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    personDeleted = false;
    personEdited = false;
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
    //ui->table_person->setSortingEnabled(false);

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

    //ui->table_person->setSortingEnabled(true);
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
    if(!personDeleted && !personEdited){
        int selectedPersonIndex = ui->table_person->currentIndex().row();
        person selectedPerson = displayedPersons[selectedPersonIndex];
        prel selectedPersonRelations = listPerson.getRel(selectedPerson.getId(),dbMain.readDb());


        ui->person_name->setEnabled(false);

        ui->person_known_for->setEnabled(false);
        ui->person_birth->setEnabled(false);
        ui->person_death->setEnabled(false);
        ui->button_edit_person->setText("Edit");

        ui->button_delete_person->setEnabled(true);
        ui->button_edit_person->setEnabled(true);

        ui->table_person_connections->clearContents();
        ui->table_person_connections->setRowCount(selectedPersonRelations.cName.size());

        ui->label_person_id->setText("Id:" + QString::number(selectedPerson.getId()));
        ui->person_name->setText(QString::fromStdString(selectedPerson.getName()));
        ui->person_age->setText(QString::number((int)(selectedPerson.getAge()/365.25)));
        ui->person_gender->setText(QString::fromStdString(selectedPerson.getGender()));
        ui->person_known_for->setText(QString::fromStdString(selectedPerson.getKnownFor()));
        ui->person_birth->setText(QString::fromStdString(selectedPerson.getDateBirth()));
        ui->person_death->setText(QString::fromStdString(selectedPerson.getDateDeath()));
        //ui->person_age->setStyleSheet("background-color: rgb(255,130,0);");

        for(unsigned int row = 0; row < selectedPersonRelations.cName.size(); row++){
            QString relatedComputerId = QString::number(selectedPersonRelations.cId[row]);
            QString relatedComputerName = QString::fromStdString(selectedPersonRelations.cName[row]);

            ui->table_person_connections->setItem(row,0, new QTableWidgetItem(relatedComputerId));
            ui->table_person_connections->setItem(row,1, new QTableWidgetItem(relatedComputerName));
        }
    }
    else{
        personDeleted = false;
        personEdited = false;
    }
}


void MainWindow::on_add_person_confirm_clicked()
{
    string gender;
    bool errorFound = false;

    ui->label_name_error_code->setText("");
    ui->label_date_birth_error_code->setText("");
    ui->label_date_death_error_code->setText("");
    ui->label_known_for_error_code->setText("");
    if(ui->radio_male->isChecked())
        gender = "Male";
    else
        gender = "Female";

    QString name = ui->line_person_name->text();
    QString dateBirth = ui->line_person_date_birth->text();
    QString dateDeath = ui->line_person_date_death->text();
    QString knownFor = ui->text_person_known_for->toPlainText();

    person newPerson;

    if(name.isEmpty()){
        ui->label_name_error_code->setText("Field can't be empty");
        errorFound = true;
    }
    newPerson.setName(name.toStdString());
    newPerson.setDateBirth(dateBirth.toStdString());
    if(!newPerson.isDateBirthValid()){
        ui->label_date_birth_error_code->setText("Date needs to be in format dd/mm/yyyy");
        errorFound = true;
    }

    newPerson.setDateDeath(dateDeath.toStdString());
    if(!newPerson.isDateDeathValid()){
        ui->label_date_death_error_code->setText("<div style='color:rgb(255,0,0)'>Date needs to be in format dd/mm/yyyy</div>");
        errorFound = true;
    }

    if(knownFor.isEmpty()){
        ui->label_known_for_error_code->setText("Field can't be empty");
    }
    newPerson.setKnownFor(knownFor.toStdString());
    if(errorFound)
        return;

    listPerson.addPerson(dbMain.readDb(), newPerson);

    ui->search_person->setText("");
    displayAllPersons();

    ui->statusBar->showMessage("Successfully added person", 1500);
}


void MainWindow::on_button_delete_person_clicked()
{
    int selectedPersonIndex = ui->table_person->currentIndex().row();

    person SelectedPerson = displayedPersons[selectedPersonIndex];
    int confirm = QMessageBox::question(this, "Confirm", "Are you sure you want to delete this person?");

    if (confirm == QMessageBox::No){
        return;
    }


    ui->button_delete_person->setEnabled(false);
    ui->button_edit_person->setEnabled(false);


    ui->table_person_connections->clearContents();

    ui->label_person_id->setText("Id:");
    ui->person_name->setText("");
    ui->person_age->setText("");
    ui->person_known_for->setText("");
    ui->person_birth->setText("");


    ui->person_name->setEnabled(false);

    ui->person_known_for->setEnabled(false);
    ui->person_birth->setEnabled(false);
    ui->person_death->setEnabled(false);


    listPerson.deletePerson(SelectedPerson.getId(),dbMain.readDb());
    ui->search_person->setText("");
    personDeleted = true;
    displayAllPersons();

}

void MainWindow::on_button_edit_person_clicked()
{
    if(ui->button_edit_person->text() == "Edit"){
        ui->person_name->setEnabled(true);
        ui->person_gender->setEnabled(true);
        ui->person_known_for->setEnabled(true);
        ui->person_birth->setEnabled(true);
        ui->person_death->setEnabled(true);

        ui->button_edit_person->setText("Save changes");
    }
    else if(ui->button_edit_person->text() == "Save changes"){
        bool errorFound = false;
        QString name = ui->person_name->text();
        QString gender = ui->person_gender->text();
        QString knownFor = ui->person_known_for->toPlainText();
        QString dateBirth = ui->person_birth->text();
        QString dateDeath = ui->person_death->text();

        int selectedPersonIndex = ui->table_person->currentIndex().row();

        person SelectedPerson = displayedPersons[selectedPersonIndex];

        person editedPerson;

        QString errorMessage = "";

        if(name.isEmpty()){
            errorMessage.append("<div style='color:rgb(255,0,0)'>Name field can't be empty</>\n");
            errorFound = true;
        }
        editedPerson.setName(name.toStdString());
        editedPerson.setDateBirth(dateBirth.toStdString());
        if(!editedPerson.isDateBirthValid()){
            errorMessage.append("<div style='color:rgb(255,0,0)'>Date birth needs to be in format dd/mm/yyyy</>\n");
            errorFound = true;
        }

        editedPerson.setGender(gender.toStdString());
        if(!editedPerson.isGenderValid()){
            errorMessage.append("<div style='color:rgb(255,0,0)'>Gender needs to be either Male or Female</>\n");
            errorFound = true;
        }

        editedPerson.setDateDeath(dateDeath.toStdString());
        if(!editedPerson.isDateDeathValid() && dateDeath != "Alive"){
            errorMessage.append("<div style='color:rgb(255,0,0)'>Date death needs to be in format dd/mm/yyyy or Alive</>\n");
            errorFound = true;
        }

        if(knownFor.isEmpty()){
            errorMessage.append("<div style='color:rgb(255,0,0)'>Known for field can't be empty</>\n");
            errorFound = true;
        }
        editedPerson.setKnownFor(knownFor.toStdString());

        if(errorFound){
            QMessageBox::information(this,"Error editing person",errorMessage);
            return;
        }

        listPerson.editPerson(SelectedPerson.getId(),editedPerson,dbMain.readDb());
        ui->button_edit_person->setText("Edit");
        ui->person_name->setEnabled(false);
        ui->person_gender->setEnabled(false);
        ui->person_known_for->setEnabled(false);
        ui->person_birth->setEnabled(false);
        ui->person_death->setEnabled(false);

        ui->person_age->setText(QString::number(int(editedPerson.getAge() / 365.25)));
        ui->person_name->setText(QString::fromStdString(editedPerson.getName()));

        ui->person_gender->setText(QString::fromStdString(editedPerson.getGender()));
        ui->person_known_for->setText(QString::fromStdString(editedPerson.getKnownFor()));
        ui->person_birth->setText(QString::fromStdString(editedPerson.getDateBirth()));
        ui->person_death->setText(QString::fromStdString(editedPerson.getDateDeath()));
        personEdited = true;


        displayAllPersons();
        ui->search_person->setText("");



    }

}
