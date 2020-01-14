#ifndef HEXADECIMALSUM_H
#define HEXADECIMALSUM_H
#include "mymath.h"
#include <list>
#include <deque>
#include <string>
class HexadecimalSum:public MyMath
{
    deque<string> stringDeque;
public:
    HexadecimalSum();
    string solve(string s);
    int getValue(char);
    char getChar(int);
    virtual ~HexadecimalSum(){}
};

#endif // HEXADECIMALSUM_H
