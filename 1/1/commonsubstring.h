#ifndef COMMONSUBSTRING_H
#define COMMONSUBSTRING_H
#include "mystring.h"

class CommonSubstring:public MyString
{
public:
    CommonSubstring();
    string solve(string s);
    string capitailize(string s);
    virtual ~CommonSubstring(){}
};

#endif // COMMONSUBSTRING_H
