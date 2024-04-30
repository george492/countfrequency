#include "finalmenu.h"
#include "mainwindow.h"
#include "displaymenu.h"
#include "ui_finalmenu.h"
#include "wordfrequancy.h"
extern std::string globalString;

finalmenu::finalmenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::finalmenu)

{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &finalmenu::on_pushButton_clicked);



    connect(ui->pushButton_3, &QPushButton::clicked, this, &finalmenu::openDisplaymenu); ///
}

finalmenu::~finalmenu()
{
    delete ui;
}
void finalmenu::on_pushButton_clicked()
{
    MainWindow *M = new MainWindow();
    this->hide();
    M->show();
}
void finalmenu::updatetext()
{
    ui->textBrowser->setText(QString::fromStdString(globalString));
}

void finalmenu::openDisplaymenu() ///
{ // one function for display only
       displayMenu = new displaymenu(this); ///
    displayMenu->show();
       //wordfrequency s = new wordfrequency(globalString);
    // s disply normally
       // t7t display sorted
}
// one for display sorted
