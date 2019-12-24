#include "treestructure.h"
#include <iostream>
#include <string>
#include <sstream>
#include <string.h>
using namespace std;

TreeStructure::TreeStructure()
{
}

string TreeStructure::solve(string s)
{
    stringstream ss;
    ss<<s;
    string str;
    char *preOrderArr, *inOrderArr;
    result = "";

    ss>>str;
    int length = str.length();
    preOrderArr = new char [length+1];
    inOrderArr = new char [length+1];

    strcpy(preOrderArr, str.c_str());
    ss>>str;
    strcpy(inOrderArr, str.c_str());
    printPostOrder(inOrderArr, preOrderArr, length);
    return result;
}
// A utility function to search x in arr[] of size n
int TreeStructure::search(char arr[], int x, int n)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

// Prints postorder traversal from given inorder and preorder traversals
void TreeStructure::printPostOrder(char in[], char pre[], int n)
{
    // The first element in pre[] is always root, search it
    // in in[] to find left and right subtrees
    int root = search(in, pre[0], n);

    // If left subtree is not empty, print left subtree
    if (root != 0)
        printPostOrder(in, pre + 1, root);

    // If right subtree is not empty, print right subtree
    if (root != n - 1)
        printPostOrder(in + root + 1, pre + root + 1, n - root - 1);

    // Print root
    result += pre[0];
}
