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
    long long get_pisano_period(long long);
    long long get_fibonacci_huge(long long , long long );
};

#endif // FIB_H
