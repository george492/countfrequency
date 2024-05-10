/********************************************************************************
** Form generated from reading UI file 'autocorrect.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTOCORRECT_H
#define UI_AUTOCORRECT_H

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

class Ui_autocorrect
{
public:
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;
    QTextEdit *textEdit_2;
    QTextBrowser *textBrowser_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *autocorrect)
    {
        if (autocorrect->objectName().isEmpty())
            autocorrect->setObjectName("autocorrect");
        autocorrect->resize(356, 600);
        centralwidget = new QWidget(autocorrect);
        centralwidget->setObjectName("centralwidget");
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(10, 51, 331, 461));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(260, 520, 83, 29));
        textEdit_2 = new QTextEdit(centralwidget);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(10, 520, 231, 31));
        textBrowser_2 = new QTextBrowser(centralwidget);
        textBrowser_2->setObjectName("textBrowser_2");
        textBrowser_2->setGeometry(QRect(30, 0, 191, 31));
        autocorrect->setCentralWidget(centralwidget);
        menubar = new QMenuBar(autocorrect);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 356, 25));
        autocorrect->setMenuBar(menubar);
        statusbar = new QStatusBar(autocorrect);
        statusbar->setObjectName("statusbar");
        autocorrect->setStatusBar(statusbar);

        retranslateUi(autocorrect);

        QMetaObject::connectSlotsByName(autocorrect);
    } // setupUi

    void retranslateUi(QMainWindow *autocorrect)
    {
        autocorrect->setWindowTitle(QCoreApplication::translate("autocorrect", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("autocorrect", "enter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class autocorrect: public Ui_autocorrect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTOCORRECT_H
