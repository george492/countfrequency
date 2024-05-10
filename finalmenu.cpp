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

    connect(ui->pushButton_4, &QPushButton::clicked, this, &finalmenu::openHistoryDisplaymenu);

    connect(ui->Search, &QPushButton::clicked, this, &finalmenu::searchwin);
}

finalmenu::~finalmenu()
{
    //store the history
    WordFrequancy::storeHistoryFromFile("C:/Users/alima/Documents/countfrequency/CommonWords.txt");
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
    //autocorrect *a=new autocorrect();
 //   WordFrequancy::globalString=a->processParagraph(WordFrequancy::globalString);
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

// display the window of history words
void finalmenu::openHistoryDisplaymenu()
{

    displayMenu = new displaymenu(this);
    WordFrequancy historyDisplay = WordFrequancy(WordFrequancy::globalString);
    historyDisplay.dispalyHistoryFrequancy();
    unordered_map<string,int> historyMap = historyDisplay.globalMap;
    string display = "\t    History Frequency\n\nWord\t\t\t      Frequency\n\n";

    for(auto history = historyMap.begin(); history != historyMap.end(); history++){

        display += "{ " + history->first + " }\n\t\t\t          " + to_string(history->second) + "\n----------------------------------------------------\n\n";
    }

    WordFrequancy::storeHistoryFromFile("C:/Users/alima/Documents/countfrequency/CommonWords.txt");
    displayMenu->printText(display);
    displayMenu->show();
}
