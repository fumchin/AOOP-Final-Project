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

    //X = newS1, Y = newS2, m = newS1.length(), n = newS2.length()
    int maxlen = 0;			// stores the max length of LCS
    int endingIndex = newS1.length();	// stores the ending index of LCS in X

    // lookup[i][j] stores the length of LCS of substring
    // X[0..i-1], Y[0..j-1]
    int lookup[newS1.length() + 1][newS2.length() + 1];

    // initialize all cells of lookup table to 0
    memset(lookup, 0, sizeof(lookup));

    // fill the lookup table in bottom-up manner
    for (int i = 1; i <= newS1.length(); i++)
    {
        for (int j = 1; j <= newS2.length(); j++)
        {
            // if current character of newS1 and newS2 matches
            if (newS1[i - 1] == newS2[j - 1])
            {
                lookup[i][j] = lookup[i - 1][j - 1] + 1;

                // update the maximum length and ending index
                if (lookup[i][j] > maxlen)
                {
                    maxlen = lookup[i][j];
                    endingIndex = i;
                }
            }
        }
    }

    // return Longest common substring having length maxlen
    return newS1.substr(endingIndex - maxlen, maxlen);
}

string CommonSubstring::capitailize(string s)
{
    for (int i=0; i<s.length(); i++)
        if (s[i]>='a' && s[i]<='z')
            s[i] += 'A'-'a';
    return s;
}
