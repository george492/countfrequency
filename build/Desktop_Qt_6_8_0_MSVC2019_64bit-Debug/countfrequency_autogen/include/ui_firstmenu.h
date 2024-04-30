/********************************************************************************
** Form generated from reading UI file 'firstmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIRSTMENU_H
#define UI_FIRSTMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_firstmenu
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *firstmenu)
    {
        if (firstmenu->objectName().isEmpty())
            firstmenu->setObjectName("firstmenu");
        firstmenu->resize(800, 600);
        centralwidget = new QWidget(firstmenu);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(60, 250, 171, 91));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(390, 240, 211, 101));
        firstmenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(firstmenu);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        firstmenu->setMenuBar(menubar);
        statusbar = new QStatusBar(firstmenu);
        statusbar->setObjectName("statusbar");
        firstmenu->setStatusBar(statusbar);

        retranslateUi(firstmenu);

        QMetaObject::connectSlotsByName(firstmenu);
    } // setupUi

    void retranslateUi(QMainWindow *firstmenu)
    {
        firstmenu->setWindowTitle(QCoreApplication::translate("firstmenu", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("firstmenu", "Input text", nullptr));
        pushButton_2->setText(QCoreApplication::translate("firstmenu", "Read from text file", nullptr));
    } // retranslateUi

};

namespace Ui {
    class firstmenu: public Ui_firstmenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIRSTMENU_H
