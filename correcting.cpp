#include "correcting.h"
#include "ui_correcting.h"
#include <QFile>
#include <QInputDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QInputDialog>
#include <set>
#include <QDebug>
#include <regex>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include "wordfrequancy.h"
#include "finalmenu.h"
#include "datamanager.h"

using namespace std;
 //string globalString;
bool found = false;
vector<string> words, tmp;
correcting::correcting(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::correcting)
{
    ui->setupUi(this);
}

correcting::~correcting()
{
    delete ui;
}
void correcting::processParagraph() {
    string s;
    for (auto& pair : WordFrequancy::globalMap) {
        tmp.push_back(pair.first);
    }

    words=correcting::splitString(DataManager::instance().getString().toStdString());

    for (string &w : words) {
        w = search(tmp, w);
        s += w + " ";
    }
   // if (!s.empty()) {
     //   s.pop_back();
    //}
    DataManager::instance().setString(QString::fromStdString(s));

}
string correcting::search(vector<string> a, string s) {
    vector<string> tmp;

    auto it = std::find(a.begin(), a.end(), s);
    if (it != a.end()) {
        return s;
    }
    for (const auto& word : a) {
        if (like(word, s)) {
            tmp.push_back(word);
            found = true;
        }
    }

    if (found) {
        return print(tmp, s);

    } else {
     return s;
    }
}

bool correcting::like(const string &str, const string &pattern) {
    return str.find(pattern) != string::npos;
}

string correcting::print(vector<string> tmp, string s) {
    this->show();
   ui->textBrowser_2->setText(QString::fromStdString(s));

    if (!tmp.empty()) {
        QString suggestions;
        for (auto t : tmp) {
            suggestions += QString::fromStdString(t) + "\n"; // Display suggestions in separate lines
        }
        ui->textBrowser->setText(suggestions);
    }

    QString userInput = QInputDialog::getText(this, "Input", "Please enter your text:");

    this->close();
    return userInput.toStdString();

}
std::vector<std::string> correcting::splitString(const std::string& input) {
    std::istringstream iss(input);
    std::vector<std::string> words(std::istream_iterator<std::string>{iss},
                                   std::istream_iterator<std::string>());

    return words;
}
