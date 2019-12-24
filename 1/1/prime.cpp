#include "prime.h"
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;
Prime::Prime()
{
}

string Prime::solve(string s){
    stringstream ss;
    ss<<s;
    bool flag = false;
    int i;
    int n;
    string result="";

    while(ss>>n)
    {
        int diff = 0;
        //turn number into odd number

        for(i=n;i>0;i--)
        {
            flag = false;
            if(i%2 == 0)
                continue;
            for(int j=3;j<i/2;j++)
                if(i%j == 0)
                {
                    flag = true;
                    break;
                }

            if(flag == false)
            {
                diff += n-i;
                break;
                //i is prime
            }

        }
        i=n;
        while(1)
        {
            if(isPrime(i))
                break;
            i++;
        }
        diff += i-n;
        result.append(to_string(diff)+' ');
    }
    result.erase(result.length()-1);
    return result;
}

int Prime::isPrime(int n) // assuming n > 1
{
    int i,root;

    if (n%2 == 0 || n%3 == 0)
        return 0;

    root = (int)sqrt(n);

    for (i=5; i<=root; i+=6)
    {
        if (n%i == 0)
           return 0;
    }

    for (i=7; i<=root; i+=6)
    {
        if (n%i == 0)
           return 0;
    }

    return 1;
}
