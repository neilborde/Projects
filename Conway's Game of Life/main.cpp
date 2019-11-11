#include "plotwindow.h"
#include <QApplication>


//Neil Borde
//Homework 4
//Conway's game of life simulator
//Needs no arguments to run


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PlotWindow w;
    w.show();

    return a.exec();
}
