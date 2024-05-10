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
#include "datamanager.h"

using namespace std;
//string globalString; // Declare the global variable
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
    if (fileName.isEmpty()) {
        msg("No file selected.", "error");
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        msg("Unable to open file.", "error");
        return;
    }

    WordFrequancy c = WordFrequancy(DataManager::instance().getString().toStdString());
    QString result, s;
    QString word = ui->textEdit->toPlainText();
    word = word.toLower(); // Ensure word is converted to lowercase
    bool wordFoundInFile = false;
    QTextStream in(&file);
    while (!in.atEnd()) {
        result = in.readLine();
        //result.contains(word, Qt::CaseInsensitive)
        if (result.compare(word)) {
            display("Suggesting: " + result);
            wordFoundInFile = true;
            break;
        }
    }
    file.close();

    // Check if the word is already in the map
    unordered_map<string, int> myMap = c.count(DataManager::instance().getString().toStdString());
    auto it = myMap.find(word.toStdString());
    if (it != myMap.end()) {
        display(word + " found in map.");
        return;
    }

    // Save the word in the file if it's new and not found in the file
    if (!wordFoundInFile && word.length() > 1) {
        QFile outFile(fileName);
        if (outFile.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&outFile);
            out << word << "\n"; // Write to file
            outFile.close();
            display("Word '" + word + "' saved to file.");
        } else {
            msg("Unable to open file to save word.", "error");
        }
    }
}
void searchwindow::displayresults()
{
    WordFrequancy c = WordFrequancy(DataManager::instance().getString().toStdString());
    QString s =ui->textEdit_2->toPlainText();
    s.isLower();
    QString s1;
    unordered_map<string, int> myMap=c.count(DataManager::instance().getString().toStdString());
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
