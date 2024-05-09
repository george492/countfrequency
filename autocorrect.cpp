#include "autocorrect.h"
#include "ui_autocorrect.h"
#include <QFile>
#include <QInputDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QInputDialog>
#include <set>
#include <regex>
using namespace std;
std::set<std::string>  autocorrect::arabic;
std::set<std::string>  autocorrect::english;
autocorrect::autocorrect(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::autocorrect)
{
    ui->setupUi(this);
}

autocorrect::~autocorrect()
{
    delete ui;
}

std::set<std::string> autocorrect::load(QString fileName){
    std::set<std::string> s; // Use std:: prefix
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            QString fileContent = in.readAll();
            s.insert(fileContent.toStdString());
            file.close();
        }
        //else {
          //  QMessageBox::warning(this, "Error", "Failed to open file.");
         //   return -1;
       // }
    }
    return s;
}
std::string autocorrect::search(std::string s,std::set<std::string> a){
    bool found = false;
    std::set<std::string> tmp;
    if (a.find(s) != a.end()) {
        return s;
    } else {
        std::string parttern = s.substr(0, 1) + ".*" + s.substr(s.length() - 1, 1);
        for ( auto& word : a) {
            if (like(word, parttern)) {
                tmp.insert(word);
                found = true;
            }
        }
    }
    if (!found) {
        QMessageBox::warning(this ,"Error", "Pattern not matched");
        return s;
    }   else{
       return print(tmp,s);
    }
}
bool autocorrect::like(const std::string &str, const std::string &pattern) {
    regex regexPattern(pattern);
    return regex_search(str, regexPattern);
}
std::string autocorrect::print(std::set<std::string> tmp,std::string s)
{
    this->show();
    ui->textBrowser_2->setText(QString::fromStdString(s));
    if (!tmp.empty())
    {
    for(auto t:tmp)
    {
        ui->textBrowser->setText(QString::fromStdString(t));
    }
    QString userInput = QInputDialog::getText(this, "Input", "Please enter your text:");

    s = userInput.toStdString();
        return s;
        // Close the window
        close();

    }
 else {
        ui->textBrowser->setText("this isnt a common word");
        return s;
        close();
    }
}
void autocorrect::loadfromfiles()
{
  arabic =autocorrect::load("C:\\Users\\georg\\Downloads\\AllListWordArabic.txt");
  english=autocorrect::load("C:\\Users\\georg\\Downloads\\words (1).txt");

}
