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
    void on_table_person_itemSelectionChanged();
    void on_add_person_confirm_clicked();

    void on_button_delete_person_clicked();

    void on_button_edit_person_clicked();

    void on_button_person_search_update_clicked();

private:
    Ui::MainWindow *ui;
    dataAccess dbMain;
    computerlist listComputer;
    personlist listPerson;

    bool personEdited;
    bool personDeleted;

    bool validateAgeString(string a);

    void displayAllPersons();
    void displayPersons(vector<person> persons);

    void displayAllComputers();
    void displayComputer(vector<computer> computers);

    vector<person> displayedPersons;
    vector<computer> displayedComputers;

};

#endif // MAINWINDOW_H
