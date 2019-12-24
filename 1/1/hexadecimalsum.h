#ifndef HEXADECIMALSUM_H
#define HEXADECIMALSUM_H
#include "mymath.h"
#include <list>
#include <deque>
class HexadecimalSum:public MyMath
{
    deque<list<char>> listDeque;
//    enum hexValue {'a'=10, b=11, c=12, d=13, e=14, f=15};
public:
    HexadecimalSum();
    string solve(string s);
    static bool compare(list<char> list1, list<char> list2);
    int getValue(char);
    char getChar(int);
};

#endif // HEXADECIMALSUM_H
