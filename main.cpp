#include <QApplication>
#include "firstmenu.h"
#include <string>
#include <set>
#include"wordfrequancy.h"
using namespace std;
//string globalString;
int main(int argc, char *argv[])
{
    WordFrequancy::loadHistoryFromFile("C:/Users/georg/Downloads/c.txt");
    //load;
    QApplication a(argc, argv);
     firstmenu mainWindow;
   mainWindow.show();
     // save;
    return a.exec();
}
