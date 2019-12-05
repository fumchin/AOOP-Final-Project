#include "largefactorial.h"
#include <iostream>
#include <sstream>
#include <string>
#define Max 3000
using namespace std;

LargeFactorial::LargeFactorial()
{
}

void multiply(int arr[],int n,int &size){
    int carry = 0;
    int temp;
    for(int i=0;i<size;i++){
        temp = n*arr[i]+carry;
        arr[i] = temp%10;
        carry = temp/10;
    }
    while(carry!=0){
        arr[size] = carry%10;
        carry = carry/10;
        size++;

    }
}

string LargeFactorial::solve(string s){
    stringstream ss;
    ss<<s;
    int n;
    string result = "";
    int arr[Max] = {0};
    arr[0] = 1;
    int size = 1;
    while(ss>>n){
        for(int i=2;i<=n;i++){
            multiply(arr,i,size);
        }
        for(int i=size-1;i>=0;i--){
            result = result + to_string(arr[i]);
        }
    }
    return result;
}
