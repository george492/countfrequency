#include "firstmenu.h"
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QPushButton>
#include "finalmenu.h"
#include "mainwindow.h"
#include "ui_firstmenu.h"
#include <string>
#include "WordFrequancy.h"
#include "datamanager.h"

using namespace std;
//string globalString; // Declare the global variable
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
    MainWindow *M = new MainWindow();
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
            DataManager::instance().setString( fileContent);
            t->updatetext();
            file.close();
            this->hide();
            t->show();
        } else {
            QMessageBox::warning(this, "Error", "Failed to open file.");
        }
    }
}
