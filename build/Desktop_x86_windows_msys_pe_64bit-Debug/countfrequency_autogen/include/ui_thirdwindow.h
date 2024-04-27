/********************************************************************************
** Form generated from reading UI file 'thirdwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THIRDWINDOW_H
#define UI_THIRDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_thirdwindow
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *thirdwindow)
    {
        if (thirdwindow->objectName().isEmpty())
            thirdwindow->setObjectName("thirdwindow");
        thirdwindow->resize(856, 552);
        label = new QLabel(thirdwindow);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 40, 541, 191));
        pushButton = new QPushButton(thirdwindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(80, 310, 83, 29));

        retranslateUi(thirdwindow);

        QMetaObject::connectSlotsByName(thirdwindow);
    } // setupUi

    void retranslateUi(QDialog *thirdwindow)
    {
        thirdwindow->setWindowTitle(QCoreApplication::translate("thirdwindow", "Dialog", nullptr));
        label->setText(QString());
        pushButton->setText(QCoreApplication::translate("thirdwindow", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class thirdwindow: public Ui_thirdwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THIRDWINDOW_H
