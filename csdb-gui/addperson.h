#ifndef ADDPERSON_H
#define ADDPERSON_H

#include <QDialog>
#include "personlist.h"

namespace Ui {
class addPerson;
}

class addPerson : public QDialog
{
    Q_OBJECT

public:
    explicit addPerson(QWidget *parent = 0);
    ~addPerson();

private slots:
    void on_add_person_confirm_clicked();

private:
    Ui::addPerson *ui;
    personlist listPersons;
};

#endif // ADDPERSON_H
