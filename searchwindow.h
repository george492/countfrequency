#ifndef SEARCHWINDOW_H
#define SEARCHWINDOW_H

#include <QMainWindow>
#include <QString>
#include <string>
using namespace std;
namespace Ui {
class searchwindow;
}

class searchwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit searchwindow(QWidget *parent = nullptr);
    ~searchwindow();

private:
    Ui::searchwindow *ui;
    void search();
    void display(QString s);
    void msgbox(const QString &text);
    void msg(const QString &text, const QString &title);
    void displayresults();

};

#endif // SEARCHWINDOW_H
