#ifndef INTEXT_H
#define INTEXT_H

#include <QDialog>

namespace Ui {
class intext;
}

class intext : public QDialog
{
    Q_OBJECT

public:
    explicit intext(QWidget *parent = nullptr);
    ~intext();

private:
    Ui::intext *ui;
};

#endif // INTEXT_H
