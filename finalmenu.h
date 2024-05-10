#ifndef FINALMENU_H
#define FINALMENU_H

#include <QMainWindow>
#include "displaymenu.h"

namespace Ui {
class finalmenu;
}
class finalmenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit finalmenu(QWidget *parent = nullptr);
    ~finalmenu();
    void updatetext();

public slots:
    void searchwin();
    void openDisplaymenu();
    void openOrderedDisplaymenu();
    void openHistoryDisplaymenu();

private:
    Ui::finalmenu *ui;
    void on_pushButton_clicked();
    displaymenu *displayMenu;
};

#endif // FINALMENU_H
