#include "palindrome.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
Palindrome::Palindrome()
{

}

string Palindrome::solve(string s)
{
    toUpper(s);
    string newS;
    remove_copy_if(s.begin(),s.end(),back_inserter(newS),ptr_fun<int, int>(&ispunct));

    string subStr = "";
    string maxStr = "";
    int max = -1;
    for (int i=0; i<(int)newS.length()-1; i++)
    {
        for (int j=1; j<=(int)newS.length(); j++)
        {
            subStr = newS.substr(i, (size_t)j-i);
            if (subStr == reverse(subStr))
            {
                if (j-i != max)
                {
                    if (max == -1)
                    {
                        max = j-i;
                        maxStr = subStr;
                    }
                    if (j-i > max)
                    {
                        max = j-i;
                        maxStr = subStr;
                    }
                }
                else if (j-i == max)
                {
                    maxStr = {maxStr.c_str()[0]>subStr.c_str()[0]? subStr: maxStr};
                }
            }
        }
    }
    return maxStr;

}

void Palindrome::toUpper(string &s)
{
    for (int i=0; i<int(s.length()); i++)
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] += ('A' -'a');
}

string Palindrome::reverse(string s)
{
    string tempString;
    for (int i = (int)s.length()-1; i>=0; i--)
        tempString += s.c_str()[i];
    return tempString;
}
