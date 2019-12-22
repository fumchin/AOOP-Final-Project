#include "scheduler.h"

Scheduler::Scheduler()
{
//    int tempFloorArray[11] =  {1, 3, 4, 6, 9, 10, 8, 7, 5, 2, 0};
    int tempFloorArray[11] =  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0};
//    elevator algorithm
//    while
    for (int i=0; i<11; i++)
        nowFloor.push_back(tempFloorArray[i]);
    index = 0;


}

int Scheduler::getNowFloor()
{
    return nowFloor[index++];
}

void setFloorArray(int FloorArray){

}
