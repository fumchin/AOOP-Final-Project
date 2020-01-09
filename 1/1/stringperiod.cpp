#include "stringperiod.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
StringPeriod::StringPeriod()
{

}

string StringPeriod::solve(string inputStr)
{
    string pattern;
    for (int i=1; i<inputStr.length()/2; i++)//the pattern will not be longer than half the input string
    {
        bool periodFound = true;
        pattern = inputStr.substr(0,i);
        if (inputStr.length()%pattern.length() != 0)
            continue;
        size_t startPos = 0;
        while (startPos+pattern.length() <= inputStr.length())
        {
            if (inputStr.substr(startPos, pattern.length()) != pattern)
            {
                periodFound = false;
                break;
            }
            else
                startPos += pattern.length();
        }
        if (periodFound == true)
            return to_string(pattern.length());
    }

    return to_string(inputStr.length());
}
