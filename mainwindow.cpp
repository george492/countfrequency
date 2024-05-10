#include "mainwindow.h"
#include <QString>
#include "WordFrequancy.h"
#include <QTextEdit>
#include "./ui_mainwindow.h"
#include "finalmenu.h"
#include <string>
// main.cpp
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->label->setText(QString::fromStdString(globalString));
    ui->textEdit->setText(QString::fromStdString(WordFrequancy::globalString));
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString text = ui->textEdit->toPlainText();
    finalmenu *t = new finalmenu(this);
    // Initialize a string with the retrieved text
    WordFrequancy::globalString = text.toStdString();
    // Use the initialized string as needed
    // For example, print it to the console
    //qDebug() << "Initialized string: " << QString::fromStdString(globalString);
    //t->finalmenu::Ui->setText(QString::fromStdString(globalString));
    t->updatetext();
    //emit updatetext();
    this->hide();
    t->show();
}

