#include "firstmenu.h"
#include "ui_firstmenu.h"
#include "mainwindow.h"
#include "finalmenu.h"
#include <QMessageBox>
#include <QPushButton>
#include <QFileDialog>
#include<string>
#include <QFile>
using namespace std;
extern std::string globalString;
firstmenu::firstmenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::firstmenu)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &firstmenu::on_submitButton_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &firstmenu::on_loadButton_clicked);

}

firstmenu::~firstmenu()
{
    delete ui;
}
void firstmenu::on_submitButton_clicked()
{
    MainWindow *M=new MainWindow();
    this->hide();
    M->show();
}

void firstmenu::on_loadButton_clicked()
{
    finalmenu *t = new finalmenu();
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", QDir::homePath());
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            QString fileContent = in.readAll();
           // globalstring=in.readAll();
           // ui->textInput->setPlainText(fileContent);
            globalString =fileContent.toStdString();
            file.close();
            this->hide();
            t->show();
        } else {
            QMessageBox::warning(this, "Error", "Failed to open file.");
        }
    }

}
