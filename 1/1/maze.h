#ifndef MAZE_H
#define MAZE_H
#include "mymath.h"
#include <stack>
class Maze:public MyMath
{
    struct Point
    {
        int x; int y;
    }startPos, endPos;
    int x,y;
    char up,down,left,right;
    vector<vector<char>> maze;
    stack<Point> visitedStack, alternativeStack;
public:
    Maze();
    string solve(string s);
    int getStatus();
    Point make_point(int x, int y);
};

#endif // MAZE_H
