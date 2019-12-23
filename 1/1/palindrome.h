#ifndef PALINDROME_H
#define PALINDROME_H
#include "mymath.h"

class Palindrome:public MyMath
{
public:
    Palindrome();
    string solve(string s);
    void toUpper(string &s);
    string reverse(string s);
};

#endif // PALINDROME_H
