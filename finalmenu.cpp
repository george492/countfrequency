#include "finalmenu.h"
#include "ui_finalmenu.h"
#include "mainwindow.h"
extern std::string globalString;
finalmenu::finalmenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::finalmenu)

{

    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &finalmenu::on_pushButton_clicked);
}

finalmenu::~finalmenu()
{
    delete ui;
}
void finalmenu::on_pushButton_clicked()
{       MainWindow *M=new MainWindow();
    this->hide();
    M->show();}
void finalmenu::updatetext()
{
     ui->textBrowser->setText(QString::fromStdString(globalString));
}
