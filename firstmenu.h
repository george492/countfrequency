#ifndef FIRSTMENU_H
#define FIRSTMENU_H

#include <QMainWindow>

namespace Ui {
class firstmenu;
}

class firstmenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit firstmenu(QWidget *parent = nullptr);
    ~firstmenu();

private:
    Ui::firstmenu *ui;
    void on_submitButton_clicked();
    void on_loadButton_clicked();
};

#endif // FIRSTMENU_H
