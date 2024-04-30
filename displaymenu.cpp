#include "displaymenu.h"
#include "ui_displaymenu.h"

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
