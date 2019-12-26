#include "fib.h"
#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
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

int Fib::shift(long long int n){
    int f0=0,f1=1;
    int result=1;
    for(int i=2;i<=n;i++){
        result = f0+f1;
        if(result>=60){
            result%=60;
        }
        f0 = f1;
        f1 = result;
    }
//    long  long int result;
//    double estim = 0.4472135955 * pow(1.618033988745, n+1);
//    result =  ( abs(ceil(estim)-estim) < abs(estim-floor(estim)) )? ceil(estim) : floor(estim);
//    result%=60;
    return  result;
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
//        cout<<n<<endl;
     //   fast_fib(n,ans);
        temp = shift(n);
        ans = find_last_digit(f,temp);
        result.append(to_string(ans)+' ');
    }
    result.erase(result.length()-1);

    return result;
}
