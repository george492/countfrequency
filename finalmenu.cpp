#include "finalmenu.h"
#include "displaymenu.h"
#include "mainwindow.h"
#include "ui_finalmenu.h"
#include "wordfrequancy.h"
#include "searchwindow.h"
#include "autocorrect.h"
#include <set>

finalmenu::finalmenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::finalmenu)

{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &finalmenu::on_pushButton_clicked);

    connect(ui->pushButton_3, &QPushButton::clicked, this, &finalmenu::openDisplaymenu);

    connect(ui->pushButton_2, &QPushButton::clicked, this, &finalmenu::openOrderedDisplaymenu);

    connect(ui->pushButton_4, &QPushButton::clicked, this, &finalmenu::openCommonDisplaymenu);

    connect(ui->Search, &QPushButton::clicked, this, &finalmenu::searchwin);
}

finalmenu::~finalmenu()
{
    delete ui;
}
void finalmenu::searchwin()
{
    searchwindow *s = new searchwindow();
    s->show();
}
void finalmenu::on_pushButton_clicked()
{
    MainWindow *M = new MainWindow();
    this->hide();
    M->show();
}
void finalmenu::updatetext()
{
    ui->textBrowser->setText(QString::fromStdString(WordFrequancy::globalString));
}

// display the window of unordered frequency
void finalmenu::openDisplaymenu()
{
    displayMenu = new displaymenu(this);
    string display;
    WordFrequancy unorderedDisplay = WordFrequancy(WordFrequancy::globalString);
    display = unorderedDisplay.displayFrequancy();
    displayMenu->printText(display);
    displayMenu->show();
}

// display the window of ordered frequency
void finalmenu::openOrderedDisplaymenu()
{
    displayMenu = new displaymenu(this);
    string display;
    WordFrequancy orderedDisplay = WordFrequancy(WordFrequancy::globalString);
    display = orderedDisplay.displaySortedFrequancy();
    displayMenu->printText(display);
    displayMenu->show();
}

// display the window of common words
void finalmenu::openCommonDisplaymenu()
{
    displayMenu = new displaymenu(this);
    string display;
    set<string> commonWords;
    WordFrequancy commondDisplay = WordFrequancy(WordFrequancy::globalString);
    autocorrect loadData;
    commondDisplay.displayCommonWords();
    commonWords = loadData.load("C:\\Users\alima\\Documents\\countfrequency\\CommonWords.txt");

    display = "\t\tCommon Words\n\n";
    for(auto it = commonWords.begin();it != commonWords.end();it++){
        display += "{ ";
        display += it->data();
        display += " }\n----------------------------------------------------\n\n";
    }
    displayMenu->printText(display);
    displayMenu->show();
}
