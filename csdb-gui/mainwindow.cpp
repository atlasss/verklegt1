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

    QDoubleValidator* validator = new QDoubleValidator(this);

    dbMain.open();
    ui->setupUi(this);
    ui->computer_yearBuilt->setValidator(validator);
    ui->table_person->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->table_person_connections->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->table_computer->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->table_computer_connections->setEditTriggers(QAbstractItemView::NoEditTriggers);


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
        if(currentComputer.wasBuilt())
            ui->table_computer->setItem(row, 2, new QTableWidgetItem(QString::number(currentComputer.getYearBuilt())));
        else
            ui->table_computer->setItem(row, 2, new QTableWidgetItem("N/A"));
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
        if(!selectedPerson.getPic().isEmpty() && selectedPerson.getPic().toInt() != -1){
            image = image.scaledToWidth(ui->person_profilepic->width(), Qt::SmoothTransformation);
            ui->person_profilepic->setPixmap(QPixmap::fromImage(image));
        }
        else{
            ui->person_profilepic->clear();
            ui->person_profilepic->setText("Missing");
        }
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

    if(listPerson.addPerson(dbMain.readDb(), newPerson)){
        ui->search_person->setText("");
        displayAllPersons();
        ui->line_person_name->setText("");
        ui->line_person_date_birth->setText("");
        ui->line_person_date_death->setText("");
        ui->text_person_known_for->setText("");
        ui->statusBar->showMessage("Successfully added person", 1500);
    }
    else
        ui->statusBar->showMessage("Person was not added to database", 1500);

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
        person SelectedPerson = displayedPersons.at(selectedPersonIndex);

        person editedPerson;

        editedPerson.setPic(SelectedPerson.getPic());

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

        ui->search_person->setText("");
        displayAllPersons();

        ui->table_person->selectRow(selectedPersonIndex);
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
    bool asc = true;
    int built = 0;
    if(!validateAgeString(ageRange)){
        ageRange = "";
    }
    if(ui->computer_order_combo->currentText() == "Descending"){
        asc = false;
    }
    if(ui->computer_wasBuilt_checkBox->isChecked()){
        built = 1;
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

void MainWindow::on_add_computer_confirm_clicked(){
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
    newComputer.setId(-1);
    QByteArray q;
    newComputer.setPic(q);

    if(listComputer.addComputer(dbMain.readDb(), newComputer)){
        ui->search_computer->setText("");
        displayAllComputers();
        ui->line_computer_name->setText("");
        ui->line_computer_yearBuilt->setText("");
        ui->line_computer_weight->setText("");

        ui->statusBar->showMessage("Successfully added computer", 1500);
    }
    else
        ui->statusBar->showMessage("Computer was not added to database", 1500);

}

void MainWindow::on_table_computer_itemSelectionChanged(){
    if(!computerDeleted && !computerEdited){
        int selectedComputerIndex = ui->table_computer->currentIndex().row();
        computer selectedComputer = displayedComputers[selectedComputerIndex];
        crel selectedComputerRelations = listComputer.getRel(selectedComputer.getId(),dbMain.readDb());
        string wasBuilt = "No";
        if(selectedComputer.wasBuilt()){
            wasBuilt = "Yes";
        }

        QImage image;
        image.loadFromData(selectedComputer.getPic());
        if(!selectedComputer.getPic().isEmpty() && selectedComputer.getPic().toInt() != -1){
            image = image.scaledToWidth(ui->computer_profilepic->width(), Qt::SmoothTransformation);
            ui->computer_profilepic->setPixmap(QPixmap::fromImage(image));
        }
        else{
            ui->computer_profilepic->clear();
            ui->computer_profilepic->setText("Missing");
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
        if(wasBuilt == "Yes")
            ui->computer_yearBuilt->setText(QString::number(selectedComputer.getYearBuilt()));
        else
            ui->computer_yearBuilt->setText("N/A");
        ui->computer_built->setText(QString::fromStdString(wasBuilt));
        if(selectedComputer.getWeight() < 0)
            ui->computer_weight->setText("Unkown");
        else
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
                    //ui->person_profilepic->setPixmap(QPixmap::fromImage(image));
                }
                else{
                    QMessageBox::information(this,"Error", "Profile pic not updated");
                    return;
                }
            }

    image.save(&buffer, "PNG");
    selectedPerson.setPic(pic);
    selectedPerson.isDateBirthValid();
    listPerson.editPerson(selectedPerson.getId(), selectedPerson, dbMain.readDb());
    ui->person_profilepic->setPixmap(QPixmap::fromImage(image));
    displayedPersons[selectedPersonIndex].setPic(pic);
}

void MainWindow::on_button_delete_computer_clicked(){
    int selectedComputerIndex = ui->table_computer->currentIndex().row();
    computer selectedComputer = displayedComputers[selectedComputerIndex];
    int confirm = QMessageBox::question(this, "Confirm", "Are you sure you want to delete this computer?");

    if (confirm == QMessageBox::No){
        return;
    }


    ui->button_delete_computer->setEnabled(false);
    ui->button_edit_computer->setEnabled(false);
    ui->table_computer_connections->clearContents();

    ui->label_computer_id->setText("Id:");
    ui->computer_name->setText("");
    ui->computer_type->setText("");
    ui->computer_yearBuilt->setText("");
    ui->computer_built->setText("");
    ui->computer_weight->setText("");

    ui->computer_name->setEnabled(false);
    ui->computer_type->setEnabled(false);
    ui->computer_yearBuilt->setEnabled(false);
    ui->computer_weight->setEnabled(false);

    listComputer.deleteComputer(selectedComputer.getId(),dbMain.readDb());
    ui->search_computer->setText("");
    computerDeleted = true;
    displayAllComputers();
}

void MainWindow::on_button_edit_computer_clicked(){
    if(ui->button_edit_computer->text() == "Edit"){
        ui->computer_name->setEnabled(true);
        ui->computer_type->setEnabled(true);
        ui->computer_yearBuilt->setEnabled(true);
        ui->computer_weight->setEnabled(true);

        ui->button_edit_computer->setText("Save changes");
    }
    else if(ui->button_edit_computer->text() == "Save changes"){
        bool errorFound = false;
        QString name = ui->computer_name->text();
        QString type = ui->computer_type->text();
        QString yearBuilt = ui->computer_yearBuilt->text();
        QString weight = ui->computer_weight->text();

        int selectedComputerIndex = ui->table_computer->currentIndex().row();
        computer selectedComputer = displayedComputers[selectedComputerIndex];
        computer editedComputer;

        QString errorMessage = "";

        if(name.isEmpty()){
            errorMessage.append("<div style='color:rgb(255,0,0)'>Name field can't be empty</>\n");
            errorFound = true;
        }
        editedComputer.setName(name.toStdString());

        editedComputer.setType(type.toStdString());
        if(!editedComputer.isTypeValid()){
            errorMessage.append("<div style='color:rgb(255,0,0)'>Type needs to be electromechanical, mechanical, transistor or electronic</>\n");
            errorFound = true;
        }

        editedComputer.setYearBuilt(yearBuilt.toInt());
        if(!editedComputer.isYearBuiltValid()){
            errorMessage.append("<div style='color:rgb(255,0,0)'>Year built needs to be an integer between 1600 and 2015 (or -1 if the computer wasn't built')</>\n");
            errorFound = true;
        }

        editedComputer.setWeight(weight.toDouble());
        editedComputer.setPic(selectedComputer.getPic());
        if(errorFound){
            QMessageBox::information(this,"Error editing computer",errorMessage);
            return;
        }


        QString computerId = ui->label_computer_id->text();
        listComputer.editComputer(computerId.split(":")[1].toInt(),editedComputer,dbMain.readDb());

        ui->button_edit_computer->setText("Edit");
        ui->computer_name->setEnabled(false);
        ui->computer_type->setEnabled(false);
        ui->computer_yearBuilt->setEnabled(false);
        ui->computer_weight->setEnabled(false);

        ui->computer_name->setText(QString::fromStdString(editedComputer.getName()));
        ui->computer_type->setText(QString::fromStdString(editedComputer.getType()));
        if(editedComputer.wasBuilt()){
            ui->computer_yearBuilt->setText(QString::number(editedComputer.getYearBuilt()));
            ui->computer_built->setText("Yes");
        }

        else {
            ui->computer_yearBuilt->setText("N/A");
            ui->computer_built->setText("No");
        }

        if(editedComputer.getWeight() < 0)
            ui->computer_weight->setText("Unkown");
        else
            ui->computer_weight->setText(QString::number(editedComputer.getWeight()));

        computerEdited = true;

        ui->search_computer->setText("");
        displayAllComputers();
        ui->table_computer->selectRow(selectedComputerIndex);
    }
}

void MainWindow::on_button_add_connection_person_clicked(){
    int personId = ui->label_person_id->text().split(":")[1].toInt();
    int computerId = ui->person_relation_line->text().toInt();

    if(listComputer.idExists(computerId) && ui->table_person->currentIndex().isValid()){
        listPerson.addRel(personId,computerId,dbMain.readDb());
        ui->statusBar->showMessage("Connection created", 1500);
    }
    else{
        ui->statusBar->showMessage("Id not found", 1500);
    }
}

void MainWindow::on_button_remove_connection_person_clicked(){
    if (ui->table_person_connections->currentIndex().isValid()) {
        int currentRow = ui->table_person_connections->currentIndex().row();
        int personId = ui->label_person_id->text().split(":")[1].toInt();
        int computerId = ui->table_person_connections->item(currentRow,0)->data(0).toInt();
        listPerson.removeRel(personId, computerId, dbMain.readDb());

        int selectedPersonIndex = ui->table_person->currentIndex().row();
        person selectedPerson = displayedPersons[selectedPersonIndex];
        prel selectedPersonRelations = listPerson.getRel(selectedPerson.getId(),dbMain.readDb());

        ui->table_person_connections->clearContents();
        for(unsigned int row = 0; row < selectedPersonRelations.cName.size(); row++){
            QString relatedComputerId = QString::number(selectedPersonRelations.cId[row]);
            QString relatedComputerName = QString::fromStdString(selectedPersonRelations.cName[row]);

            ui->table_person_connections->setItem(row,0, new QTableWidgetItem(relatedComputerId));
            ui->table_person_connections->setItem(row,1, new QTableWidgetItem(relatedComputerName));
        }
        ui->statusBar->showMessage("Connection removed", 1500);
    }

    else
        return;

}

void MainWindow::on_button_add_connection_computer_clicked(){
    int computerId = ui->label_computer_id->text().split(":")[1].toInt();
    int personId = ui->computer_relation_line->text().toInt();

    if(listPerson.idExists(personId) && ui->table_computer->currentIndex().isValid()){
        listPerson.addRel(personId,computerId,dbMain.readDb());
        ui->statusBar->showMessage("Connection created", 1500);
    }
    else{
        ui->statusBar->showMessage("Id not found", 1500);
    }
}

void MainWindow::on_button_remove_connection_computer_clicked(){
    if (ui->table_computer_connections->currentIndex().isValid()) {
        int currentRow = ui->table_computer_connections->currentIndex().row();
        int computerId = ui->label_computer_id->text().split(":")[1].toInt();
        int personId = ui->table_computer_connections->item(currentRow,0)->data(0).toInt();
        listPerson.removeRel(personId, computerId, dbMain.readDb());

        int selectedComputerIndex = ui->table_computer->currentIndex().row();
        computer selectedComputer = displayedComputers[selectedComputerIndex];
        crel selectedComputerRelations = listComputer.getRel(selectedComputer.getId(),dbMain.readDb());

        ui->table_computer_connections->clearContents();
        for(unsigned int row = 0; row < selectedComputerRelations.pName.size(); row++){
            QString relatedPersonId = QString::number(selectedComputerRelations.pId[row]);
            QString relatedPersonName = QString::fromStdString(selectedComputerRelations.pName[row]);

            ui->table_computer_connections->setItem(row,0, new QTableWidgetItem(relatedPersonId));
            ui->table_computer_connections->setItem(row,1, new QTableWidgetItem(relatedPersonName));
        }
        ui->statusBar->showMessage("Connection removed", 1500);
    }

    else{
        return;
    }
}

void MainWindow::on_button_computer_change_profilepic_clicked(){
    if(ui->label_computer_id->text() == "Id:")
        return;

    int selectedComputerIndex = ui->table_computer->currentIndex().row();
    computer selectedComputer = displayedComputers[selectedComputerIndex];


    QByteArray pic;
    QBuffer buffer(&pic);
    buffer.open(QIODevice::WriteOnly);

    QImage image;

    QString filename = QFileDialog::getOpenFileName(this, tr("choose"), "", tr("images(*.png *.jpg *.jpeg *.bmp)"));
            if(QString::compare(filename ,QString()) != 0){

                bool valid = image.load(filename);
                if(valid){
                     image = image.scaledToWidth(ui->person_profilepic->width(), Qt::SmoothTransformation);
                    //ui->person_profilepic->setPixmap(QPixmap::fromImage(image));
                }
                else{
                    QMessageBox::information(this,"Error", "Profile pic not updated");
                    return;
                }
            }

    image.save(&buffer, "PNG");
    selectedComputer.setPic(pic);
    selectedComputer.isYearBuiltValid();
    listComputer.editComputer(selectedComputer.getId(), selectedComputer, dbMain.readDb());
    ui->computer_profilepic->setPixmap(QPixmap::fromImage(image));
    displayedComputers[selectedComputerIndex].setPic(pic);
}
