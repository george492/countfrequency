/********************************************************************************
** Form generated from reading UI file 'displaymenu.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAYMENU_H
#define UI_DISPLAYMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_displaymenu
{
public:
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QScrollBar *verticalScrollBar;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *displaymenu)
    {
        if (displaymenu->objectName().isEmpty())
            displaymenu->setObjectName("displaymenu");
        displaymenu->resize(803, 565);
        centralwidget = new QWidget(displaymenu);
        centralwidget->setObjectName("centralwidget");
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(0, 0, 781, 451));
        verticalScrollBar = new QScrollBar(centralwidget);
        verticalScrollBar->setObjectName("verticalScrollBar");
        verticalScrollBar->setGeometry(QRect(780, 0, 20, 451));
        verticalScrollBar->setOrientation(Qt::Vertical);
        displaymenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(displaymenu);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 803, 25));
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
