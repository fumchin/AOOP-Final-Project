#include "longestpair.h"
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <math.h>
#include <vector>
#include <iomanip>
using namespace std;

LongestPair::LongestPair()
{

}

string LongestPair::solve(string s){
    stringstream ss;
    ss<<s;
    double x,y,z;
    int counter = 0;
    vector<double> xVec, yVec, zVec;
    while(ss>>x>>y>>z)
    {
        xVec.push_back(x);
        yVec.push_back(y);
        zVec.push_back(z);
        counter++;
    }

    cout << "counter: " << counter << endl;
    for (int j=0; j< counter; j++)
    {
        cout << xVec[j] << " " << yVec[j]  << " " << zVec[j] << endl;
    }

    double max = sqrt(pow(xVec[1]-xVec[0],2)+pow(yVec[1]-yVec[0],2)+pow(zVec[1]-zVec[0],2));
    double min = sqrt(pow(xVec[1]-xVec[0],2)+pow(yVec[1]-yVec[0],2)+pow(zVec[1]-zVec[0],2));
    for (int i=0; i<counter-1; i++)
    {
        for (int j=i+1; j<counter; j++)
        {
            if(sqrt(pow(xVec[j]-xVec[i],2)+pow(yVec[j]-yVec[i],2)+pow(zVec[j]-zVec[i],2)) > max)
                max = sqrt( pow(xVec[j]-xVec[i],2)+pow(yVec[j]-yVec[i],2)+pow(zVec[j]-zVec[i],2) );
            if(sqrt(pow(xVec[j]-xVec[i],2)+pow(yVec[j]-yVec[i],2)+pow(zVec[j]-zVec[i],2)) < min)
                min = sqrt( pow(xVec[j]-xVec[i],2)+pow(yVec[j]-yVec[i],2)+pow(zVec[j]-zVec[i],2) );
        }
    }
    ostringstream minStrs;
    cout << "min before: " << min << " after ";
    min = floor(min*100)/100;//set precision to 2 manually
    minStrs << min;
    cout << min << endl;
    string result = minStrs.str();

    ostringstream maxStrs;
    cout << "max before: " << max << " after ";
    max = floor(max*100)/100;//set precision to 2 manually
    maxStrs << max;
    cout << max << endl;
    result.append(" " + maxStrs.str());
    return result;
}
