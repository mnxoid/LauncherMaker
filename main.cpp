#include "mainwindow.h"
#include <QApplication>
#include <unistd.h>
#include <QDebug>
//#include <QCommonStyle>
QString path;
int main(int argc, char *argv[])
{
    if(argc>1)
    {
        std::string s(argv[1]);
        path = QString::fromStdString(s);
    }
    qDebug() << path << endl << argc << endl;
    qDebug() << argv[1];
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
