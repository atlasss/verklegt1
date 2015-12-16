#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QBuffer>
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
    void on_table_person_itemSelectionChanged();
    void on_add_person_confirm_clicked();
    void on_button_delete_person_clicked();
    void on_button_edit_person_clicked();
    void on_button_person_search_update_clicked();
    void on_button_computer_search_update_clicked();
    void on_add_computer_confirm_clicked();
    void on_table_computer_itemSelectionChanged();
    void on_button_person_change_profilepic_clicked();
    void on_button_delete_computer_clicked();
    void on_button_edit_computer_clicked();
    void on_button_add_connection_person_clicked();
    void on_button_remove_connection_person_clicked();
    void on_button_add_connection_computer_clicked();
    void on_button_remove_connection_computer_clicked();
    void on_button_computer_change_profilepic_clicked();

private:
    Ui::MainWindow *ui;
    dataAccess dbMain;
    computerlist listComputer;
    personlist listPerson;

    bool personEdited;
    bool personDeleted;

    bool computerEdited;
    bool computerDeleted;

    bool validateAgeString(string a);

    void displayAllPersons();
    void displayPersons(vector<person> persons);

    void displayAllComputers();
    void displayComputers(vector<computer> computers);

    vector<person> displayedPersons;
    vector<computer> displayedComputers;

};

#endif // MAINWINDOW_H
