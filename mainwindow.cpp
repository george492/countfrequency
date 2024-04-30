#include "mainwindow.h"
#include <QString>
#include <QTextEdit>
#include "./ui_mainwindow.h"
#include "finalmenu.h"
#include <string>
// main.cpp
extern std::string globalString; // Declare the global string variable
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->label->setText(QString::fromStdString(globalString));
    ui->textEdit->setText(QString::fromStdString(globalString));
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    // Retrieve text from the QTextEdit widget
    QString text = ui->textEdit->toPlainText();
    finalmenu *t = new finalmenu(this);
    // Initialize a string with the retrieved text
    globalString = text.toStdString();
    // Use the initialized string as needed
    // For example, print it to the console
    //qDebug() << "Initialized string: " << QString::fromStdString(globalString);
    //t->finalmenu::Ui->setText(QString::fromStdString(globalString));
    t->updatetext();
    //emit updatetext();
    this->hide();
    t->show();
}
