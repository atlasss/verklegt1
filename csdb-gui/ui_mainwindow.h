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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tab_view_chocie;
    QWidget *tab_person;
    QTableWidget *table_person;
    QTabWidget *tabWidget;
    QWidget *person_tab_search;
    QTabWidget *person_details;
    QWidget *person_profile;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *button_delete_person;
    QPushButton *button_edit_person;
    QTextEdit *person_known_for;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_person_id;
    QLabel *label;
    QLineEdit *person_name;
    QLabel *label_2;
    QLineEdit *person_age;
    QLabel *label_3;
    QLineEdit *person_birth;
    QLabel *label_4;
    QLineEdit *person_death;
    QLabel *label_5;
    QLineEdit *person_gender;
    QPushButton *button_person_change_profilepic;
    QLabel *person_profilepic;
    QWidget *person_connections;
    QTableWidget *table_person_connections;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayout_5;
    QPushButton *button_remove_connection_person;
    QGridLayout *gridLayout_4;
    QLabel *label_10;
    QPushButton *button_add_connection_person;
    QLineEdit *lineEdit;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QLineEdit *search_person;
    QGridLayout *gridLayout_2;
    QComboBox *person_order_combo;
    QComboBox *person_gender_combo;
    QLabel *label_6;
    QLabel *label_8;
    QLineEdit *person_age_line_edit;
    QLabel *label_7;
    QComboBox *person_orderBy_combo;
    QLabel *label_9;
    QPushButton *button_person_search_update;
    QWidget *tab_3;
    QWidget *formLayoutWidget_2;
    QFormLayout *person_form;
    QFormLayout *formLayout_15;
    QLabel *label_15;
    QLabel *label_name_error_code;
    QLineEdit *line_person_name;
    QFormLayout *formLayout_16;
    QLabel *label_16;
    QRadioButton *radio_male;
    QRadioButton *radio_female;
    QFormLayout *formLayout_17;
    QLabel *label_17;
    QLabel *label_date_birth_error_code;
    QLineEdit *line_person_date_birth;
    QLineEdit *line_person_date_death;
    QFormLayout *formLayout_18;
    QLabel *label_18;
    QLabel *label_known_for_error_code;
    QTextEdit *text_person_known_for;
    QPushButton *add_person_confirm;
    QFormLayout *formLayout_19;
    QLabel *label_19;
    QLabel *label_date_death_error_code;
    QWidget *tab_computer;
    QTableWidget *table_computer;
    QTabWidget *tabWidget_2;
    QWidget *tab;
    QWidget *gridLayoutWidget_6;
    QGridLayout *gridLayout_6;
    QLineEdit *search_computer;
    QGridLayout *gridLayout_7;
    QComboBox *computer_order_combo;
    QComboBox *computer_type_combo;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *computer_yearBuilt_line_edit;
    QLabel *label_13;
    QComboBox *computer_orderBy_combo;
    QLabel *label_14;
    QCheckBox *computer_wasBuilt_checkBox;
    QPushButton *button_computer_search_update;
    QTabWidget *computer_details;
    QWidget *computer_profile;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_8;
    QPushButton *button_delete_computer;
    QPushButton *button_edit_computer;
    QWidget *formLayoutWidget_4;
    QFormLayout *formLayout_2;
    QLabel *label_computer_id;
    QLabel *label_23;
    QLineEdit *computer_name;
    QLabel *label_25;
    QLineEdit *computer_yearBuilt;
    QLabel *label_26;
    QLineEdit *computer_built;
    QLabel *label_27;
    QLineEdit *computer_weight;
    QLabel *label_28;
    QLineEdit *computer_type;
    QWidget *computer_connections_tab;
    QTableWidget *table_computer_connections;
    QWidget *gridLayoutWidget_7;
    QGridLayout *gridLayout_9;
    QPushButton *button_remove_connection_computer;
    QGridLayout *gridLayout_10;
    QLabel *label_29;
    QPushButton *button_add_connection_computer;
    QLineEdit *lineEdit_2;
    QWidget *tab_2;
    QWidget *formLayoutWidget_3;
    QFormLayout *person_form_2;
    QFormLayout *formLayout_20;
    QLabel *label_20;
    QLabel *label_computer_name_error_code;
    QLineEdit *line_computer_name;
    QLabel *label_21;
    QComboBox *computer_type_add_Combo;
    QFormLayout *formLayout_22;
    QLabel *label_22;
    QLabel *label_yearBuilt_error_code;
    QLineEdit *line_computer_yearBuilt;
    QFormLayout *formLayout_24;
    QLabel *label_24;
    QLabel *label_weight_error_code;
    QLineEdit *line_computer_weight;
    QPushButton *add_computer_confirm;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(828, 600);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tab_view_chocie = new QTabWidget(centralWidget);
        tab_view_chocie->setObjectName(QStringLiteral("tab_view_chocie"));
        tab_view_chocie->setGeometry(QRect(0, 0, 811, 541));
        tab_person = new QWidget();
        tab_person->setObjectName(QStringLiteral("tab_person"));
        table_person = new QTableWidget(tab_person);
        if (table_person->columnCount() < 4)
            table_person->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_person->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_person->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_person->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_person->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        table_person->setObjectName(QStringLiteral("table_person"));
        table_person->setEnabled(true);
        table_person->setGeometry(QRect(390, 20, 411, 481));
        table_person->setAutoFillBackground(true);
        table_person->setFrameShape(QFrame::StyledPanel);
        table_person->setFrameShadow(QFrame::Plain);
        table_person->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        table_person->setShowGrid(true);
        table_person->setSortingEnabled(false);
        table_person->setRowCount(0);
        table_person->verticalHeader()->setVisible(false);
        table_person->verticalHeader()->setStretchLastSection(false);
        tabWidget = new QTabWidget(tab_person);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(-2, 0, 371, 511));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideLeft);
        tabWidget->setDocumentMode(true);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(true);
        person_tab_search = new QWidget();
        person_tab_search->setObjectName(QStringLiteral("person_tab_search"));
        person_details = new QTabWidget(person_tab_search);
        person_details->setObjectName(QStringLiteral("person_details"));
        person_details->setGeometry(QRect(10, 170, 361, 311));
        person_details->setAutoFillBackground(false);
        person_details->setTabShape(QTabWidget::Rounded);
        person_details->setDocumentMode(false);
        person_details->setMovable(true);
        person_profile = new QWidget();
        person_profile->setObjectName(QStringLiteral("person_profile"));
        verticalLayoutWidget = new QWidget(person_profile);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(130, 10, 211, 271));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(verticalLayoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 230, 181, 31));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        button_delete_person = new QPushButton(gridLayoutWidget);
        button_delete_person->setObjectName(QStringLiteral("button_delete_person"));
        button_delete_person->setEnabled(false);

        gridLayout->addWidget(button_delete_person, 0, 0, 1, 1);

        button_edit_person = new QPushButton(gridLayoutWidget);
        button_edit_person->setObjectName(QStringLiteral("button_edit_person"));
        button_edit_person->setEnabled(false);

        gridLayout->addWidget(button_edit_person, 0, 1, 1, 1);

        person_known_for = new QTextEdit(groupBox);
        person_known_for->setObjectName(QStringLiteral("person_known_for"));
        person_known_for->setEnabled(false);
        person_known_for->setGeometry(QRect(10, 180, 181, 41));
        person_known_for->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhMultiLine);
        person_known_for->setTextInteractionFlags(Qt::TextEditorInteraction);
        formLayoutWidget = new QWidget(groupBox);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 20, 181, 151));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_person_id = new QLabel(formLayoutWidget);
        label_person_id->setObjectName(QStringLiteral("label_person_id"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_person_id);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label);

        person_name = new QLineEdit(formLayoutWidget);
        person_name->setObjectName(QStringLiteral("person_name"));
        person_name->setEnabled(false);

        formLayout->setWidget(2, QFormLayout::FieldRole, person_name);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_2);

        person_age = new QLineEdit(formLayoutWidget);
        person_age->setObjectName(QStringLiteral("person_age"));
        person_age->setEnabled(false);

        formLayout->setWidget(4, QFormLayout::FieldRole, person_age);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_3);

        person_birth = new QLineEdit(formLayoutWidget);
        person_birth->setObjectName(QStringLiteral("person_birth"));
        person_birth->setEnabled(false);
        person_birth->setInputMethodHints(Qt::ImhNone);

        formLayout->setWidget(5, QFormLayout::FieldRole, person_birth);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_4);

        person_death = new QLineEdit(formLayoutWidget);
        person_death->setObjectName(QStringLiteral("person_death"));
        person_death->setEnabled(false);
        person_death->setFrame(true);

        formLayout->setWidget(6, QFormLayout::FieldRole, person_death);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);

        person_gender = new QLineEdit(formLayoutWidget);
        person_gender->setObjectName(QStringLiteral("person_gender"));
        person_gender->setEnabled(false);

        formLayout->setWidget(3, QFormLayout::FieldRole, person_gender);


        verticalLayout->addWidget(groupBox);

        button_person_change_profilepic = new QPushButton(person_profile);
        button_person_change_profilepic->setObjectName(QStringLiteral("button_person_change_profilepic"));
        button_person_change_profilepic->setGeometry(QRect(20, 120, 75, 23));
        person_profilepic = new QLabel(person_profile);
        person_profilepic->setObjectName(QStringLiteral("person_profilepic"));
        person_profilepic->setGeometry(QRect(20, 20, 71, 71));
        person_details->addTab(person_profile, QString());
        person_connections = new QWidget();
        person_connections->setObjectName(QStringLiteral("person_connections"));
        table_person_connections = new QTableWidget(person_connections);
        if (table_person_connections->columnCount() < 2)
            table_person_connections->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table_person_connections->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table_person_connections->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        table_person_connections->setObjectName(QStringLiteral("table_person_connections"));
        table_person_connections->setEnabled(true);
        table_person_connections->setGeometry(QRect(10, 10, 201, 271));
        table_person_connections->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        gridLayoutWidget_5 = new QWidget(person_connections);
        gridLayoutWidget_5->setObjectName(QStringLiteral("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(220, 20, 155, 80));
        gridLayout_5 = new QGridLayout(gridLayoutWidget_5);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        button_remove_connection_person = new QPushButton(gridLayoutWidget_5);
        button_remove_connection_person->setObjectName(QStringLiteral("button_remove_connection_person"));

        gridLayout_5->addWidget(button_remove_connection_person, 1, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout_4->setContentsMargins(0, -1, 0, -1);
        label_10 = new QLabel(gridLayoutWidget_5);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_4->addWidget(label_10, 0, 1, 1, 1);

        button_add_connection_person = new QPushButton(gridLayoutWidget_5);
        button_add_connection_person->setObjectName(QStringLiteral("button_add_connection_person"));

        gridLayout_4->addWidget(button_add_connection_person, 0, 0, 1, 1);

        lineEdit = new QLineEdit(gridLayoutWidget_5);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(lineEdit, 0, 2, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 0, 0, 1, 1);

        person_details->addTab(person_connections, QString());
        gridLayoutWidget_3 = new QWidget(person_tab_search);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(10, 10, 221, 161));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        search_person = new QLineEdit(gridLayoutWidget_3);
        search_person->setObjectName(QStringLiteral("search_person"));

        gridLayout_3->addWidget(search_person, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        person_order_combo = new QComboBox(gridLayoutWidget_3);
        person_order_combo->setObjectName(QStringLiteral("person_order_combo"));

        gridLayout_2->addWidget(person_order_combo, 2, 1, 1, 1);

        person_gender_combo = new QComboBox(gridLayoutWidget_3);
        person_gender_combo->setObjectName(QStringLiteral("person_gender_combo"));

        gridLayout_2->addWidget(person_gender_combo, 1, 1, 1, 1);

        label_6 = new QLabel(gridLayoutWidget_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget_3);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_2->addWidget(label_8, 2, 0, 1, 1);

        person_age_line_edit = new QLineEdit(gridLayoutWidget_3);
        person_age_line_edit->setObjectName(QStringLiteral("person_age_line_edit"));

        gridLayout_2->addWidget(person_age_line_edit, 0, 1, 1, 1);

        label_7 = new QLabel(gridLayoutWidget_3);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 1, 0, 1, 1);

        person_orderBy_combo = new QComboBox(gridLayoutWidget_3);
        person_orderBy_combo->setObjectName(QStringLiteral("person_orderBy_combo"));

        gridLayout_2->addWidget(person_orderBy_combo, 3, 1, 1, 1);

        label_9 = new QLabel(gridLayoutWidget_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_2->addWidget(label_9, 3, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 0, 1, 1);

        button_person_search_update = new QPushButton(gridLayoutWidget_3);
        button_person_search_update->setObjectName(QStringLiteral("button_person_search_update"));

        gridLayout_3->addWidget(button_person_search_update, 0, 1, 1, 1);

        tabWidget->addTab(person_tab_search, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        formLayoutWidget_2 = new QWidget(tab_3);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(10, 10, 271, 341));
        person_form = new QFormLayout(formLayoutWidget_2);
        person_form->setSpacing(6);
        person_form->setContentsMargins(11, 11, 11, 11);
        person_form->setObjectName(QStringLiteral("person_form"));
        person_form->setContentsMargins(0, 0, 0, 0);
        formLayout_15 = new QFormLayout();
        formLayout_15->setSpacing(6);
        formLayout_15->setObjectName(QStringLiteral("formLayout_15"));
        label_15 = new QLabel(formLayoutWidget_2);
        label_15->setObjectName(QStringLiteral("label_15"));

        formLayout_15->setWidget(0, QFormLayout::LabelRole, label_15);

        label_name_error_code = new QLabel(formLayoutWidget_2);
        label_name_error_code->setObjectName(QStringLiteral("label_name_error_code"));

        formLayout_15->setWidget(0, QFormLayout::FieldRole, label_name_error_code);


        person_form->setLayout(0, QFormLayout::FieldRole, formLayout_15);

        line_person_name = new QLineEdit(formLayoutWidget_2);
        line_person_name->setObjectName(QStringLiteral("line_person_name"));

        person_form->setWidget(1, QFormLayout::FieldRole, line_person_name);

        formLayout_16 = new QFormLayout();
        formLayout_16->setSpacing(6);
        formLayout_16->setObjectName(QStringLiteral("formLayout_16"));
        label_16 = new QLabel(formLayoutWidget_2);
        label_16->setObjectName(QStringLiteral("label_16"));

        formLayout_16->setWidget(0, QFormLayout::LabelRole, label_16);

        radio_male = new QRadioButton(formLayoutWidget_2);
        radio_male->setObjectName(QStringLiteral("radio_male"));
        radio_male->setChecked(true);

        formLayout_16->setWidget(1, QFormLayout::LabelRole, radio_male);

        radio_female = new QRadioButton(formLayoutWidget_2);
        radio_female->setObjectName(QStringLiteral("radio_female"));

        formLayout_16->setWidget(1, QFormLayout::FieldRole, radio_female);


        person_form->setLayout(2, QFormLayout::FieldRole, formLayout_16);

        formLayout_17 = new QFormLayout();
        formLayout_17->setSpacing(6);
        formLayout_17->setObjectName(QStringLiteral("formLayout_17"));
        label_17 = new QLabel(formLayoutWidget_2);
        label_17->setObjectName(QStringLiteral("label_17"));

        formLayout_17->setWidget(0, QFormLayout::LabelRole, label_17);

        label_date_birth_error_code = new QLabel(formLayoutWidget_2);
        label_date_birth_error_code->setObjectName(QStringLiteral("label_date_birth_error_code"));

        formLayout_17->setWidget(0, QFormLayout::FieldRole, label_date_birth_error_code);


        person_form->setLayout(4, QFormLayout::FieldRole, formLayout_17);

        line_person_date_birth = new QLineEdit(formLayoutWidget_2);
        line_person_date_birth->setObjectName(QStringLiteral("line_person_date_birth"));
        line_person_date_birth->setInputMethodHints(Qt::ImhNone);

        person_form->setWidget(5, QFormLayout::FieldRole, line_person_date_birth);

        line_person_date_death = new QLineEdit(formLayoutWidget_2);
        line_person_date_death->setObjectName(QStringLiteral("line_person_date_death"));

        person_form->setWidget(7, QFormLayout::FieldRole, line_person_date_death);

        formLayout_18 = new QFormLayout();
        formLayout_18->setSpacing(6);
        formLayout_18->setObjectName(QStringLiteral("formLayout_18"));
        label_18 = new QLabel(formLayoutWidget_2);
        label_18->setObjectName(QStringLiteral("label_18"));

        formLayout_18->setWidget(0, QFormLayout::LabelRole, label_18);

        label_known_for_error_code = new QLabel(formLayoutWidget_2);
        label_known_for_error_code->setObjectName(QStringLiteral("label_known_for_error_code"));

        formLayout_18->setWidget(0, QFormLayout::FieldRole, label_known_for_error_code);


        person_form->setLayout(9, QFormLayout::FieldRole, formLayout_18);

        text_person_known_for = new QTextEdit(formLayoutWidget_2);
        text_person_known_for->setObjectName(QStringLiteral("text_person_known_for"));

        person_form->setWidget(10, QFormLayout::FieldRole, text_person_known_for);

        add_person_confirm = new QPushButton(formLayoutWidget_2);
        add_person_confirm->setObjectName(QStringLiteral("add_person_confirm"));

        person_form->setWidget(11, QFormLayout::FieldRole, add_person_confirm);

        formLayout_19 = new QFormLayout();
        formLayout_19->setSpacing(6);
        formLayout_19->setObjectName(QStringLiteral("formLayout_19"));
        label_19 = new QLabel(formLayoutWidget_2);
        label_19->setObjectName(QStringLiteral("label_19"));

        formLayout_19->setWidget(0, QFormLayout::LabelRole, label_19);

        label_date_death_error_code = new QLabel(formLayoutWidget_2);
        label_date_death_error_code->setObjectName(QStringLiteral("label_date_death_error_code"));

        formLayout_19->setWidget(0, QFormLayout::FieldRole, label_date_death_error_code);


        person_form->setLayout(6, QFormLayout::FieldRole, formLayout_19);

        tabWidget->addTab(tab_3, QString());
        tab_view_chocie->addTab(tab_person, QString());
        tab_computer = new QWidget();
        tab_computer->setObjectName(QStringLiteral("tab_computer"));
        table_computer = new QTableWidget(tab_computer);
        if (table_computer->columnCount() < 4)
            table_computer->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        table_computer->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        table_computer->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        table_computer->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        table_computer->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        table_computer->setObjectName(QStringLiteral("table_computer"));
        table_computer->setEnabled(true);
        table_computer->setGeometry(QRect(380, 20, 411, 481));
        table_computer->setAutoFillBackground(true);
        table_computer->setFrameShape(QFrame::StyledPanel);
        table_computer->setFrameShadow(QFrame::Plain);
        table_computer->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        table_computer->setShowGrid(true);
        table_computer->setSortingEnabled(false);
        table_computer->setRowCount(0);
        table_computer->verticalHeader()->setVisible(false);
        table_computer->verticalHeader()->setStretchLastSection(false);
        tabWidget_2 = new QTabWidget(tab_computer);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(-2, -1, 371, 501));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayoutWidget_6 = new QWidget(tab);
        gridLayoutWidget_6->setObjectName(QStringLiteral("gridLayoutWidget_6"));
        gridLayoutWidget_6->setGeometry(QRect(10, 10, 269, 161));
        gridLayout_6 = new QGridLayout(gridLayoutWidget_6);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        search_computer = new QLineEdit(gridLayoutWidget_6);
        search_computer->setObjectName(QStringLiteral("search_computer"));

        gridLayout_6->addWidget(search_computer, 0, 0, 1, 1);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        computer_order_combo = new QComboBox(gridLayoutWidget_6);
        computer_order_combo->setObjectName(QStringLiteral("computer_order_combo"));

        gridLayout_7->addWidget(computer_order_combo, 2, 1, 1, 1);

        computer_type_combo = new QComboBox(gridLayoutWidget_6);
        computer_type_combo->setObjectName(QStringLiteral("computer_type_combo"));

        gridLayout_7->addWidget(computer_type_combo, 1, 1, 1, 1);

        label_11 = new QLabel(gridLayoutWidget_6);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_7->addWidget(label_11, 0, 0, 1, 1);

        label_12 = new QLabel(gridLayoutWidget_6);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_7->addWidget(label_12, 2, 0, 1, 1);

        computer_yearBuilt_line_edit = new QLineEdit(gridLayoutWidget_6);
        computer_yearBuilt_line_edit->setObjectName(QStringLiteral("computer_yearBuilt_line_edit"));

        gridLayout_7->addWidget(computer_yearBuilt_line_edit, 0, 1, 1, 1);

        label_13 = new QLabel(gridLayoutWidget_6);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_7->addWidget(label_13, 1, 0, 1, 1);

        computer_orderBy_combo = new QComboBox(gridLayoutWidget_6);
        computer_orderBy_combo->setObjectName(QStringLiteral("computer_orderBy_combo"));

        gridLayout_7->addWidget(computer_orderBy_combo, 3, 1, 1, 1);

        label_14 = new QLabel(gridLayoutWidget_6);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_7->addWidget(label_14, 3, 0, 1, 1);

        computer_wasBuilt_checkBox = new QCheckBox(gridLayoutWidget_6);
        computer_wasBuilt_checkBox->setObjectName(QStringLiteral("computer_wasBuilt_checkBox"));
        computer_wasBuilt_checkBox->setChecked(true);
        computer_wasBuilt_checkBox->setTristate(false);

        gridLayout_7->addWidget(computer_wasBuilt_checkBox, 4, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_7, 2, 0, 1, 1);

        button_computer_search_update = new QPushButton(gridLayoutWidget_6);
        button_computer_search_update->setObjectName(QStringLiteral("button_computer_search_update"));

        gridLayout_6->addWidget(button_computer_search_update, 0, 1, 1, 1);

        computer_details = new QTabWidget(tab);
        computer_details->setObjectName(QStringLiteral("computer_details"));
        computer_details->setGeometry(QRect(10, 170, 361, 311));
        computer_details->setAutoFillBackground(false);
        computer_details->setTabShape(QTabWidget::Rounded);
        computer_details->setDocumentMode(false);
        computer_details->setMovable(true);
        computer_profile = new QWidget();
        computer_profile->setObjectName(QStringLiteral("computer_profile"));
        verticalLayoutWidget_2 = new QWidget(computer_profile);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(130, 10, 211, 221));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        groupBox_2 = new QGroupBox(verticalLayoutWidget_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayoutWidget_2 = new QWidget(groupBox_2);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 180, 181, 31));
        gridLayout_8 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        button_delete_computer = new QPushButton(gridLayoutWidget_2);
        button_delete_computer->setObjectName(QStringLiteral("button_delete_computer"));
        button_delete_computer->setEnabled(false);

        gridLayout_8->addWidget(button_delete_computer, 0, 0, 1, 1);

        button_edit_computer = new QPushButton(gridLayoutWidget_2);
        button_edit_computer->setObjectName(QStringLiteral("button_edit_computer"));
        button_edit_computer->setEnabled(false);

        gridLayout_8->addWidget(button_edit_computer, 0, 1, 1, 1);

        formLayoutWidget_4 = new QWidget(groupBox_2);
        formLayoutWidget_4->setObjectName(QStringLiteral("formLayoutWidget_4"));
        formLayoutWidget_4->setGeometry(QRect(10, 20, 181, 151));
        formLayout_2 = new QFormLayout(formLayoutWidget_4);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_computer_id = new QLabel(formLayoutWidget_4);
        label_computer_id->setObjectName(QStringLiteral("label_computer_id"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_computer_id);

        label_23 = new QLabel(formLayoutWidget_4);
        label_23->setObjectName(QStringLiteral("label_23"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_23);

        computer_name = new QLineEdit(formLayoutWidget_4);
        computer_name->setObjectName(QStringLiteral("computer_name"));
        computer_name->setEnabled(false);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, computer_name);

        label_25 = new QLabel(formLayoutWidget_4);
        label_25->setObjectName(QStringLiteral("label_25"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_25);

        computer_yearBuilt = new QLineEdit(formLayoutWidget_4);
        computer_yearBuilt->setObjectName(QStringLiteral("computer_yearBuilt"));
        computer_yearBuilt->setEnabled(false);

        formLayout_2->setWidget(4, QFormLayout::FieldRole, computer_yearBuilt);

        label_26 = new QLabel(formLayoutWidget_4);
        label_26->setObjectName(QStringLiteral("label_26"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_26);

        computer_built = new QLineEdit(formLayoutWidget_4);
        computer_built->setObjectName(QStringLiteral("computer_built"));
        computer_built->setEnabled(false);
        computer_built->setInputMethodHints(Qt::ImhNone);

        formLayout_2->setWidget(5, QFormLayout::FieldRole, computer_built);

        label_27 = new QLabel(formLayoutWidget_4);
        label_27->setObjectName(QStringLiteral("label_27"));

        formLayout_2->setWidget(6, QFormLayout::LabelRole, label_27);

        computer_weight = new QLineEdit(formLayoutWidget_4);
        computer_weight->setObjectName(QStringLiteral("computer_weight"));
        computer_weight->setEnabled(false);
        computer_weight->setFrame(true);

        formLayout_2->setWidget(6, QFormLayout::FieldRole, computer_weight);

        label_28 = new QLabel(formLayoutWidget_4);
        label_28->setObjectName(QStringLiteral("label_28"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_28);

        computer_type = new QLineEdit(formLayoutWidget_4);
        computer_type->setObjectName(QStringLiteral("computer_type"));
        computer_type->setEnabled(false);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, computer_type);


        verticalLayout_2->addWidget(groupBox_2);

        computer_details->addTab(computer_profile, QString());
        computer_connections_tab = new QWidget();
        computer_connections_tab->setObjectName(QStringLiteral("computer_connections_tab"));
        table_computer_connections = new QTableWidget(computer_connections_tab);
        if (table_computer_connections->columnCount() < 2)
            table_computer_connections->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        table_computer_connections->setHorizontalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        table_computer_connections->setHorizontalHeaderItem(1, __qtablewidgetitem11);
        table_computer_connections->setObjectName(QStringLiteral("table_computer_connections"));
        table_computer_connections->setEnabled(true);
        table_computer_connections->setGeometry(QRect(10, 10, 201, 271));
        table_computer_connections->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        gridLayoutWidget_7 = new QWidget(computer_connections_tab);
        gridLayoutWidget_7->setObjectName(QStringLiteral("gridLayoutWidget_7"));
        gridLayoutWidget_7->setGeometry(QRect(220, 20, 155, 80));
        gridLayout_9 = new QGridLayout(gridLayoutWidget_7);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        button_remove_connection_computer = new QPushButton(gridLayoutWidget_7);
        button_remove_connection_computer->setObjectName(QStringLiteral("button_remove_connection_computer"));

        gridLayout_9->addWidget(button_remove_connection_computer, 1, 0, 1, 1);

        gridLayout_10 = new QGridLayout();
        gridLayout_10->setSpacing(6);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        gridLayout_10->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout_10->setContentsMargins(0, -1, 0, -1);
        label_29 = new QLabel(gridLayoutWidget_7);
        label_29->setObjectName(QStringLiteral("label_29"));

        gridLayout_10->addWidget(label_29, 0, 1, 1, 1);

        button_add_connection_computer = new QPushButton(gridLayoutWidget_7);
        button_add_connection_computer->setObjectName(QStringLiteral("button_add_connection_computer"));

        gridLayout_10->addWidget(button_add_connection_computer, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(gridLayoutWidget_7);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        sizePolicy.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy);

        gridLayout_10->addWidget(lineEdit_2, 0, 2, 1, 1);


        gridLayout_9->addLayout(gridLayout_10, 0, 0, 1, 1);

        computer_details->addTab(computer_connections_tab, QString());
        tabWidget_2->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        formLayoutWidget_3 = new QWidget(tab_2);
        formLayoutWidget_3->setObjectName(QStringLiteral("formLayoutWidget_3"));
        formLayoutWidget_3->setGeometry(QRect(0, 0, 271, 341));
        person_form_2 = new QFormLayout(formLayoutWidget_3);
        person_form_2->setSpacing(6);
        person_form_2->setContentsMargins(11, 11, 11, 11);
        person_form_2->setObjectName(QStringLiteral("person_form_2"));
        person_form_2->setContentsMargins(0, 0, 0, 0);
        formLayout_20 = new QFormLayout();
        formLayout_20->setSpacing(6);
        formLayout_20->setObjectName(QStringLiteral("formLayout_20"));
        label_20 = new QLabel(formLayoutWidget_3);
        label_20->setObjectName(QStringLiteral("label_20"));

        formLayout_20->setWidget(0, QFormLayout::LabelRole, label_20);

        label_computer_name_error_code = new QLabel(formLayoutWidget_3);
        label_computer_name_error_code->setObjectName(QStringLiteral("label_computer_name_error_code"));

        formLayout_20->setWidget(0, QFormLayout::FieldRole, label_computer_name_error_code);


        person_form_2->setLayout(0, QFormLayout::FieldRole, formLayout_20);

        line_computer_name = new QLineEdit(formLayoutWidget_3);
        line_computer_name->setObjectName(QStringLiteral("line_computer_name"));

        person_form_2->setWidget(1, QFormLayout::FieldRole, line_computer_name);

        label_21 = new QLabel(formLayoutWidget_3);
        label_21->setObjectName(QStringLiteral("label_21"));

        person_form_2->setWidget(2, QFormLayout::FieldRole, label_21);

        computer_type_add_Combo = new QComboBox(formLayoutWidget_3);
        computer_type_add_Combo->setObjectName(QStringLiteral("computer_type_add_Combo"));

        person_form_2->setWidget(3, QFormLayout::FieldRole, computer_type_add_Combo);

        formLayout_22 = new QFormLayout();
        formLayout_22->setSpacing(6);
        formLayout_22->setObjectName(QStringLiteral("formLayout_22"));
        label_22 = new QLabel(formLayoutWidget_3);
        label_22->setObjectName(QStringLiteral("label_22"));

        formLayout_22->setWidget(0, QFormLayout::LabelRole, label_22);

        label_yearBuilt_error_code = new QLabel(formLayoutWidget_3);
        label_yearBuilt_error_code->setObjectName(QStringLiteral("label_yearBuilt_error_code"));

        formLayout_22->setWidget(0, QFormLayout::FieldRole, label_yearBuilt_error_code);


        person_form_2->setLayout(4, QFormLayout::FieldRole, formLayout_22);

        line_computer_yearBuilt = new QLineEdit(formLayoutWidget_3);
        line_computer_yearBuilt->setObjectName(QStringLiteral("line_computer_yearBuilt"));
        line_computer_yearBuilt->setInputMethodHints(Qt::ImhDigitsOnly);

        person_form_2->setWidget(5, QFormLayout::FieldRole, line_computer_yearBuilt);

        formLayout_24 = new QFormLayout();
        formLayout_24->setSpacing(6);
        formLayout_24->setObjectName(QStringLiteral("formLayout_24"));
        label_24 = new QLabel(formLayoutWidget_3);
        label_24->setObjectName(QStringLiteral("label_24"));

        formLayout_24->setWidget(0, QFormLayout::LabelRole, label_24);

        label_weight_error_code = new QLabel(formLayoutWidget_3);
        label_weight_error_code->setObjectName(QStringLiteral("label_weight_error_code"));

        formLayout_24->setWidget(0, QFormLayout::FieldRole, label_weight_error_code);


        person_form_2->setLayout(6, QFormLayout::FieldRole, formLayout_24);

        line_computer_weight = new QLineEdit(formLayoutWidget_3);
        line_computer_weight->setObjectName(QStringLiteral("line_computer_weight"));
        line_computer_weight->setInputMethodHints(Qt::ImhDigitsOnly);

        person_form_2->setWidget(7, QFormLayout::FieldRole, line_computer_weight);

        add_computer_confirm = new QPushButton(formLayoutWidget_3);
        add_computer_confirm->setObjectName(QStringLiteral("add_computer_confirm"));

        person_form_2->setWidget(9, QFormLayout::FieldRole, add_computer_confirm);

        tabWidget_2->addTab(tab_2, QString());
        tab_view_chocie->addTab(tab_computer, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 828, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tab_view_chocie->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);
        person_details->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(1);
        computer_details->setCurrentIndex(0);


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
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Date birth", 0));
        QTableWidgetItem *___qtablewidgetitem3 = table_person->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Date death", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Information", 0));
        button_delete_person->setText(QApplication::translate("MainWindow", "Delete", 0));
        button_edit_person->setText(QApplication::translate("MainWindow", "Edit", 0));
        label_person_id->setText(QApplication::translate("MainWindow", "Id:", 0));
        label->setText(QApplication::translate("MainWindow", "Name", 0));
        label_2->setText(QApplication::translate("MainWindow", "Age", 0));
        label_3->setText(QApplication::translate("MainWindow", "Date birth", 0));
        label_4->setText(QApplication::translate("MainWindow", "Date death", 0));
        label_5->setText(QApplication::translate("MainWindow", "Gender", 0));
        button_person_change_profilepic->setText(QApplication::translate("MainWindow", "Browse", 0));
        person_profilepic->setText(QString());
        person_details->setTabText(person_details->indexOf(person_profile), QApplication::translate("MainWindow", "Profile", 0));
        QTableWidgetItem *___qtablewidgetitem4 = table_person_connections->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Id", 0));
        QTableWidgetItem *___qtablewidgetitem5 = table_person_connections->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Name", 0));
        button_remove_connection_person->setText(QApplication::translate("MainWindow", "Remove selected", 0));
        label_10->setText(QApplication::translate("MainWindow", "Id:", 0));
        button_add_connection_person->setText(QApplication::translate("MainWindow", "Add new", 0));
        person_details->setTabText(person_details->indexOf(person_connections), QApplication::translate("MainWindow", "Connections", 0));
        search_person->setPlaceholderText(QApplication::translate("MainWindow", "Search for person...", 0));
        person_order_combo->clear();
        person_order_combo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Ascending", 0)
         << QApplication::translate("MainWindow", "Descending", 0)
        );
        person_gender_combo->clear();
        person_gender_combo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Both", 0)
         << QApplication::translate("MainWindow", "Male", 0)
         << QApplication::translate("MainWindow", "Female", 0)
        );
        label_6->setText(QApplication::translate("MainWindow", "Age", 0));
        label_8->setText(QApplication::translate("MainWindow", "Order", 0));
        person_age_line_edit->setPlaceholderText(QApplication::translate("MainWindow", "e.g 35-50", 0));
        label_7->setText(QApplication::translate("MainWindow", "Gender", 0));
        person_orderBy_combo->clear();
        person_orderBy_combo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Id", 0)
         << QApplication::translate("MainWindow", "Name", 0)
         << QApplication::translate("MainWindow", "Date birth", 0)
        );
        label_9->setText(QApplication::translate("MainWindow", "Order by", 0));
        button_person_search_update->setText(QApplication::translate("MainWindow", "Search", 0));
        tabWidget->setTabText(tabWidget->indexOf(person_tab_search), QApplication::translate("MainWindow", "Search", 0));
        label_15->setText(QApplication::translate("MainWindow", "Name:", 0));
        label_name_error_code->setText(QString());
        label_16->setText(QApplication::translate("MainWindow", "Gender:", 0));
        radio_male->setText(QApplication::translate("MainWindow", "Male", 0));
        radio_female->setText(QApplication::translate("MainWindow", "Female", 0));
        label_17->setText(QApplication::translate("MainWindow", "Date birth (dd/mm/yyyy):", 0));
        label_date_birth_error_code->setText(QString());
        label_18->setText(QApplication::translate("MainWindow", "Known for:", 0));
        label_known_for_error_code->setText(QString());
        add_person_confirm->setText(QApplication::translate("MainWindow", "Add Person", 0));
        label_19->setText(QApplication::translate("MainWindow", "Date death (dd/mm/yyyy) -1 if alive:", 0));
        label_date_death_error_code->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Add new", 0));
        tab_view_chocie->setTabText(tab_view_chocie->indexOf(tab_person), QApplication::translate("MainWindow", "Person", 0));
        QTableWidgetItem *___qtablewidgetitem6 = table_computer->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Id", 0));
        QTableWidgetItem *___qtablewidgetitem7 = table_computer->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem8 = table_computer->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "Year built", 0));
        QTableWidgetItem *___qtablewidgetitem9 = table_computer->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "Type", 0));
        search_computer->setPlaceholderText(QApplication::translate("MainWindow", "Search for computer...", 0));
        computer_order_combo->clear();
        computer_order_combo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Ascending", 0)
         << QApplication::translate("MainWindow", "Descending", 0)
        );
        computer_type_combo->clear();
        computer_type_combo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "all", 0)
         << QApplication::translate("MainWindow", "electromechanical", 0)
         << QApplication::translate("MainWindow", "electronic", 0)
         << QApplication::translate("MainWindow", "transistor", 0)
         << QApplication::translate("MainWindow", "mechanical", 0)
        );
        label_11->setText(QApplication::translate("MainWindow", "Year buillt", 0));
        label_12->setText(QApplication::translate("MainWindow", "Order", 0));
        computer_yearBuilt_line_edit->setPlaceholderText(QApplication::translate("MainWindow", "e.g 1940-1950", 0));
        label_13->setText(QApplication::translate("MainWindow", "Type", 0));
        computer_orderBy_combo->clear();
        computer_orderBy_combo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Id", 0)
         << QApplication::translate("MainWindow", "Name", 0)
         << QApplication::translate("MainWindow", "Year built", 0)
         << QApplication::translate("MainWindow", "Weight", 0)
        );
        label_14->setText(QApplication::translate("MainWindow", "Order by", 0));
        computer_wasBuilt_checkBox->setText(QApplication::translate("MainWindow", "Was built", 0));
        button_computer_search_update->setText(QApplication::translate("MainWindow", "Search", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Information", 0));
        button_delete_computer->setText(QApplication::translate("MainWindow", "Delete", 0));
        button_edit_computer->setText(QApplication::translate("MainWindow", "Edit", 0));
        label_computer_id->setText(QApplication::translate("MainWindow", "Id:", 0));
        label_23->setText(QApplication::translate("MainWindow", "Name", 0));
        label_25->setText(QApplication::translate("MainWindow", "Year built", 0));
        label_26->setText(QApplication::translate("MainWindow", "Was built?", 0));
        label_27->setText(QApplication::translate("MainWindow", "Weight", 0));
        label_28->setText(QApplication::translate("MainWindow", "Type", 0));
        computer_details->setTabText(computer_details->indexOf(computer_profile), QApplication::translate("MainWindow", "Profile", 0));
        QTableWidgetItem *___qtablewidgetitem10 = table_computer_connections->horizontalHeaderItem(0);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "Id", 0));
        QTableWidgetItem *___qtablewidgetitem11 = table_computer_connections->horizontalHeaderItem(1);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "Name", 0));
        button_remove_connection_computer->setText(QApplication::translate("MainWindow", "Remove selected", 0));
        label_29->setText(QApplication::translate("MainWindow", "Id:", 0));
        button_add_connection_computer->setText(QApplication::translate("MainWindow", "Add new", 0));
        computer_details->setTabText(computer_details->indexOf(computer_connections_tab), QApplication::translate("MainWindow", "Connections", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab), QApplication::translate("MainWindow", "Search", 0));
        label_20->setText(QApplication::translate("MainWindow", "Name:", 0));
        label_computer_name_error_code->setText(QString());
        label_21->setText(QApplication::translate("MainWindow", "Type:", 0));
        computer_type_add_Combo->clear();
        computer_type_add_Combo->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "electromechanical", 0)
         << QApplication::translate("MainWindow", "electronic", 0)
         << QApplication::translate("MainWindow", "mechanical", 0)
         << QApplication::translate("MainWindow", "transistor", 0)
        );
        label_22->setText(QApplication::translate("MainWindow", "Year built (-1 if N/A):", 0));
        label_yearBuilt_error_code->setText(QString());
        label_24->setText(QApplication::translate("MainWindow", "Weight:", 0));
        label_weight_error_code->setText(QString());
        add_computer_confirm->setText(QApplication::translate("MainWindow", "Add Computer", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_2), QApplication::translate("MainWindow", "Add new", 0));
        tab_view_chocie->setTabText(tab_view_chocie->indexOf(tab_computer), QApplication::translate("MainWindow", "Computer", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
