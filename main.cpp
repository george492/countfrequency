// main.cpp
#include "firstmenu.h"
#include <QApplication>
#include <string>
std::string globalString ;
using namespace std;
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    firstmenu mainWindow;
    mainWindow.show();

    // Create and show the new dialog

    return a.exec();
}
