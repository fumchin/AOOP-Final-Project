#ifndef BUILDING_H
#define BUILDING_H

#include<iostream>
using namespace std;
#include "judge.h"
#include "data.h"
#include "floor.h"
#include "mymath.h"
#include <string>


class Building
{
public:
    Building();
    void run(int quetion);
    Data getdata(){return  data;}
private:
    Judge judge;
    Data data;
    Floor *floor[30];
};


#endif // BUILDING_H
