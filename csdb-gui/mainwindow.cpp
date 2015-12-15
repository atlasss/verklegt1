#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    personDeleted = false;
    personEdited = false;

    computerDeleted = false;
    computerEdited = false;

    dbMain.open();
    ui->setupUi(this);
    displayAllPersons();
    displayAllComputers();
}

MainWindow::~MainWindow(){
    dbMain.close();
    delete ui;
}


bool MainWindow::validateAgeString(string a){
    bool midFound = false;
    for(unsigned int i = 0; i < a.size(); i++){
      if(a[i] == 45){
          if(!midFound)
              midFound = true;
          else
              return false;
      }
      else if(a[i] < 48 || a[i] > 57){
          return false;
      }
    }

      return midFound;
}

void MainWindow::displayAllPersons(){
    listPerson.readFile("", "", "",dbMain.readDb(),1);
    vector<person> persons = listPerson.getFullList();
    displayPersons(persons);
}
void MainWindow::displayPersons(vector<person> persons){
    ui->table_person->clearContents();
    ui->table_person->setRowCount(persons.size());

    for (unsigned int row = 0; row < persons.size(); row++){
        person currentPerson = persons[row];

        QString name = QString::fromStdString(currentPerson.getName());
        QString dBirth = QString::fromStdString(currentPerson.getDateBirth());
        QString dDeath = QString::fromStdString(currentPerson.getDateDeath());

        ui->table_person->setItem(row,0, new QTableWidgetItem(QString::number(currentPerson.getId())));
        ui->table_person->setItem(row,1, new QTableWidgetItem(name));
        ui->table_person->setItem(row,2, new QTableWidgetItem(dBirth));
        ui->table_person->setItem(row,3, new QTableWidgetItem(dDeath));
    }

        displayedPersons = persons;
}

void MainWindow::displayAllComputers(){
    listComputer.readFile("", "", "", 1, dbMain.readDb(), 1);
    vector<computer> computers = listComputer.getFullList();
    displayComputers(computers);
}

void MainWindow::displayComputers(vector<computer> computers){
    ui->table_computer->clearContents();
    ui->table_computer->setRowCount(computers.size());

    for(unsigned int row = 0; row < computers.size(); row++){
        computer currentComputer = computers[row];

        QString name = QString::fromStdString(currentComputer.getName());
        QString type = QString::fromStdString(currentComputer.getType());
        ui->table_computer->setItem(row, 0, new QTableWidgetItem(QString::number(currentComputer.getId())));
        ui->table_computer->setItem(row, 1, new QTableWidgetItem(name));
        ui->table_computer->setItem(row, 2, new QTableWidgetItem(QString::number(currentComputer.getYearBuilt())));
        ui->table_computer->setItem(row, 3, new QTableWidgetItem(type));
    }
    displayedComputers = computers;
}

