#ifndef LARGESTROOT_H
#define LARGESTROOT_H
#include "mytree.h"

class LargestRoot:public MyTree
{
    double nodeValue[16], subtreeValue[16];
public:
    LargestRoot();
    string solve(string s);
    double subTreeValue(int);
    virtual ~LargestRoot(){};
};

#endif // LARGESTROOT_H
