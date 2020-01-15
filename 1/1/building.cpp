#include <string>
#include <QTimer>
#include "building.h"
#include "longestpair.h"
#include "minesweeper.h"
#include "getsignature.h"
#include "shygame.h"
#include "fib.h"
#include "largestroot.h"
#include "treestructure.h"
#include "findfactorial.h"
#include "shortestdistance.h"
#include "add1.h"
#include "prime.h"
#include "mario.h"
#include "fire.h"
#include "subtract1.h"
#include "stringperiod.h"
#include "largefactorial.h"
#include "hexadecimalsum.h"
#include "commonsubstring.h"
#include "getsolution.h"
#include "palindrome.h"
#include "maze.h"
#include "easycity1.h"
#include "easycity2.h"
#include "longestshorestdisstance.h"
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
    floor[5] = new Floor(new LargestRoot());
    floor[6] = new Floor(new TreeStructure());
    floor[7] = new Floor(new FindFactorial());
    floor[8] = new Floor(new ShortestDistance());
    floor[9] = new Floor(new Add1());
    floor[10] = new Floor(new Prime());
    floor[11] = new Floor(new Mario());
    floor[12] = new Floor(new Fire());
    floor[13] = new Floor(new Subtract1());
    floor[14] = new Floor(new StringPeriod());
    floor[15] = new Floor(new LargeFactorial());
    floor[16] = new Floor(new HexadecimalSum());
    floor[17] = new Floor(new CommonSubstring());
    floor[18] = new Floor(new GetSolution());
    floor[19] = new Floor(new Palindrome());
    floor[20] = new Floor(new Maze());
    floor[21] = new Floor(new EasyCity1());
    floor[24] = new Floor(new EasyCity2());
    floor[25] = new Floor(new LongestShorestDisstance());


    //JudgeWindow judge;
    judge.show();
    judge.setSeed(1);
    int n=judge.getConditionNum(); //get People data according variable n

    //create people
    //query.exec("select n.* from (select * from peoplelist limit "+QString::number(n-1)+",1) as s,peoplelist as n where left(n.id,5)=left(s.id,5)");
    judge.getInitialCondition(people);

    //scheduler
    scheduler.findPath(people);
    data.nowfloor = 1;
    data.distance = 0;
    data.elevatorpeople = 0;

    //course7_1
    timer1 = new QTimer();
    connect(timer1, SIGNAL(timeout()), this, SLOT(update()));

}
void Building::run(int nowfloor)
{

    for(int i=0;i<scheduler.getNowFloor().peopleNum;i++){
        //test for not input question
        int times;
        string s = judge.getData(nowfloor,scheduler.getNowFloor().inOut,times);

        data.testdata1 = s;
        //give up
        string s2="";
        if(data.testdata1.compare("GIVEUP")==0){
            s2 = "";
            data.submit1 = s2;
        }
        else{
//================***testing***====================//
            times = 1;
            //10 times each testdata (時間會不斷累積)
            for(int i=0;i<times;i++){
                s2 = floor[nowfloor-1]->p->solve(s);
            }
            data.submit1 = s2;
            //送去submitdata算分數跟平均時間
            bool correct = judge.submitData(nowfloor,s2);
            data.correct1 = correct;

            cout<<"correct?: "<<data.correct1<<endl;
        }

        data.spendtime1 = judge.getSpendTime();
        //計算此時電梯裡面有幾人
        if(scheduler.getNowFloor().inOut==1) data.elevatorpeople++;
        else if(scheduler.getNowFloor().inOut==0) data.elevatorpeople--;
    }
    //將資料傳給data
    data.score+=judge.getScore();
    scheduler.getNewFloor();
    data.distance += abs(scheduler.getNowFloor().now-data.nowfloor);
    judge.getDistance(data.distance);
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
