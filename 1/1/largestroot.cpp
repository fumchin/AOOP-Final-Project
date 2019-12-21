#include "largestroot.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
LargestRoot::LargestRoot()
{

}

string LargestRoot::solve(string s)
{
    stringstream ss;
    ss<<s;

    for (int i=1; i<=15; i++)
        ss >> nodeValue[i];
    for (int i=1; i<=15; i++)
        subtreeValue[i] = subTreeValue(i);

    double max = subtreeValue[0];
    int maxIndex = 0;
    for (int i=1; i<=15; i++)
        if (subtreeValue[i]>max)
        {
            max = subtreeValue[i];
            maxIndex = i;
        }

    ostringstream Strs;
    string result = "";
    Strs << fixed << setprecision(3) << max;
    result.append(Strs.str());
    return (to_string(maxIndex) + ":" + result);
}

double LargestRoot::subTreeValue(int index)
{
    if (index>=8)
        return nodeValue[index];
    else
        return nodeValue[index] + 0.5*(subTreeValue(2*index) + subTreeValue(2*index+1));
}
