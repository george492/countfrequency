// main.cpp
#include <QApplication>
#include "firstmenu.h"
#include <string>
std::string globalString;
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    firstmenu mainWindow;
    mainWindow.show();

    // Create and show the new dialog

    return a.exec();
}
