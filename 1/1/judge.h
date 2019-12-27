#ifndef JUDGE_H
#define JUDGE_H
#include <string>
#include <iostream>
#include <QString>
#include <QElapsedTimer>
#include <fstream>
#include "people.h"
using namespace std;

class Judge
{
public:
    Judge() {score=0;}
    string getData(int question);
    bool submitData(string ans);
    qint64 getSpendTime(){return costtime;}
    int getScore(){return score;}

private:
    string ans;
    ifstream in;
    QElapsedTimer timer;
    qint64 costtime;
    int score;

};

#endif // JUDGE_H
