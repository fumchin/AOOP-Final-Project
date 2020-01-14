#ifndef FINDFACTORIAL_H
#define FINDFACTORIAL_H
#include "mymath.h"


class FindFactorial : public MyMath
{
public:
    FindFactorial();
    string solve(string s);
    virtual ~FindFactorial(){}
};

#endif // FINDFACTORIAL_H
