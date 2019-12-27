#include "shortestdistance.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
ShortestDistance::ShortestDistance()
{

}

string ShortestDistance::solve(string s){

    stringstream ss;
    ss<<s;
    int n, x, y, N;
    bool justStart = true;
    int counter = 0;
    string result = "";
    while (justStart == true)
    {
        vector<point> pointVect;
        justStart = false;
        ss >> n;
        N = n;
        //cout << "N: " << N << endl << endl;
        while (counter != 2*N && ss>>x>>y)
        {
            counter ++;
            struct point tempPoint;
            tempPoint.X = x;
            tempPoint.Y = y;
            pointVect.push_back(tempPoint);
            if (counter == 2*N)
                break;
        }
        if (counter == 2*N)
        {
            vector<point> tempVect = pointVect;
            //sort by x
            sort(pointVect.begin(), pointVect.end(), this->compareX);
//            for (int k=0; k<pointVect.size(); k++)
//                cout << k+1 << " " << pointVect[k].X << " " << pointVect[k].Y << endl;

            double totalMinDistance = 0;
            while (pointVect.size() != 0)
            {
                int i = 0;
//                    cout << "contents: ";
//                    for (int k=0; k<pointVect.size(); k++)
//                        cout << pointVect[k].X << " " << pointVect[k].Y << " ";
//                    cout << endl;

                    int removeIndex = i+1;
                    double minDistance = pow(pointVect[i].X-pointVect[i+1].X ,2)+pow(pointVect[i].Y-pointVect[i+1].Y ,2);
                    for (int j=1; j<pointVect.size(); j++)
                    {
//                        cout << "i: " << i << " j: " << j << " " << minDistance << endl;
                        if (pow(pointVect[i].X-pointVect[j].X ,2)+pow(pointVect[i].Y-pointVect[j].Y ,2) < minDistance)
                        {
                            minDistance = pow(pointVect[i].X-pointVect[j].X ,2)+pow(pointVect[i].Y-pointVect[j].Y ,2);
                            removeIndex = j;
                        }
                    }
//                    cout << "distance: " << minDistance << " i: " << i <<  " removeIndex: " << removeIndex;
                    totalMinDistance += sqrt(minDistance);
                    pointVect.erase(pointVect.begin()+removeIndex);
                    pointVect.erase(pointVect.begin()+i);
//                    cout << " size: " << pointVect.size() << endl;
                    if (pointVect.size() == 0)
                        break;
            }
            pointVect.clear();

            pointVect = tempVect;
            //sort by y
            sort(pointVect.begin(), pointVect.end(), this->compareY);
//            for (int k=0; k<pointVect.size(); k++)
//                cout << k+1 << " " << pointVect[k].X << " " << pointVect[k].Y << endl;

            double totalMinDistance2 = 0;
            while (pointVect.size() != 0)
            {
                int i = 0;
//                    cout << "contents: ";
//                    for (int k=0; k<pointVect.size(); k++)
//                        cout << pointVect[k].X << " " << pointVect[k].Y << " ";
//                    cout << endl;

                    int removeIndex = i+1;
                    double minDistance = pow(pointVect[i].X-pointVect[i+1].X ,2)+pow(pointVect[i].Y-pointVect[i+1].Y ,2);
                    for (int j=1; j<pointVect.size(); j++)
                    {
//                        cout << "i: " << i << " j: " << j << " " << minDistance << endl;
                        if (pow(pointVect[i].X-pointVect[j].X ,2)+pow(pointVect[i].Y-pointVect[j].Y ,2) < minDistance)
                        {
                            minDistance = pow(pointVect[i].X-pointVect[j].X ,2)+pow(pointVect[i].Y-pointVect[j].Y ,2);
                            removeIndex = j;
                        }
                    }
//                    cout << "distance: " << minDistance << " i: " << i <<  " removeIndex: " << removeIndex;
                    totalMinDistance2 += sqrt(minDistance);
                    pointVect.erase(pointVect.begin()+removeIndex);
                    pointVect.erase(pointVect.begin()+i);
//                    cout << " size: " << pointVect.size() << endl;
                    if (pointVect.size() == 0)
                        break;
            }
            pointVect.clear();

            pointVect = tempVect;
            double totalMinDistance3 = 0;
            while (pointVect.size() != 0)
            {
                int i = 0;
//                    cout << "contents: ";
//                    for (int k=0; k<pointVect.size(); k++)
//                        cout << pointVect[k].X << " " << pointVect[k].Y << " ";
//                    cout << endl;

                    int removeIndex = i+1;
                    double minDistance = pow(pointVect[i].X-pointVect[i+1].X ,2)+pow(pointVect[i].Y-pointVect[i+1].Y ,2);
                    for (int j=1; j<pointVect.size(); j++)
                    {
//                        cout << "i: " << i << " j: " << j << " " << minDistance << endl;
                        if (pow(pointVect[i].X-pointVect[j].X ,2)+pow(pointVect[i].Y-pointVect[j].Y ,2) < minDistance)
                        {
                            minDistance = pow(pointVect[i].X-pointVect[j].X ,2)+pow(pointVect[i].Y-pointVect[j].Y ,2);
                            removeIndex = j;
                        }
                    }
//                    cout << "distance: " << minDistance << " i: " << i <<  " removeIndex: " << removeIndex;
                    totalMinDistance3 += sqrt(minDistance);
                    pointVect.erase(pointVect.begin()+removeIndex);
                    pointVect.erase(pointVect.begin()+i);
//                    cout << " size: " << pointVect.size() << endl;
                    if (pointVect.size() == 0)
                        break;
            }
            pointVect.clear();

//            cout << totalMinDistance << " " << totalMinDistance2 << " "<< totalMinDistance3 << endl;
            double Min = totalMinDistance<totalMinDistance2? totalMinDistance : totalMinDistance2;
            Min = totalMinDistance3 < Min ? totalMinDistance3 : Min;
            Min = rounding(Min, 2);
//            cout << Min << endl;
            ostringstream strs;
            strs << Min;
            result.append(strs.str());
            result.append(" ");
//            cout << "enter reset block" << endl;
            counter = 0;
            justStart = true;
            N = -1;
            n = -1;
        }
    }
    result.erase(result.length()-1);

    return result;
}

bool ShortestDistance::compareX(point a, point b)
{
    if (a.X > b.X)
        return 0;
    else if (a.X < b.X)
        return 1;
    else
    {

        if (a.Y > b.Y)
            return 0;
        else if (a.Y < b.Y)
            return 1;
    }
}

bool ShortestDistance::compareY(point a, point b)
{
    if (a.Y > b.Y)
        return 0;
    else if (a.Y < b.Y)
        return 1;
    else
    {
        if (a.X > b.X)
            return 0;
        else if (a.X < b.X)
            return 1;
    }
}

double ShortestDistance::rounding(double num, int index)
{
    bool isNegative = false; // whether is negative number or not

    if(num < 0) // if this number is negative, then convert to positive number
    {
        isNegative = true;
        num = -num;
    }

    if(index >= 0)
    {
        int multiplier;
        multiplier = pow(10, index);
        num = (int)(num * multiplier + 0.5) / (multiplier * 1.0);
    }

    if(isNegative) // if this number is negative, then convert to negative number
    {
        num = -num;
    }

    return num;
}
