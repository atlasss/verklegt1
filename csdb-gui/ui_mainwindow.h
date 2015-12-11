/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tab_view_chocie;
    QWidget *tab_person;
    QTabWidget *person_details;
    QWidget *person_profile;
    QGroupBox *groupBox;
    QTextEdit *person_known_for;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *person_name;
    QLineEdit *person_age;
    QLabel *label_3;
    QLineEdit *person_birth;
    QLabel *label_4;
    QLineEdit *person_death;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *button_delete;
    QPushButton *button_edit;
    QWidget *person_connections;
    QTableWidget *table_person_connections;
    QTableWidget *table_person;
    QLineEdit *search_person;
    QPushButton *add_person;
    QWidget *tab_computer;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(882, 491);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tab_view_chocie = new QTabWidget(centralWidget);
        tab_view_chocie->setObjectName(QStringLiteral("tab_view_chocie"));
        tab_view_chocie->setGeometry(QRect(0, 10, 831, 411));
        tab_person = new QWidget();
        tab_person->setObjectName(QStringLiteral("tab_person"));
        person_details = new QTabWidget(tab_person);
        person_details->setObjectName(QStringLiteral("person_details"));
        person_details->setGeometry(QRect(20, 150, 301, 231));
        person_profile = new QWidget();
        person_profile->setObjectName(QStringLiteral("person_profile"));
        groupBox = new QGroupBox(person_profile);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(90, 0, 201, 181));
        person_known_for = new QTextEdit(groupBox);
        person_known_for->setObjectName(QStringLiteral("person_known_for"));
        person_known_for->setEnabled(false);
        person_known_for->setGeometry(QRect(30, 120, 161, 51));
        person_known_for->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhMultiLine);
        person_known_for->setTextInteractionFlags(Qt::NoTextInteraction);
        formLayoutWidget = new QWidget(groupBox);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 10, 181, 100));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        person_name = new QLineEdit(formLayoutWidget);
        person_name->setObjectName(QStringLiteral("person_name"));
        person_name->setEnabled(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, person_name);

        person_age = new QLineEdit(formLayoutWidget);
        person_age->setObjectName(QStringLiteral("person_age"));
        person_age->setEnabled(false);

        formLayout->setWidget(1, QFormLayout::FieldRole, person_age);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        person_birth = new QLineEdit(formLayoutWidget);
        person_birth->setObjectName(QStringLiteral("person_birth"));
        person_birth->setEnabled(false);

        formLayout->setWidget(2, QFormLayout::FieldRole, person_birth);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        person_death = new QLineEdit(formLayoutWidget);
        person_death->setObjectName(QStringLiteral("person_death"));
        person_death->setEnabled(false);
        person_death->setFrame(true);

        formLayout->setWidget(3, QFormLayout::FieldRole, person_death);

        gridLayoutWidget = new QWidget(person_profile);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(110, 180, 161, 25));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        button_delete = new QPushButton(gridLayoutWidget);
        button_delete->setObjectName(QStringLiteral("button_delete"));

        gridLayout->addWidget(button_delete, 0, 0, 1, 1);

        button_edit = new QPushButton(gridLayoutWidget);
        button_edit->setObjectName(QStringLiteral("button_edit"));

        gridLayout->addWidget(button_edit, 0, 1, 1, 1);

        person_details->addTab(person_profile, QString());
        person_connections = new QWidget();
        person_connections->setObjectName(QStringLiteral("person_connections"));
        table_person_connections = new QTableWidget(person_connections);
        if (table_person_connections->columnCount() < 2)
            table_person_connections->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_person_connections->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_person_connections->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        table_person_connections->setObjectName(QStringLiteral("table_person_connections"));
        table_person_connections->setEnabled(true);
        table_person_connections->setGeometry(QRect(10, 10, 256, 151));
        person_details->addTab(person_connections, QString());
        table_person = new QTableWidget(tab_person);
        if (table_person->columnCount() < 4)
            table_person->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_person->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_person->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table_person->setHorizontalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table_person->setHorizontalHeaderItem(3, __qtablewidgetitem5);
        table_person->setObjectName(QStringLiteral("table_person"));
        table_person->setGeometry(QRect(370, 10, 449, 371));
        table_person->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        table_person->setSortingEnabled(true);
        search_person = new QLineEdit(tab_person);
        search_person->setObjectName(QStringLiteral("search_person"));
        search_person->setGeometry(QRect(10, 10, 171, 20));
        add_person = new QPushButton(tab_person);
        add_person->setObjectName(QStringLiteral("add_person"));
        add_person->setGeometry(QRect(10, 90, 75, 23));
        add_person->setCheckable(false);
        add_person->setAutoDefault(false);
        add_person->setFlat(false);
        tab_view_chocie->addTab(tab_person, QString());
        person_details->raise();
        search_person->raise();
        table_person->raise();
        add_person->raise();
        tab_computer = new QWidget();
        tab_computer->setObjectName(QStringLiteral("tab_computer"));
        tab_view_chocie->addTab(tab_computer, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 882, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tab_view_chocie->setCurrentIndex(0);
        person_details->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "csdb", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Information", 0));
        label->setText(QApplication::translate("MainWindow", "Name", 0));
        label_2->setText(QApplication::translate("MainWindow", "Age", 0));
        label_3->setText(QApplication::translate("MainWindow", "Date birth", 0));
        label_4->setText(QApplication::translate("MainWindow", "Date death", 0));
        button_delete->setText(QApplication::translate("MainWindow", "Delete", 0));
        button_edit->setText(QApplication::translate("MainWindow", "Edit", 0));
        person_details->setTabText(person_details->indexOf(person_profile), QApplication::translate("MainWindow", "Profile", 0));
        QTableWidgetItem *___qtablewidgetitem = table_person_connections->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Id", 0));
        QTableWidgetItem *___qtablewidgetitem1 = table_person_connections->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Name", 0));
        person_details->setTabText(person_details->indexOf(person_connections), QApplication::translate("MainWindow", "Connections", 0));
        QTableWidgetItem *___qtablewidgetitem2 = table_person->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Id", 0));
        QTableWidgetItem *___qtablewidgetitem3 = table_person->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem4 = table_person->horizontalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Date birth", 0));
        QTableWidgetItem *___qtablewidgetitem5 = table_person->horizontalHeaderItem(3);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Date death", 0));
        search_person->setPlaceholderText(QApplication::translate("MainWindow", "Search for person...", 0));
        add_person->setText(QApplication::translate("MainWindow", "Add", 0));
        tab_view_chocie->setTabText(tab_view_chocie->indexOf(tab_person), QApplication::translate("MainWindow", "Person", 0));
        tab_view_chocie->setTabText(tab_view_chocie->indexOf(tab_computer), QApplication::translate("MainWindow", "Computer", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
