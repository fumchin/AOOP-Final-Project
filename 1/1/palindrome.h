#ifndef PALINDROME_H
#define PALINDROME_H
#include "mystring.h"

class Palindrome:public MyString
{
public:
    Palindrome();
    string solve(string s);
    void toUpper(string &s);
    string reverse(string s);
    virtual ~Palindrome(){}
};

#endif // PALINDROME_H
