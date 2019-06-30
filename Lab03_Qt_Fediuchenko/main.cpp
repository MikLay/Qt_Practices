#include "mainwindow.h"
#include "mainview.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainView v;
    v.show();

    return a.exec();
}
