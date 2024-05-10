#include "searchwindow.h"
#include "ui_searchwindow.h"
#include "WordFrequancy.h"
#include <map>
#include <unordered_map>
#include <string>
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
using namespace std;
searchwindow::searchwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::searchwindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &searchwindow::search);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &searchwindow::displayresults);
    connect(ui->close, &QPushButton::clicked, this, &searchwindow::close);

}
void searchwindow::display(QString s)
{
 ui->Searchresults->setText(s);
}
void searchwindow::msgbox(const QString &text)
{
        QMessageBox::information(this, "msg", text);
}
void searchwindow::msg(const QString &text, const QString &title) {
    QMessageBox::warning(this, title, text);
}
searchwindow::~searchwindow()
{
    delete ui;
}
void searchwindow::search() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", QDir::homePath());
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        WordFrequancy c = WordFrequancy(WordFrequancy::globalString);
        QString result, s;
        QString word = ui->textEdit->toPlainText();
        word = word.toLower(); // Ensure word is converted to lowercase
        bool wordFoundInFile = false;
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            QChar firstAlphabet = word.at(0);
            s = "Searching in file for words starting with " + QString(firstAlphabet) + "':\n";
            display(s);
            while (!in.atEnd()) {
                result = in.readLine();
                if (result.contains(word, Qt::CaseInsensitive)) {
                    display(result + " found");
                    wordFoundInFile = true;
                }
            }
            file.close();
        } else {
            msg("Unable to open file.", "error");
            return;
        }

        // Check if word found in map
        unordered_map<string, int> myMap = c.count(WordFrequancy::globalString);
        auto it = myMap.find(word.toStdString());
        if (it != myMap.end()) {
            s = "Word '" + word + "' found in map\n";
            display(s);
        }

        // Save the word in the file if it's new
        if (!word.isEmpty() && word.length() > 1 && !wordFoundInFile) {
            QFile outFile(fileName);
            if (outFile.open(QIODevice::Append | QIODevice::Text)) {
                QTextStream out(&outFile);
                out << word << "\n"; // Convert to QString and write to QTextStream
                outFile.close();
            } else {
                msg("Unable to open file to save word.", "error");
            }
        } else if (wordFoundInFile) {
            msg("Word found in the file.", "info");
        } else {
            msg("Word is too short or already exists in the file.", "info");
        }
    } else {
        msg("No file selected.", "error");
    }
}
void searchwindow::displayresults()
{
    WordFrequancy c = WordFrequancy(WordFrequancy::globalString);
    QString s =ui->textEdit_2->toPlainText();
    s.isLower();
    QString s1;
    unordered_map<string, int> myMap=c.count(WordFrequancy::globalString);
    auto it =myMap.find(s.toStdString());
    // Search in the map
    if (it != myMap.end() ) {
        s1 = "Word '" + QString::fromStdString(it->first) + "' found in map with frequency: " + QString::number(it->second) + "\n";
        msgbox(s1);
    } else {
        msg("not found","error");
    }


}
void searchwindow::close(){
    this->hide();
}
/*    QString fileName = QFileDialog::getOpenFileName(this, "Open File", QDir::homePath());
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        WordFrequancy c = WordFrequancy(WordFrequancy::globalString);
        QString result, s;
        QString word = ui->textEdit->toPlainText();
        word.isLower();
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            QChar firstAlphabet = word.at(0);
            s = "Searching in file for words starting with " + QString(firstAlphabet) + "':\n";
            display(s);
            while (!in.atEnd()) {
                result = in.readLine();
                if (result.contains(firstAlphabet)) {
                    display(result);
                }
            }
            file.close();
        } else {
            msg("Unable to open file.", "error");
            return;
        }

        //======================================================================================================

        // Search in the map
        unordered_map<string, int> myMap=c.count(WordFrequancy::globalString);
        auto it =myMap.find(word.toStdString());
        if (it != myMap.end()) {
            s = "Word '" + word + "\n";
            display(s) ;
        }
        //else {
          //  msg("not found","error");
       // }

        //======================================================================================================

        // Save the word in the file if it's new
        if (!word.isEmpty()&& word.length()>1) {
            QFile outFile(fileName);
            if (outFile.open(QIODevice::Append | QIODevice::Text)) {
                QTextStream out(&outFile);
                out <<word<<"\n"; // Convert to QString and write to QTextStream
                outFile.close();
            } else {
                msg("Unable to open file to save word.", "error");
            }
        } else {
            msg("word is too short","error");
        }
    } else {
        msg("No file selected.", "error");
    }*/
