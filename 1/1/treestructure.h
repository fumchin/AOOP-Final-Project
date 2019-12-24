#ifndef TREESTRUCTURE_H
#define TREESTRUCTURE_H
#include "mymath.h"
#include <string>

class TreeStructure:public MyMath
{
    string result;
public:
    TreeStructure();
    string solve(string s);
    int search(char arr[], int x, int n);
    void printPostOrder(char in[], char pre[], int n);

};

#endif // TREESTRUCTURE_H
