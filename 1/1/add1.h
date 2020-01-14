#ifndef ADD1_H
#define ADD1_H

#include "mymath.h"
class Add1 : public MyMath
{
public:
    Add1();
    string solve(string s);
    virtual ~Add1(){}
};

#endif // ADD1_H
