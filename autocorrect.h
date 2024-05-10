#ifndef AUTOCORRECT_H
#define AUTOCORRECT_H

#include <QMainWindow>
#include <set>
#include <string>
#include <regex>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
using namespace std;
namespace Ui {
class autocorrect;
}

class autocorrect : public QMainWindow
{
    Q_OBJECT

public:
    static set<string> english;
    static set<string> arabic;
    explicit autocorrect(QWidget *parent = nullptr);
    ~autocorrect();
    static std::set<std::string> load(QString fileName);
    static  void loadfromfiles();

    void search();
private:
    Ui::autocorrect *ui;
    bool like(const std::string &str, const std::string &pattern);
    std::string print(std::set<std::string> tmp,std::string s);
    std ::string search(std::string s,std::set<std::string> a);
};

#endif // AUTOCORRECT_H
