#ifndef DATA_H
#define DATA_H

#include<qstring.h>
using namespace std;
class Data //: public Building
{
public:
    Data();
    int question;
    qint64 spendtime1,spendtime2;
    string testdata1,testdata2;
    string submit1,submit2;
    bool correct1,correct2;

    int score;
    int nowfloor;
};

#endif // DATA_H
