#include "hexadecimalsum.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
HexadecimalSum::HexadecimalSum()
{

}

string HexadecimalSum::solve(string s)
{
    stringstream ss;
    ss<<s;
    string hexStr, result;
    while (ss>>hexStr)
    {
        list<char> tmplist;
        for (unsigned int i=0; i<hexStr.length(); i++)
            tmplist.push_front(hexStr[i]);
        listDeque.push_back(tmplist);
    }
    sort(listDeque.begin(), listDeque.end(), this->compare);

    for (int i=0; i<listDeque.size(); i++)
    {
        while (listDeque[i].size() != listDeque.front().size())
        {
            listDeque[i].push_back('0');
        }
    }

    int sum = 0, carry = 0;
    while (!listDeque.front().empty())
    {
        for (int i=0; i<listDeque.size(); i++)
        {
            sum += getValue(listDeque[i].front());
            listDeque[i].pop_front();
        }
        result = getChar(sum%16) + result;
        carry = sum/16;
        sum = carry;
    }
    result = getChar(sum%16) + result;
//    while (sum!=0)
//    {
//        result = getChar(sum%16) + result;
//        carry = sum/16;
//        sum = carry;
//    }
    return result;
}

bool HexadecimalSum::compare(list<char> list1, list<char> list2)
{
     return list1.size()>list2.size();
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
