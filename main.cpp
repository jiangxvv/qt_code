#include "mainwindow.h"

#include <QApplication>
#include "environment_loads.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    EnvironmentLoads env(1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, "/home/jiangxvv/Documents/qt-code/towing_project/data/semi_data");

    return a.exec();
}
