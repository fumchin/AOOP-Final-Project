#include <string>
#include <QTimer>
#include "building.h"
#include "longestpair.h"
#include "minesweeper.h"
#include "getsignature.h"
#include "shygame.h"
#include "fib.h"
#include "findfactorial.h"
#include "shortestdistance.h"
#include "add1.h"
#include "prime.h"
#include "easycity2.h"
#include "longestshorestdisstance.h"
#include "largefactorial.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtDebug>
#include "judgewindow.h"
#include <time.h>
#include <QString>
using namespace std;
Building::Building()
{

    //create floor
    floor[0] = new Floor(new LongestPair());
    floor[1] = new Floor(new Minesweeper());
    floor[2] = new Floor(new GetSignature());
    floor[3] = new Floor(new Shygame());
    floor[4] = new Floor(new Fib());
    floor[7] = new Floor(new FindFactorial());
    floor[8] = new Floor(new ShortestDistance());
    floor[9] = new Floor(new Add1());
    floor[14] = new Floor(new LargeFactorial());
    floor[24] = new Floor(new EasyCity2());
    floor[25] = new Floor(new LongestShorestDisstance());


    //JudgeWindow judge;
    judge.show();
    judge.setSeed(0);
    int n=judge.getConditionNum(); //get People data according variable n

    //create people
    judge.getInitialCondition(people);
//      query.exec("select n.* from (select * from peoplelist limit "+QString::number(n-1)+",1) as s,peoplelist as n where left(n.id,5)=left(s.id,5)");

    //course7_1
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));

}
void Building::run(int question)
{

    //0.txt
    string s = judge.getData(question,0);

    data.testdata1 = s;
    string s2 = floor[question]->p->solve(s);

    data.submit1 = s2;
    bool correct = judge.submitData(s2);
    data.correct1 = correct;
    data.spendtime1 = judge.getSpendTime();
}


void Building::startSimulation()
{
    timer->start(100);
    timer->setSingleShot(true);

//    timer->start(1000);

}

void Building::update()
{
    data.nowfloor = scheduler.getNowFloor();
    if (data.nowfloor != 0)
        this->run(data.nowfloor);
    else
        timer->stop();
    //timer->start(100);
    emit this->updateGUI();
}


