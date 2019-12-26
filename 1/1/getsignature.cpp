#include "getsignature.h"
#include <iostream>
#include <string>
#include <sstream>
#include <deque>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
GetSignature::GetSignature()
{

}

string GetSignature::solve(string s)
{
    stringstream ss;
    ss<<s;

//    deque<struct assignment> streak;
    vector<deque<struct assignment>> dequeVec;//store every streak of assignments
    int celebrityNum;
    ss>>celebrityNum;

    int sour, dest;
    ss>>sour>>dest;

    deque<struct assignment> firstDeque;
    firstDeque.push_back(assignment(sour, dest));
    dequeVec.push_back(firstDeque);

    while (ss>>sour>>dest)
    {
        bool inserted = false;

        unsigned int numOfStreak = dequeVec.size();
        for (unsigned int i=0; i<numOfStreak; i++)
        {
            if (sour == (dequeVec[i].end()-1)->desination)
            {
                dequeVec[i].push_back(assignment(sour,dest));
                inserted = true;
            }
            else
            {
                for (deque<assignment>::iterator it=dequeVec[i].begin(); it!=dequeVec[i].end(); it++)
                {
                    if (dest == it->source )
                    {
                        if (it == dequeVec[i].begin())//insert in the beginning
                        {
                            dequeVec[i].insert(it, assignment(sour,dest));
                            inserted = true;
                            break;
                        }
                        else if (dest != (it-1)->desination)//沒有同樣的人指向destination
                        {
                            dequeVec[i].insert(it, assignment(sour,dest));
                            inserted = true;
                            break;
                        }
                        else//有同樣的人指向destination
                        {
                            deque<struct assignment> newDeque;
                            copy(dequeVec[i].begin(), it-1, newDeque.begin());
                            newDeque.push_back(assignment(sour,dest));
                            newDeque.push_back(*it);
                            dequeVec.push_back(newDeque);
                            inserted = true;
                            break;
                        }
                    }
                }
            }

        }
        if (inserted == false)
        {
            deque<struct assignment> newDeque;
            newDeque.push_back(assignment(sour,dest));
            dequeVec.push_back(newDeque);
            inserted = true;
        }
    }

    int maxLength=0;
    int smallestStarter=-1;
    for (unsigned int i=0; i<dequeVec.size(); i++)
    {
        if (dequeVec[i].size()>maxLength)
        {
            maxLength = dequeVec[i].size();
            smallestStarter = dequeVec[i].front().source;
        }
        else if (dequeVec[i].size() == maxLength)
        {
            if (dequeVec[i].front().source < smallestStarter)
                smallestStarter = dequeVec[i].front().source;
        }
    }
    return to_string(smallestStarter);
}
