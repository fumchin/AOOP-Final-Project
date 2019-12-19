#include "prime.h"
#include <iostream>
#include <string>
#include <sstream>
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
    while(ss>>n){
        //turn number into odd number

        if(n%2 == 0){
            n--;
        }
        for(i=n;i>0;i--){
            flag = false;
            if(i%2 == 0){
                continue;
            }
            for(int j=3;j<i/2;j++){
                if(i%j == 0){
                    flag = true;
                    break;
                }
            }
            if(flag == false){
                break;
                //i is prime
            }
        }

        result.append(to_string(i)+' ');
    }
    result.erase(result.length()-1);
    return result;
}
