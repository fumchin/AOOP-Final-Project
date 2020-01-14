#ifndef TREESTRUCTURE_H
#define TREESTRUCTURE_H
#include "mytree.h"
#include <string>

class TreeStructure:public MyTree
{
    string result;
public:
    TreeStructure();
    string solve(string s);
    int search(char arr[], int x, int n);
    void printPostOrder(char in[], char pre[], int n);
    virtual ~TreeStructure(){}

};

#endif // TREESTRUCTURE_H
