#ifndef SCHEDULER_H
#define SCHEDULER_H
#include <vector>
using namespace std;

class Scheduler
{
public:
 Scheduler();
 int getNowFloor();
private:
 vector<int> nowFloor; // temp
 int index; // temp
};

#endif // SCHEDULER_H
