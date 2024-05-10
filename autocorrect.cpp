#include "autocorrect.h"
#include "ui_autocorrect.h"
#include <QFile>
#include <QInputDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QInputDialog>
#include <set>
#include <regex>
#include <vector>
#include <string>
using namespace std;
//std::set<std::string>  autocorrect::english;
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
/*
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
        if (!found) {
            QMessageBox::warning(this ,"Error", "Pattern not matched");
            return s;
        }   else{
            return print(tmp,s);
        }

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
string autocorrect::processParagraph( string paragraph)
{
    vector<string> words;
    string word;
    bool englis = false;
    for (char c : paragraph) {
        if (isalpha(c)) {
            word += tolower(c); // Convert to lowercase
        }
        else if (!word.empty()) {

            words.push_back(word);
            word.clear();
        }
    }
    if (!word.empty()) {

        words.push_back(word);
    }
    for(string z: words)
    {
        for (char c : z) {
            if (isEnglish(c)) {
                englis = true;
            }
        }
        if (englis)
        {
            z=print(english,z);
        }else {
            z=print(arabic,z);
        }
    }
    // Construct the modified paragraph
    string modifiedParagraph;
    for (const string& w : words) {
        modifiedParagraph += w + " "; // Add a space between words
    }
    // Remove the trailing space
    if (!modifiedParagraph.empty()) {
        modifiedParagraph.pop_back();
    }

    return modifiedParagraph;
}
*/
