#ifndef SHORTESTDISTANCE_H
#define SHORTESTDISTANCE_H
#include "mymath.h"
struct point
{
    int X,Y;
};

class ShortestDistance: public MyMath
{
public:
    ShortestDistance();
    string solve(string s);
    static bool compareX(point a, point b);
    static bool compareY(point a, point b);
    double rounding(double num, int index);
    virtual ~ShortestDistance(){}

};

#endif // SHORTESTDISTANCE_H
