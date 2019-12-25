#ifndef FIB_H
#define FIB_H
#include <string>
#include "mymath.h"


class Fib : public MyMath
{
public:
    Fib();
    string solve(string s);
    void fib_last_digit(int*,long long int);
    int find_last_digit(int*,long long int);
    int shift(long long int);
};

#endif // FIB_H
