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
    void on_search_person_textChanged(const QString &arg1);
    void on_table_person_itemSelectionChanged();
    void on_add_person_confirm_clicked();

    void on_button_delete_person_clicked();

    void on_button_edit_person_clicked();

private:
    Ui::MainWindow *ui;
    dataAccess dbMain;
    computerlist listComputer;
    personlist listPerson;

    bool personEdited;
    bool personDeleted;
    void displayAllPersons();
    void displayPersons(vector<person> persons);
    vector<person> displayedPersons;

};

#endif // MAINWINDOW_H
