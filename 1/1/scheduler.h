    #ifndef SCHEDULER_H
#define SCHEDULER_H
#include <vector>
using namespace std;

typedef struct{
    int des;
    bool inOut;
    int peopleNum;
} floorData;

class Scheduler
{
public:
    Scheduler();
    int getNowFloor();
    void getFloorArray();
private:
    vector<int> nowFloor; // temp
    int index; // temp
    vector<floorData> FloorArray;
};

#endif // SCHEDULER_H
