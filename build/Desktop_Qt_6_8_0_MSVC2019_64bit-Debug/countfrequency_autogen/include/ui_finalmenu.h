/********************************************************************************
** Form generated from reading UI file 'finalmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINALMENU_H
#define UI_FINALMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_finalmenu
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *Search;
    QTextBrowser *textBrowser;
    QPushButton *pushButton_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *finalmenu)
    {
        if (finalmenu->objectName().isEmpty())
            finalmenu->setObjectName("finalmenu");
        finalmenu->resize(800, 600);
        centralwidget = new QWidget(finalmenu);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 510, 83, 29));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(160, 510, 131, 29));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(360, 510, 83, 29));
        Search = new QPushButton(centralwidget);
        Search->setObjectName("Search");
        Search->setGeometry(QRect(510, 510, 111, 29));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(10, 10, 771, 491));
        QFont font;
        font.setPointSize(10);
        textBrowser->setFont(font);
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(689, 510, 101, 31));
        finalmenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(finalmenu);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        finalmenu->setMenuBar(menubar);
        statusbar = new QStatusBar(finalmenu);
        statusbar->setObjectName("statusbar");
        finalmenu->setStatusBar(statusbar);

        retranslateUi(finalmenu);

        QMetaObject::connectSlotsByName(finalmenu);
    } // setupUi

    void retranslateUi(QMainWindow *finalmenu)
    {
        finalmenu->setWindowTitle(QCoreApplication::translate("finalmenu", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("finalmenu", "edit", nullptr));
        pushButton_2->setText(QCoreApplication::translate("finalmenu", "Display sorted", nullptr));
        pushButton_3->setText(QCoreApplication::translate("finalmenu", "Display", nullptr));
        Search->setText(QCoreApplication::translate("finalmenu", "Search", nullptr));
        pushButton_4->setText(QCoreApplication::translate("finalmenu", "Common words", nullptr));
    } // retranslateUi

};

namespace Ui {
    class finalmenu: public Ui_finalmenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINALMENU_H
