#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "people.h"
#include "judgewindow.h"
#include <time.h>

int main(int argc, char *argv[])
{
    //connect database
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    database.setUserName("root");
    database.setPassword("123456789");
    database.setPort(3306);
    bool ok = database.open();
    if(ok){
        qDebug()<<"Connected!!";
    }
    else{
        qDebug()<<"fail to connect";
    }

    QApplication a(argc, argv);
    MainWindow w;
    //w.connectDB();
    w.show();



//    judge.show();
//    //w.connectDB();


    return a.exec();
}
