#include "searchwindow.h"
#include "ui_searchwindow.h"
#include <map>
#include <unordered_map>
#include <string>
#include <QString>
#include"wordfrequancy.h"
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
extern std::string globalString;
using namespace std;
searchwindow::searchwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::searchwindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &searchwindow::search);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &searchwindow::displayresults);
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
        WordFrequancy c = WordFrequancy(globalString);
        QString result, s;
        QString word = ui->textEdit->toPlainText();
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            char firstAlphabet = word.at(0).toLatin1();
            s = "Searching in file for words starting with '" + QString(firstAlphabet) + "':\n";
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
        unordered_map<string, int> myMap=c.count(globalString);
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
        if (!word.isEmpty()) {
            QFile outFile(fileName);
            if (outFile.open(QIODevice::Append | QIODevice::Text)) {
                QTextStream out(&outFile);
                out <<word<<"\n"; // Convert to QString and write to QTextStream
                outFile.close();
            } else {
                msg("Unable to open file to save word.", "error");
            }
        } else {
            msg("word is empty","error");
        }
    } else {
        msg("No file selected.", "error");
    }
}
void searchwindow::displayresults()
{
    WordFrequancy c = WordFrequancy(globalString);
    QString s =ui->textEdit_2->toPlainText();
    QString s1;
    unordered_map<string, int> myMap=c.count(globalString);
    auto it =myMap.find(s.toStdString());
    // Search in the map
    if (it != myMap.end()) {
        s1 = "Word '" + s + "' found in map with frequency: " + QString::number(it->second) + "\n";
        msgbox(s1);
    } else {
        msg("not found","error");
    }


}
