#include "longestpair.h"
#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <math.h>
#include <QDebug>
using namespace std;
#define maxSize 10000
LongestPair::LongestPair()
{

}

string LongestPair::solve(string s){
    stringstream ss;
    ss<<s;
    double n;
    double longest;
    double max;
    int counter = 0;
    double x[maxSize],y[maxSize],z[maxSize];

    while(ss>>n){
        //turn number into odd number
        if (counter%3 == 0)
            x[counter/3] = n;
        else if (counter%3 == 1)
            y[counter/3] = n;
        else if (counter%3 == 2)
            z[counter/3] = n;
        counter++;
    }

    cout << "counter: " << counter << endl;
    for (int j=0; j< counter/3; j++)
    {
        cout << x[j] << " " << y[j]  << " " << z[j] << endl;
    }

    max = sqrt(pow(x[1]-x[0],2)+pow(y[1]-y[0],2)+pow(z[1]-z[0],2));
    for (int i=0; i< counter/3-1; i++)
    {
        for (int j=i+1; j< counter/3; j++)
        {
            if(sqrt(pow(x[j]-x[i],2)+pow(y[j]-y[i],2)+pow(z[j]-z[i],2)) > max)
                max = sqrt( pow(x[j]-x[i],2)+pow(y[j]-y[i],2)+pow(z[j]-z[i],2) );
        }
    }
    ostringstream strs;
    max = floor(max*100)/100;//set precision to 2 manually
    strs << max;
    cout << max << endl;
    string result = strs.str();
    return result;
}
