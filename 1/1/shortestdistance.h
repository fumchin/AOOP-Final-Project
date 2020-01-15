#ifndef SHORTESTDISTANCE_H
#define SHORTESTDISTANCE_H
#include "mymath.h"
#include <vector>
class ShortestDistance: public MyMath
{
    struct point
    {
        int X,Y;
        point(int x, int y){X=x; Y=y;}
    };
    vector<point> pointVec;
    double MIN;
public:
    ShortestDistance();
    string solve(string s);
    double compute(double, vector<point>);
    static bool compareX(point a, point b);
};

#endif // SHORTESTDISTANCE_H
