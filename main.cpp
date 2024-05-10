#include <QApplication>
#include "firstmenu.h"
#include <string>
#include "autocorrect.h"
#include <set>
#include"wordfrequancy.h"
using namespace std;
//string globalString;
int main(int argc, char *argv[])
{
    WordFrequancy::loadHistoryFromFile("C:/Users/georg/Downloads/TestHistory.txt");

    WordFrequancy::clearFile("C:/Users/georg/Downloads/TestHistory.txt");

    //load;
    QApplication a(argc, argv);
     firstmenu mainWindow;
   mainWindow.show();
     // save;
    return a.exec();
}
