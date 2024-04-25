#include "enter_text.h"
#include "ui_enter_text.h"

Enter_text::Enter_text(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Enter_text)
{
    ui->setupUi(this);

    // Create a QLineEdit widget
    lineEdit = new QLineEdit(this);
    lineEdit->setPlaceholderText("Enter text here"); // Set placeholder text

    // Set the position and size of the line edit widget
    lineEdit->setGeometry(50, 50, 200, 30);

    // Connect a signal from line edit to a custom slot (e.g., textChanged)
    connect(lineEdit, &QLineEdit::textChanged, this, &Enter_text::onTextChanged);
}

Enter_text::~Enter_text()
{
    delete ui;
}

void Enter_text::onTextChanged(const QString &text)
{
    // Custom slot to handle text changes in line edit
    // You can implement your logic here
    qDebug() << "Text changed: " << text;
}
