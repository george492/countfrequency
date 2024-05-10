// main.cpp
#include <QApplication>
#include "firstmenu.h"
#include <string>
#include "autocorrect.h"
#include <set>
#include "WordFrequancy.h"
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

        firstmenu mainWindow;
   // autocorrect::loadfromfiles();
    mainWindow.show();

    // Create and show the new dialog

    return a.exec();
}
