#include "findfactorial.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
FindFactorial::FindFactorial()
{

}

string FindFactorial::solve(string s){
    stringstream ss;
    ss<<s;
    int n;
    string result = "";
    int count = 0;
    int temp;
    while(ss>>n){
        count = 0;
        for(int i=2;i<=n+5;i++){    //range of n
            temp = i;
            for(int j =2;j<=i;j++){
                while(temp % j==0 && temp>1){
                    count++;
                    temp = temp / j;
                }
                if(count>n){
                    break;
                }
            }
            if(count == n){
                result.append(to_string(i)+"! ");
                break;
            }
            else if( count > n){
                result.append("N ");
                break;
            }
        }
    }
    result.erase(result.length()-1);
    return result;
}
