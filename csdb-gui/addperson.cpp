#include "addperson.h"
#include "ui_addperson.h"

addPerson::addPerson(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addPerson)
{
    ui->setupUi(this);
}

addPerson::~addPerson()
{
    delete ui;
}

void addPerson::on_add_person_confirm_clicked()
{

}
