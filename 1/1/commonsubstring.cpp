#include "commonsubstring.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>
using namespace std;
CommonSubstring::CommonSubstring()
{

}

string CommonSubstring::solve(string s)
{
    stringstream ss;
    ss<<s;
    string s1,s2,newS1,newS2,result;
    ss>>s1>>s2;
    remove_copy_if(s1.begin(),s1.end(),back_inserter(newS1),ptr_fun<int, int>(&ispunct));
    remove_copy_if(s2.begin(),s2.end(),back_inserter(newS2),ptr_fun<int, int>(&ispunct));
    newS1 = capitailize(newS1);
    newS2 = capitailize(newS2);

    int maxlen = 0;
    int endingIndex = newS1.length();
    int lookup[newS1.length() + 1][newS2.length() + 1];

    memset(lookup, 0, sizeof(lookup));

    for (int i = 1; i <= newS1.length(); i++)
    {
        for (int j = 1; j <= newS2.length(); j++)
        {
            if (newS1[i - 1] == newS2[j - 1])
            {
                lookup[i][j] = lookup[i - 1][j - 1] + 1;

                if (lookup[i][j] > maxlen || lookup[i][j] == maxlen && newS1[i-lookup[i][j]] < newS1[endingIndex-maxlen])
                {
                    maxlen = lookup[i][j];
                    endingIndex = i;
                }
            }
        }
    }

    return newS1.substr(endingIndex - maxlen, maxlen);
}

string CommonSubstring::capitailize(string s)
{
    for (int i=0; i<s.length(); i++)
        if (s[i]>='a' && s[i]<='z')
            s[i] += 'A'-'a';
    return s;
}
