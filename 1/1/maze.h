#ifndef MAZE_H
#define MAZE_H
#include "mymath.h"
#include <stack>
class Maze:public MyMath
{
    struct COORD
    {
        int X;
        int Y;
        COORD(int x, int y){X=x; Y=y;}
    };
    string result;
    vector<vector<char>> maze;
    vector<vector<char>> mark;
    stack<COORD> trajactoryStack;
public:
    Maze();
    string solve(string s);
    void PrintDaMaze(int MazeHeight, int MazeWidth);
};

#endif // MAZE_H
