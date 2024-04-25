#ifndef ENTER_TEXT_H
#define ENTER_TEXT_H

#include <QMainWindow>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui {
class Enter_text;
}
QT_END_NAMESPACE

class Enter_text : public QMainWindow
{
    Q_OBJECT

public:
    Enter_text(QWidget *parent = nullptr);
    ~Enter_text();

private:
    Ui::Enter_text *ui;
    QLineEdit *lineEdit; // Add a pointer to QLineEdit
};

#endif // ENTER_TEXT_H
