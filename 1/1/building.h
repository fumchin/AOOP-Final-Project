#ifndef BUILDING_H
#define BUILDING_H

#include<iostream>
using namespace std;
#include "judge.h"
#include "add1.h"
#include "data.h"
#include "mymath.h"
#include "prime.h"
#include <string>


class Building
{
public:
    Building();
    void run();
    Data getdata(){return  data;}
private:
    Judge judge;
    Data data;
    Add1 add1;
    Prime prime;
};


#endif // BUILDING_H
