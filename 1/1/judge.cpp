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
    if(question == 0 || question == 2){
        n = 2*(rand()%3)+1; //choose number from 1,3,5
    }
    else if(question == 1){
        n = 2*(rand()%4)+1;//choose number from 1,3,5,7
    }
    else {
        return  0;
    }

    ifstream infile;
    string fileName;

    if (question == 0 || question == 1)
        fileName = to_string(question)+".txt";
    else if (question == 2)
        fileName = "longest.txt";
    else if (question == 3)
        fileName = "shygame.txt";
    else if (question == 4)
        fileName = "myfibfib.txt";

    infile.open(fileName);
    if(!infile){
        cout<<"fail open file"<<endl;
    }

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
        return true;
    }
    else{
        return false;
    }
}


//data member
/*
string ans;
ifstream in;
QElapsedTimer timer;
qint64 costtime;
*/
