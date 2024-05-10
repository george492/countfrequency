/********************************************************************************
** Form generated from reading UI file 'searchwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHWINDOW_H
#define UI_SEARCHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_searchwindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QTextBrowser *Searchresults;
    QPushButton *pushButton_2;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *searchwindow)
    {
        if (searchwindow->objectName().isEmpty())
            searchwindow->setObjectName("searchwindow");
        searchwindow->resize(401, 600);
        centralwidget = new QWidget(searchwindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(290, 10, 83, 29));
        Searchresults = new QTextBrowser(centralwidget);
        Searchresults->setObjectName("Searchresults");
        Searchresults->setGeometry(QRect(10, 50, 371, 461));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(290, 520, 91, 29));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(20, 10, 251, 31));
        textEdit_2 = new QTextEdit(centralwidget);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(20, 520, 251, 31));
        searchwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(searchwindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 401, 25));
        searchwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(searchwindow);
        statusbar->setObjectName("statusbar");
        searchwindow->setStatusBar(statusbar);

        retranslateUi(searchwindow);

        QMetaObject::connectSlotsByName(searchwindow);
    } // setupUi

    void retranslateUi(QMainWindow *searchwindow)
    {
        searchwindow->setWindowTitle(QCoreApplication::translate("searchwindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("searchwindow", "Search", nullptr));
        pushButton_2->setText(QCoreApplication::translate("searchwindow", "Display", nullptr));
    } // retranslateUi

};

namespace Ui {
    class searchwindow: public Ui_searchwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHWINDOW_H
