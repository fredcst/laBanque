#include "mainwindow.h"

#include <QApplication>

//Fonction Random
int rand50(){
    return rand()%51;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
