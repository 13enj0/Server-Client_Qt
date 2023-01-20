#include "mainwindow.h"
#include "registr.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;

    Registr s;
    s.show();
    return a.exec();
}
