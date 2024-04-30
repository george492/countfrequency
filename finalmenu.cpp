#include "finalmenu.h"
#include "mainwindow.h"
#include "ui_finalmenu.h"
extern std::string globalString;
finalmenu::finalmenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::finalmenu)

{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &finalmenu::on_pushButton_clicked);

    displayMenu = new displaymenu(this);///

    connect(ui->pushButton_3,&QPushButton::clicked, this, &finalmenu::openDisplaymenu);///
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

void finalmenu::openDisplaymenu()///
{
    displayMenu->show();
}
