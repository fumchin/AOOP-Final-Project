#include "hexadecimalsum.h"
#include <iostream>
#include <string>
#include <sstream>
HexadecimalSum::HexadecimalSum()
{

}

string HexadecimalSum::solve(string s)
{
    stringstream ss;
    ss<<s;
    string hexStr, result;
    int maxSize = 0;
    while (ss>>hexStr)
    {
        maxSize = hexStr.size() > maxSize? hexStr.size():maxSize;
        stringDeque.push_back(hexStr);
    }

    for (int i=0; i<stringDeque.size(); i++)
        while (stringDeque[i].size() != maxSize)
            stringDeque[i] = '0' + stringDeque[i];

    int sum = 0, carry = 0;
    for (int j=maxSize-1; j>=0; j--)
    {
        for (int i=0; i<stringDeque.size(); i++)
            sum += getValue(stringDeque[i][j]);
        result = getChar(sum%16) + result;
        carry = sum/16;
        sum = carry;
    }
    if (sum%16 != 0)
        result = getChar(sum%16) + result;
//    while (sum!=0)
//    {
//        result = getChar(sum%16) + result;
//        carry = sum/16;
//        sum = carry;
//    }
    stringDeque.clear();
    return result;
}

int HexadecimalSum::getValue(char c)
{
    if (c>='0' && c<='9')
        return c-'0';
    else //if (c>='a' && c<='f')
        return 10+c-'a';
}

char HexadecimalSum::getChar(int d)
{
    if (d>=0 && d <=9)
        return d+'0';
    else //if (d>=10 && d<=15)
        return d-10+'a';
}
