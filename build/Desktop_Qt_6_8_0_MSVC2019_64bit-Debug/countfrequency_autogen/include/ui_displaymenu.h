/********************************************************************************
** Form generated from reading UI file 'displaymenu.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAYMENU_H
#define UI_DISPLAYMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_displaymenu
{
public:
    QWidget *centralwidget;
    QTextBrowser *printTextBrowser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *displaymenu)
    {
        if (displaymenu->objectName().isEmpty())
            displaymenu->setObjectName("displaymenu");
        displaymenu->resize(390, 565);
        centralwidget = new QWidget(displaymenu);
        centralwidget->setObjectName("centralwidget");
        printTextBrowser = new QTextBrowser(centralwidget);
        printTextBrowser->setObjectName("printTextBrowser");
        printTextBrowser->setGeometry(QRect(0, 0, 391, 521));
        displaymenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(displaymenu);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 390, 25));
        displaymenu->setMenuBar(menubar);
        statusbar = new QStatusBar(displaymenu);
        statusbar->setObjectName("statusbar");
        displaymenu->setStatusBar(statusbar);

        retranslateUi(displaymenu);

        QMetaObject::connectSlotsByName(displaymenu);
    } // setupUi

    void retranslateUi(QMainWindow *displaymenu)
    {
        displaymenu->setWindowTitle(QCoreApplication::translate("displaymenu", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class displaymenu: public Ui_displaymenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYMENU_H
