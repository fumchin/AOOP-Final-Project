#ifndef JUDGEWINDOW_H
#define JUDGEWINDOW_H

#include <QElapsedTimer>
#include <string>
#include <iostream>
#include <QWidget>
#include <QApplication>
#include <QLineEdit>
#include <QSqlQuery>
using namespace std;
namespace Ui {
class JudgeWindow;
}

class JudgeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit JudgeWindow(QWidget *parent = nullptr);
    ~JudgeWindow();
    string getData(int floor,int b);//input 0-26
    bool submitData(string ans);
    void setSeed(int seed){srand(seed);}
    qint64 getSpendTime(){return costtime;}
    int getConditionNum();//return 1-300
    int getDistance(){return distance;}
    void scheduleEnd();
    QLineEdit showline[27][4];

private:
    Ui::JudgeWindow *ui;
    qint64 costtime;
    int distance;
    QSqlQuery query;
    QElapsedTimer timer;
    string answer;

};

#endif // JUDGEWINDOW_H
