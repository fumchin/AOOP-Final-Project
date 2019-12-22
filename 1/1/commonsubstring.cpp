#include "commonsubstring.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
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
    cout << newS1 << endl << newS2 << endl;
    for (int i=0; i<newS1.length(); i++)
    {
        string match = "";
        for (int j=0; j<newS2.length(); j++)
        {
            if (i + j < newS1.length() && newS1[i + j] == newS2[j])
                match += newS2[j];
            else
            {
                if (match.length() > result.length())
                    result = match;
                match = "";
            }
        }
    }

    return result;
}

string CommonSubstring::capitailize(string s)
{
    for (int i=0; i<s.length(); i++)
        if (s[i]>='a' && s[i]<='z')
            s[i] += 'A'-'a';
    return s;
}
