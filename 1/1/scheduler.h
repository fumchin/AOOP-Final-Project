#ifndef SCHEDULER_H
#define SCHEDULER_H
#include <vector>
#include "people.h"
using namespace std;

typedef struct{
    int now;
    int des;
    bool inOut;
    int peopleNum;
} floorData;

class Scheduler
{
public:
    Scheduler();
    floorData getNowFloor();
    void getFloorArray();
    void getNewFloor();
    void findPath(People *people[]);
private:
    int index; // temp
    vector<floorData> FloorArray;
    floorData *f;

};

#endif // SCHEDULER_H
