// main.cpp

#include "mainwindow.h"
#include "enter_text.h" // Include the header file for your new dialog

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();

    // Create and show the new dialog

    return a.exec();
}
