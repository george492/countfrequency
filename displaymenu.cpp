#include "displaymenu.h"
#include "ui_displaymenu.h"
#include "WordFrequancy.h"
displaymenu::displaymenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::displaymenu)
{
    ui->setupUi(this);
}

displaymenu::~displaymenu()
{
    delete ui;
}

void displaymenu::printText(string s)
{
    QFont displayFont("Times New Roman", 16);
    ui->printTextBrowser->setFont(displayFont);
    ui->printTextBrowser->setText(QString::fromStdString(s));
}
