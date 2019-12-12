#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "people.h"
#include "judgewindow.h"
#include <time.h>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    JudgeWindow judge;
    judge.show();
    //w.connectDB();


    return a.exec();
}
