#include "shortestdistance.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
ShortestDistance::ShortestDistance()
{

}

string ShortestDistance::solve(string s){
    stringstream ss;
    ss<<s;
    int n;
    bool justStart = true;
    int counter = 0;
    int N;
    int *coor;
    string result = "";
    while(ss>>n)
    {
        if (justStart == true)
        {
            N = n;
            coor = new int[4*N];
            justStart = false;
        }
        else
        {
            coor[counter] = n;
            counter++;
            if (counter == 4*N)
            {
                for (int i=0; i<counter; i++)
                    cout << coor[i] << endl;
                counter = 0;
                delete[] coor;
                justStart = true;
            }
        }
    }

    return result;
}
