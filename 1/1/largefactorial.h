#ifndef LARGEFACTORIAL_H
#define LARGEFACTORIAL_H
#include "mymath.h"

class LargeFactorial : public MyMath
{
public:
    LargeFactorial();
    string solve(string s);
    virtual ~LargeFactorial(){}
};

#endif // LARGEFACTORIAL_H
