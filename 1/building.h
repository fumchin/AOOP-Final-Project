#ifndef BUILDING_H
#define BUILDING_H

#include<iostream>
#include "judge.h"
#include "add1.h"
#include "data.h"
#include "floor.h"
#include "mymath.h"
#include "prime.h"
#include "problemset.h"
#include "people.h"
#include <string>
#include <qobject.h>
#include <qtimer.h>
#include <qelapsedtimer.h>
#include "scheduler.h"
using namespace std;
class Building : public QObject
{
    Q_OBJECT
public:
    Building();

    void run(int quetion);
    Data getdata(){return  data;}
    People *people[10];
    void startSimulation();

public slots:
    void update();
signals:
    void updateGUI();

private:
    Judge judge;
    Data data;
    Add1 add1;
    Prime prime;
    Floor *floor[30];
    QTimer *timer;
    Scheduler scheduler;
};


#endif // BUILDING_H
