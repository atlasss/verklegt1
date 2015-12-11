/********************************************************************************
** Form generated from reading UI file 'addperson.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPERSON_H
#define UI_ADDPERSON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addPerson
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QFormLayout *formLayout_2;
    QLabel *label_2;
    QRadioButton *radio_male;
    QRadioButton *radio_female;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QTextEdit *textEdit_2;
    QPushButton *add_person_confirm;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QButtonGroup *gender_radio_group;

    void setupUi(QDialog *addPerson)
    {
        if (addPerson->objectName().isEmpty())
            addPerson->setObjectName(QStringLiteral("addPerson"));
        addPerson->resize(280, 349);
        formLayoutWidget = new QWidget(addPerson);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 20, 231, 323));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_2);

        radio_male = new QRadioButton(formLayoutWidget);
        gender_radio_group = new QButtonGroup(addPerson);
        gender_radio_group->setObjectName(QStringLiteral("gender_radio_group"));
        gender_radio_group->addButton(radio_male);
        radio_male->setObjectName(QStringLiteral("radio_male"));
        radio_male->setChecked(true);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, radio_male);

        radio_female = new QRadioButton(formLayoutWidget);
        gender_radio_group->addButton(radio_female);
        radio_female->setObjectName(QStringLiteral("radio_female"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, radio_female);


        formLayout->setLayout(1, QFormLayout::FieldRole, formLayout_2);

        lineEdit_2 = new QLineEdit(formLayoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_2);

        lineEdit_3 = new QLineEdit(formLayoutWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEdit_3);

        textEdit_2 = new QTextEdit(formLayoutWidget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));

        formLayout->setWidget(7, QFormLayout::FieldRole, textEdit_2);

        add_person_confirm = new QPushButton(formLayoutWidget);
        add_person_confirm->setObjectName(QStringLiteral("add_person_confirm"));

        formLayout->setWidget(8, QFormLayout::FieldRole, add_person_confirm);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(formLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);


        formLayout->setLayout(0, QFormLayout::FieldRole, verticalLayout);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::FieldRole, label_3);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(4, QFormLayout::FieldRole, label_4);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(6, QFormLayout::FieldRole, label_5);


        retranslateUi(addPerson);

        QMetaObject::connectSlotsByName(addPerson);
    } // setupUi

    void retranslateUi(QDialog *addPerson)
    {
        addPerson->setWindowTitle(QApplication::translate("addPerson", "Dialog", 0));
        label_2->setText(QApplication::translate("addPerson", "Gender:", 0));
        radio_male->setText(QApplication::translate("addPerson", "Male", 0));
        radio_female->setText(QApplication::translate("addPerson", "Female", 0));
        add_person_confirm->setText(QApplication::translate("addPerson", "Add Person", 0));
        label->setText(QApplication::translate("addPerson", "Name:", 0));
        label_3->setText(QApplication::translate("addPerson", "Date birth (dd/mm/yyyy):", 0));
        label_4->setText(QApplication::translate("addPerson", "Date death (dd/mm/yyyy) -1 if alive:", 0));
        label_5->setText(QApplication::translate("addPerson", "Known for:", 0));
    } // retranslateUi

};

namespace Ui {
    class addPerson: public Ui_addPerson {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPERSON_H
