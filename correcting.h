#ifndef CORRECTING_H
#define CORRECTING_H

#include <QMainWindow>
using namespace std;
namespace Ui {
class correcting;
}

class correcting : public QMainWindow
{
    Q_OBJECT

public:
    explicit correcting(QWidget *parent = nullptr);
    ~correcting();
    void processParagraph();
    static string som;
    string search(vector<string> a, string s);
    bool like(const string &str, const string &pattern);
    string print(vector<string> tmp, string s) ;
    std::vector<std::string> splitString(const std::string& input);

private:
    Ui::correcting *ui;
};

#endif // CORRECTING_H
