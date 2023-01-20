/********************************************************************************
** Form generated from reading UI file 'registr.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTR_H
#define UI_REGISTR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Registr
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *pushButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Registr)
    {
        if (Registr->objectName().isEmpty())
            Registr->setObjectName("Registr");
        Registr->resize(683, 563);
        centralwidget = new QWidget(Registr);
        centralwidget->setObjectName("centralwidget");
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(100, 220, 481, 28));
        lineEdit->setStyleSheet(QString::fromUtf8("border-color: rgb(100, 105, 207);"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(290, 170, 171, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(14);
        font.setBold(false);
        font.setItalic(false);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("font: 9pt \"Segoe UI\";\n"
"font: 14pt \"Segoe UI\";"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(240, 270, 221, 51));
        pushButton->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(70, 70, 171);"));
        Registr->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Registr);
        statusbar->setObjectName("statusbar");
        Registr->setStatusBar(statusbar);

        retranslateUi(Registr);

        QMetaObject::connectSlotsByName(Registr);
    } // setupUi

    void retranslateUi(QMainWindow *Registr)
    {
        Registr->setWindowTitle(QCoreApplication::translate("Registr", "MainWindow", nullptr));
        lineEdit->setPlaceholderText(QString());
        label->setText(QCoreApplication::translate("Registr", "Username:", nullptr));
        pushButton->setText(QCoreApplication::translate("Registr", "Connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Registr: public Ui_Registr {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTR_H
