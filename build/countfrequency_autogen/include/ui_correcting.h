/********************************************************************************
** Form generated from reading UI file 'correcting.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CORRECTING_H
#define UI_CORRECTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_correcting
{
public:
    QWidget *centralwidget;
    QTextBrowser *textBrowser_2;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *correcting)
    {
        if (correcting->objectName().isEmpty())
            correcting->setObjectName("correcting");
        correcting->resize(377, 600);
        centralwidget = new QWidget(correcting);
        centralwidget->setObjectName("centralwidget");
        textBrowser_2 = new QTextBrowser(centralwidget);
        textBrowser_2->setObjectName("textBrowser_2");
        textBrowser_2->setGeometry(QRect(40, 0, 191, 31));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(20, 51, 331, 461));
        correcting->setCentralWidget(centralwidget);
        menubar = new QMenuBar(correcting);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 377, 25));
        correcting->setMenuBar(menubar);
        statusbar = new QStatusBar(correcting);
        statusbar->setObjectName("statusbar");
        correcting->setStatusBar(statusbar);

        retranslateUi(correcting);

        QMetaObject::connectSlotsByName(correcting);
    } // setupUi

    void retranslateUi(QMainWindow *correcting)
    {
        correcting->setWindowTitle(QCoreApplication::translate("correcting", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class correcting: public Ui_correcting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CORRECTING_H
