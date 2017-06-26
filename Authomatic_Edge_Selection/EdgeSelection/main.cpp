#include "mainwindow.h"
#include "../build/ui_mainwindow.h"
#include <QApplication>

MainWindow *w;
using namespace pcl;

//PointCloudT::Ptr cloud (new PointCloudT);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    w = new MainWindow;
    w->show();

    return a.exec();
}





