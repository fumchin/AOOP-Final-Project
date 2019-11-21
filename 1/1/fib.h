#ifndef FIB_H
#define FIB_H
#include <string>
#include "mymath.h"


class Fib : public MyMath
{
public:
    Fib();
    string solve(string s);
};

#endif // FIB_H
