#include "mario.h"
#include <iostream>
#include <sstream>
using namespace std;
Mario::Mario()
{

}

string Mario::solve(string s)
{
    stringstream ss;
    ss<<s;
    int N;
    ss>>N;

    int coin;
    int last = 0, sum = 0, count = 0;
    while (ss>>coin)
    {
        if (sum >= coin)
            sum = sum - last + coin;
        else
        {
            sum += coin;
            ++count;
        }

        last = coin;
    }
    return to_string(count);
}
