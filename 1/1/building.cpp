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
    //query.exec("select n.* from (select * from peoplelist limit "+QString::number(n-1)+",1) as s,peoplelist as n where left(n.id,5)=left(s.id,5)");
    judge.getInitialCondition(people);

    //scheduler
    scheduler.findPath(people);
    data.nowfloor = 1;

    //course7_1
    timer1 = new QTimer();
    connect(timer1, SIGNAL(timeout()), this, SLOT(update()));

}
void Building::run(int question)
{
    cout<<scheduler.getNowFloor().now<<"how many times"<<scheduler.getNowFloor().peopleNum<<endl;
    for(int i=0;i<scheduler.getNowFloor().peopleNum;i++){
        //test for not input question
        string s = judge.getData(question,scheduler.getNowFloor().inOut);
        data.testdata1 = s;
        //string s2 = floor[question]->p->solve(s);
        string s2 = "";
        data.submit1 = s2;
        bool correct = judge.submitData(s2);
        data.correct1 = correct;
        data.spendtime1 = judge.getSpendTime();

    }
    scheduler.getNewFloor();
    data.distance += abs(scheduler.getNowFloor().now-data.nowfloor);
    data.nowfloor = scheduler.getNowFloor().now;
    judge.display(scheduler.getNowFloor().now);
}


void Building::startSimulation()
{
    timer1->start(100);
    timer1->setSingleShot(true);
}

void Building::update()
{

    timer1->start(100);
    emit this->updateGUI();
}
