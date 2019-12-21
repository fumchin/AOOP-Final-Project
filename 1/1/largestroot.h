#ifndef LARGESTROOT_H
#define LARGESTROOT_H
#include "mymath.h"

class LargestRoot:public MyMath
{
    double nodeValue[16], subtreeValue[16];
public:
    LargestRoot();
    string solve(string s);
    double subTreeValue(int);
};

#endif // LARGESTROOT_H
