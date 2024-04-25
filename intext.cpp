#include "intext.h"
#include "ui_intext.h"

intext::intext(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::intext)
{
    ui->setupUi(this);
}

intext::~intext()
{
    delete ui;
}