void MainWindow::on_table_person_itemSelectionChanged(){
    if(!personDeleted && !personEdited){
        int selectedPersonIndex = ui->table_person->currentIndex().row();
        person selectedPerson = displayedPersons[selectedPersonIndex];
        prel selectedPersonRelations = listPerson.getRel(selectedPerson.getId(),dbMain.readDb());



        QImage image;




        image.loadFromData(selectedPerson.getPic());
        image = image.scaledToWidth(ui->person_profilepic->width(), Qt::SmoothTransformation);
        ui->person_profilepic->setPixmap(QPixmap::fromImage(image));

        listPerson.editPerson(selectedPerson.getId(), selectedPerson, dbMain.readDb());


        ui->person_name->setEnabled(false);
        ui->person_gender->setEnabled(false);
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


void MainWindow::on_add_person_confirm_clicked(){
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
    newPerson.setGender(gender);
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


void MainWindow::on_button_delete_person_clicked(){
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

void MainWindow::on_button_edit_person_clicked(){
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

        //person SelectedPerson = displayedPersons.at(selectedPersonIndex);

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


        QString personId = ui->label_person_id->text();
        listPerson.editPerson(personId.split(":")[1].toInt(),editedPerson,dbMain.readDb());



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

void MainWindow::on_button_person_search_update_clicked(){
    string input = ui->search_person->text().toStdString();
    string ageRange = ui->person_age_line_edit->text().toStdString();

    if(!validateAgeString(ageRange)){
        ageRange = "";
    }
    bool asc = true;
    string gender = "";
    if(ui->person_order_combo->currentText()== "Descending"){
        asc = false;
    }
    if(ui->person_gender_combo->currentText() == "Male"){
        gender = "Male";
    }
    else if(ui->person_gender_combo->currentText() == "Female"){
        gender = "Female";
    }
    if(ui->person_orderBy_combo->currentText() == "Id"){
        listPerson.readFile(input, gender, ageRange, dbMain.readDb(), asc);
    }
    else if(ui->person_orderBy_combo->currentText() == "Name"){
        listPerson.readFileAlpha(input, gender, ageRange,dbMain.readDb(), asc);
    }
    else if(ui->person_orderBy_combo->currentText() == "Date birth"){
        listPerson.readFileYearBorn(input, gender, ageRange,dbMain.readDb(), asc);
    }

    vector<person> persons = listPerson.getFullList();
    displayPersons(persons);
}


void MainWindow::on_button_computer_search_update_clicked(){
    string input = ui->search_computer->text().toStdString();
    string ageRange = ui->computer_yearBuilt_line_edit->text().toStdString();
    string type = "";
    bool asc = true, built = true;
    if(!validateAgeString(ageRange)){
        ageRange = "";
    }
    if(ui->computer_order_combo->currentText() == "Descending"){
        asc = false;
    }
    if(!ui->computer_wasBuilt_checkBox->isChecked()){
        built = false;
    }
    if(ui->computer_type_combo->currentText() != "all"){
        type = ui->computer_type_combo->currentText().toStdString();
    }
    if(ui->computer_orderBy_combo->currentText() == "Id"){
        listComputer.readFile(input, ageRange, type, built, dbMain.readDb(), asc);
    }
    else if(ui->computer_orderBy_combo->currentText() == "Name"){
        listComputer.readFileAlpha(input, ageRange, type, built, dbMain.readDb(), asc);
    }
    else if(ui->computer_orderBy_combo->currentText() == "Year built"){
        listComputer.readFileAge(input, ageRange, type, built, dbMain.readDb(), asc);
    }
    else if(ui->computer_orderBy_combo->currentText() == "Weight"){
        listComputer.readFileWeight(input, ageRange, type, built, dbMain.readDb(), asc);
    }

    vector<computer> computers = listComputer.getFullList();
    displayComputers(computers);
}

void MainWindow::on_add_computer_confirm_clicked()
{
    string type;
    bool errorFound = false;

    ui->label_computer_name_error_code->setText("");
    ui->label_yearBuilt_error_code->setText("");
    ui->label_weight_error_code->setText("");

    type = ui->computer_type_add_Combo->currentText().toStdString();

    QString name = ui->line_computer_name->text();
    QString yearBuilt = ui->line_computer_yearBuilt->text();
    QString weight = ui->line_computer_weight->text();

    computer newComputer;

    if(name.isEmpty()){
        ui->label_computer_name_error_code->setText("<div style='color:rgb(255,0,0)'>Field can't be empty</div>");
        errorFound = true;
    }
    newComputer.setName(name.toStdString());

    newComputer.setYearBuilt(yearBuilt.toInt());
    if(!newComputer.isYearBuiltValid()){
        ui->label_yearBuilt_error_code->setText("<div style='color:rgb(255,0,0)'>Year built needs to be between 1600-2015</div>");
        errorFound = true;
    }

    if(weight.isEmpty()){
        ui->label_date_death_error_code->setText("<div style='color:rgb(255,0,0)'>Field can't be empty</div>");
        errorFound = true;
    }
    newComputer.setWeight(weight.toDouble());
    newComputer.setType(type);
    if(errorFound)
        return;

    listComputer.addComputer(dbMain.readDb(), newComputer);

    ui->search_computer->setText("");
    displayAllComputers();

    ui->statusBar->showMessage("Successfully added computer", 1500);
}

void MainWindow::on_table_computer_itemSelectionChanged(){
    if(!computerDeleted && !computerEdited){
        int selectedComputerIndex = ui->table_computer->currentIndex().row();
        computer selectedComputer = displayedComputers[selectedComputerIndex];
        crel selectedComputerRelations = listComputer.getRel(selectedComputer.getId(),dbMain.readDb());
        string wasBuilt ;
        if(selectedComputer.wasBuilt()){
            wasBuilt = "Yes";
        }
        else{
            wasBuilt = "No";
        }

        ui->computer_name->setEnabled(false);
        ui->computer_type->setEnabled(false);
        ui->computer_yearBuilt->setEnabled(false);
        ui->computer_weight->setEnabled(false);
        ui->button_edit_computer->setText("Edit");

        ui->button_delete_computer->setEnabled(true);
        ui->button_edit_computer->setEnabled(true);

        ui->table_computer_connections->clearContents();
        ui->table_computer_connections->setRowCount(selectedComputerRelations.pName.size());

        ui->label_computer_id->setText("Id:" + QString::number(selectedComputer.getId()));
        ui->computer_name->setText(QString::fromStdString(selectedComputer.getName()));
        ui->computer_type->setText(QString::fromStdString(selectedComputer.getType()));
        ui->computer_yearBuilt->setText(QString::number(selectedComputer.getYearBuilt()));
        ui->computer_built->setText(QString::fromStdString(wasBuilt));
        ui->computer_weight->setText(QString::number(selectedComputer.getWeight()));

        for(unsigned int row = 0; row < selectedComputerRelations.pName.size(); row++){
            QString relatedPersonId = QString::number(selectedComputerRelations.pId[row]);
            QString relatedPersonName = QString::fromStdString(selectedComputerRelations.pName[row]);

            ui->table_computer_connections->setItem(row,0, new QTableWidgetItem(relatedPersonId));
            ui->table_computer_connections->setItem(row,1, new QTableWidgetItem(relatedPersonName));
        }
    }
    else{
        computerDeleted = false;
        computerEdited = false;
    }
}

void MainWindow::on_button_person_change_profilepic_clicked(){
    if(ui->label_person_id->text() == "Id:")
        return;

    int selectedPersonIndex = ui->table_person->currentIndex().row();
    person selectedPerson = displayedPersons[selectedPersonIndex];


    QByteArray pic;
    QBuffer buffer(&pic);
    buffer.open(QIODevice::WriteOnly);

    QImage image;

    QString filename = QFileDialog::getOpenFileName(this, tr("choose"), "", tr("images(*.png *.jpg *.jpeg *.bmp)"));
            if(QString::compare(filename ,QString()) != 0){

                bool valid = image.load(filename);
                if(valid){
                    image = image.scaledToWidth(ui->person_profilepic->width(), Qt::SmoothTransformation);
                    ui->person_profilepic->setPixmap(QPixmap::fromImage(image));
                }
                else{
                //error
                }
            }



    //image.loadFromData(pic);
    image.save(&buffer, "PNG");
    selectedPerson.setPic(pic);
    listPerson.editPerson(selectedPerson.getId(), selectedPerson, dbMain.readDb());
}
