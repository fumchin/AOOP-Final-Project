#include "fib.h"
#include <iostream>
#include <sstream>
#include <string>
#include <math.h>

//solved by Pisano period
using namespace std;
Fib::Fib()
{

}

void Fib::fib_last_digit(int *f,long long int n){
    f[0]=0;
    f[1]=1;
    for(int i=2;i<n;i++){
        f[i] = (f[i-1]+f[i-2])%10;
    }
}

int Fib::find_last_digit(int *f,long long int n){
    return f[n];
}

//int Fib::shift(long long int n){
//    int f0=0,f1=1;
//    int result=1;
//    for(int i=2;i<=n;i++){
//        result = f0+f1;
//        if(result>=60){
//            result-=60;
//        }
//        //result = ((f0%60)+(f1%60))%60;
//        if(f1>=60) f0 = f1 - 60;
//        else f0 = f1;
//        f1 = result;
//    }
//    return  result;
//}


long long Fib::get_pisano_period(long long m) {
    long long a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
}

long long Fib::get_fibonacci_huge(long long n, long long m) {
    long long remainder = n % get_pisano_period(m);

    long long first = 0;
    long long second = 1;

    long long res = remainder;

    for (int i = 1; i < remainder; i++) {
        res = (first + second) % m;
        first = second;
        second = res;
    }

    return res % m;
}


string Fib::solve(string s){
    stringstream ss;
    ss<<s;
    long long int n;
    string result="";
    int ans;
    //first digit cycle every 60 numbers
    int f[60];
    fib_last_digit(f,60);
    long long int temp;   //temp = fib(n)%60
    //long long int temp[2]={0};
    while(ss>>n){
        temp = get_fibonacci_huge(n,60);
        ans = find_last_digit(f,temp);
        result.append(to_string(ans)+' ');
    }
    result.erase(result.length()-1);
    //cout<<result<<endl;
    return result;
}
