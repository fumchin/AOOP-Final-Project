#ifndef PRIME_H
#define PRIME_H
#include "mymath.h"

class Prime : public MyMath
{
public:
    Prime();
    string solve(string s);
    int isPrime(int n);
};

#endif // PRIME_H
