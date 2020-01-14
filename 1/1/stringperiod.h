#ifndef STRINGPERIOD_H
#define STRINGPERIOD_H
#include "mystring.h"

class StringPeriod:public MyString
{
public:
    StringPeriod();
    string solve(string inputStr);
    virtual ~StringPeriod(){}
};

#endif // STRINGPERIOD_H
