#include "add1.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

Add1::Add1()
{

}

string Add1::solve(string s){
    stringstream ss;
    ss<<s;
    int n;
    string result="";
    while(ss>>n){
        result.append(to_string(n+1)+' ');
    }
    result.erase(result.length()-1);
    return result;
}
