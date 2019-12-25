#include "getsignature.h"
#include <iostream>
#include <string>
#include <sstream>
#include <deque>
#include <vector>
#include <iterator>
using namespace std;
GetSignature::GetSignature()
{

}

string GetSignature::solve(string s)
{
    stringstream ss;
    ss<<s;
    struct assignment
    {
        int source, desination;
    };
    deque<struct assignment> streak;
    vector<deque<struct assignment>> streakVec;
    int celeNum;
    ss>>celeNum;
    int sour, dest;
    ss>>sour>>dest;
    assignment *tmpStruct = new assignment;
    tmpStruct->source = sour;
    tmpStruct->desination = dest;
    deque<struct assignment> firstDeque;
    firstDeque.push_back(*tmpStruct);
    streakVec.push_back(firstDeque);

    while (ss>>sour>>dest)
    {
        int vectorSize = streakVec.size();
        for (unsigned int i=0; i<vectorSize; i++)
        {
            bool inserted = false;
            tmpStruct = new assignment;
            tmpStruct->source = sour;
            tmpStruct->desination = dest;
//            for (unsigned int j=0; j<streakVec[i].size(); j++)
            for (deque<assignment>::iterator it=streakVec[i].begin(); it!=streakVec[i].end(); it++)
            {
                if (tmpStruct->desination == it->source)
                {
                    streakVec[i].insert(it, *tmpStruct);
                    inserted = true;
                }
            }
            if (tmpStruct->source == streakVec[i].end()->desination)
            {
                streakVec[i].push_back(*tmpStruct);
                inserted = true;
            }
            if (inserted == false)
            {
                deque<struct assignment> tmpDeque;
                tmpDeque.push_back(*tmpStruct);
                streakVec.push_back(tmpDeque);
                inserted = true;
            }
        }
    }
    return "test";
}
