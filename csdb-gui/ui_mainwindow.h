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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tab_view_chocie;
    QWidget *tab_person;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QTableWidget *table_person;
    QPlainTextEdit *search_person;
    QTabWidget *person_details;
    QWidget *person_profile;
    QWidget *person_connections;
    QWidget *tab_computer;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(699, 465);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tab_view_chocie = new QTabWidget(centralWidget);
        tab_view_chocie->setObjectName(QStringLiteral("tab_view_chocie"));
        tab_view_chocie->setGeometry(QRect(10, 10, 651, 401));
        tab_person = new QWidget();
        tab_person->setObjectName(QStringLiteral("tab_person"));
        horizontalLayoutWidget = new QWidget(tab_person);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(340, 10, 291, 351));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        table_person = new QTableWidget(horizontalLayoutWidget);
        if (table_person->columnCount() < 3)
            table_person->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_person->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_person->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_person->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        table_person->setObjectName(QStringLiteral("table_person"));
        table_person->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout->addWidget(table_person);

        search_person = new QPlainTextEdit(tab_person);
        search_person->setObjectName(QStringLiteral("search_person"));
        search_person->setGeometry(QRect(10, 20, 171, 21));
        search_person->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        search_person->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        person_details = new QTabWidget(tab_person);
        person_details->setObjectName(QStringLiteral("person_details"));
        person_details->setGeometry(QRect(20, 180, 291, 191));
        person_profile = new QWidget();
        person_profile->setObjectName(QStringLiteral("person_profile"));
        person_details->addTab(person_profile, QString());
        person_connections = new QWidget();
        person_connections->setObjectName(QStringLiteral("person_connections"));
        person_details->addTab(person_connections, QString());
        tab_view_chocie->addTab(tab_person, QString());
        tab_computer = new QWidget();
        tab_computer->setObjectName(QStringLiteral("tab_computer"));
        tab_view_chocie->addTab(tab_computer, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 699, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tab_view_chocie->setCurrentIndex(0);
        person_details->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "csdb", 0));
        QTableWidgetItem *___qtablewidgetitem = table_person->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Id", 0));
        QTableWidgetItem *___qtablewidgetitem1 = table_person->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem2 = table_person->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Age", 0));
        search_person->setPlaceholderText(QApplication::translate("MainWindow", "Search for person name...", 0));
        person_details->setTabText(person_details->indexOf(person_profile), QApplication::translate("MainWindow", "Profile", 0));
        person_details->setTabText(person_details->indexOf(person_connections), QApplication::translate("MainWindow", "Connections", 0));
        tab_view_chocie->setTabText(tab_view_chocie->indexOf(tab_person), QApplication::translate("MainWindow", "Person", 0));
        tab_view_chocie->setTabText(tab_view_chocie->indexOf(tab_computer), QApplication::translate("MainWindow", "Computer", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
