#include "shortestdistance.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iomanip>
ShortestDistance::ShortestDistance()
{

}

string ShortestDistance::solve(string s){

    stringstream ss;
    ss<<s;
    int N,x,y;
    string result;
    while(ss>>N)
    {
        int counter=0;
        while (counter!=2*N && ss>>x>>y)
        {
            counter++;
            pointVec.push_back(point(x,y));
        }

        MIN = 1000000;
//        sort(pointVec.begin(), pointVec.end(), this->compareX);
        compute(0,pointVec);
        pointVec.clear();
        ostringstream Strs;
        Strs << fixed << setprecision(2) << MIN;
        result.append(Strs.str()+" ");
    }
    result.erase(result.length()-1);
    return result;
}

double ShortestDistance::compute(double totalDistance, vector<point> pVec)
{
    if (pVec.size() == 0)
    {
        MIN = totalDistance<MIN? totalDistance:MIN;
        return totalDistance;
    }
    int counter = 1;
    while (counter!=pVec.size())
//    while (counter!=(pVec.size()<6?pVec.size():6))
    {
        //calculate distance for the pair: 0 & counter
        double twoPointDistance = sqrt(pow(pVec[counter].X-pVec[0].X,2)+pow(pVec[counter].Y-pVec[0].Y,2));
        //pass the vector without the pair
        vector<point> tempVec = pVec;
        tempVec.erase(tempVec.begin()+counter);
        tempVec.erase(tempVec.begin());
        //recursive
        compute(totalDistance+twoPointDistance, tempVec);
        counter++;
    }
    return 0;
}

bool ShortestDistance::compareX(point a, point b)
{
    if (a.X > b.X)
        return 0;
    else if (a.X < b.X)
        return 1;
}
