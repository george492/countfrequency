#include "finalmenu.h"
#include "displaymenu.h"
#include "mainwindow.h"
#include "ui_finalmenu.h"
#include "wordfrequancy.h"
#include "searchwindow.h"
#include "autocorrect.h"
#include "correcting.h"
#include "datamanager.h"

using namespace std;
// Now you can use 'globalString' wherever this header is included

//std::string globalString; // Declare the global variable
finalmenu::finalmenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::finalmenu)

{
    ui->setupUi(this);
    connect(ui->edit, &QPushButton::clicked, this, &finalmenu::on_pushButton_clicked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &finalmenu::openDisplaymenu);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &finalmenu::openOrderedDisplaymenu);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &finalmenu::openHistoryDisplaymenu);
    connect(ui->Search, &QPushButton::clicked, this, &finalmenu::searchwin);
}
finalmenu::~finalmenu()
{
    WordFrequancy::storeHistoryFromFile("C:/Users/georg/Downloads/TestHistory.txt");
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
    correcting *a = new correcting();
    a->processParagraph();
    this->hide();
    M->setLabelText();
    M->show();
}
void finalmenu::updatetext()
{

    ui->textBrowser->setText(DataManager::instance().getString());
}

// display the window of unordered frequency
void finalmenu::openDisplaymenu()
{
    displayMenu = new displaymenu(this);
    string display;
    WordFrequancy unorderedDisplay = WordFrequancy(DataManager::instance().getString().toStdString());
    display = unorderedDisplay.displayFrequancy();
    displayMenu->printText(display);
    displayMenu->show();
}

// display the window of ordered frequency
void finalmenu::openOrderedDisplaymenu()
{
    displayMenu = new displaymenu(this);
    string display;
    WordFrequancy orderedDisplay = WordFrequancy(DataManager::instance().getString().toStdString());
    display = orderedDisplay.displaySortedFrequancy();
    displayMenu->printText(display);
    displayMenu->show();
}
// display the window of history words
void finalmenu::openHistoryDisplaymenu()
{

    displayMenu = new displaymenu(this);
    WordFrequancy historyDisplay = WordFrequancy(DataManager::instance().getString().toStdString());
    historyDisplay.dispalyHistoryFrequancy();
    unordered_map<string,int> historyMap = historyDisplay.globalMap;
    string display = "\t    History Frequency\n\nWord\t\t\t      Frequency\n\n";

    for(auto history = historyMap.begin(); history != historyMap.end(); history++){

        display += "{ " + history->first + " }\n\t\t\t          " + to_string(history->second) + "\n----------------------------------------------------\n\n";
    }

    WordFrequancy::storeHistoryFromFile("C:/Users/georg/Downloads/TestHistory.txt");
    displayMenu->printText(display);
    displayMenu->show();
}
