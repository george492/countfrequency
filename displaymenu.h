#ifndef DISPLAYMENU_H
#define DISPLAYMENU_H

#include <QMainWindow>
#include <iostream>
using namespace std;


namespace Ui {
class displaymenu;
}

class displaymenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit displaymenu(QWidget *parent = nullptr);
    ~displaymenu();
    void printText(string);


private:
    Ui::displaymenu *ui;
};

#endif // DISPLAYMENU_H
