#include "judge.h"
#include <fstream>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <QTimer>
using namespace std;


string Judge::getData(int question){
    srand((unsigned)time(NULL));

    int n;
    ifstream infile;
    string fileName;

    if (question == 0)
        fileName = "longest.txt";
    else if (question == 1)
        fileName = "minesweeper.txt";
    else if (question == 2)
        fileName = "getsignature.txt";
    else if (question == 3)
        fileName = "shygame.txt";
    else if (question == 4)
        fileName = "myfibfib.txt";
    else if (question == 5)
        fileName = "largestroot.txt";
    else if (question == 7)
        fileName = "findfactorial.txt";
    else if (question == 8)
        fileName = "shortestdistance.txt";   
    else if (question == 9)
        fileName = "add1.txt";
    else if(question == 14)
        fileName = "bigfact.txt";
    else if(question == 24)
        fileName = "myDatabase1_EasyCity2.txt";
    else if(question == 25)
        fileName = "myDatabase2_LSDis.txt";

    infile.open(fileName);
    if(!infile){
        cout<<"fail open file"<<endl;
    }

    //count how many line in the filer
    string unused;
    int line_count=0;
    while(getline(infile,unused)){
        line_count++;
    }

    //choose question
    n = 2*(rand()%(line_count/2))+1;



    //file rewind
    infile.clear();
    infile.seekg(0);

    string result;
    for(int i=0;i<n;i++){
        getline(infile,result);
    }
    getline(infile,ans);

    //timer start
    timer.start();

    //return
    return result;
}
bool Judge::submitData(string ans){
    //timer end
    costtime = timer.nsecsElapsed();
    //ans is result from add1
    if(this->ans.compare(ans)==0){
        score += 100;
        return true;
    }
    else{
        return false;
    }
}
