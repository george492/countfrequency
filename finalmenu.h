#ifndef FINALMENU_H
#define FINALMENU_H

#include <QMainWindow>


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
private:
    Ui::finalmenu *ui;
      void on_pushButton_clicked();
};

#endif // FINALMENU_H
