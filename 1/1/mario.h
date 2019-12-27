#ifndef MARIO_H
#define MARIO_H
#include "mymath.h"
class Mario:public MyMath
{
public:
    Mario();
    string solve(string s);
};

#endif // MARIO_H
