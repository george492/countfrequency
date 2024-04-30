#include "displaymenu.h"
#include "ui_displaymenu.h"
extern std::string globalString;

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
