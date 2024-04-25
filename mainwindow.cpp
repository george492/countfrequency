#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPushButton>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // here add what you want
}

MainWindow::~MainWindow()
{
    delete ui;
}

