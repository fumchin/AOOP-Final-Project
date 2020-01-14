#ifndef MAZE_H
#define MAZE_H
#include "myother.h"
#include <stack>
class Maze:public MyOther
{
    struct COORD
    {
        int X;
        int Y;
        COORD(int x, int y){X=x; Y=y;}
    };
    string result;
    vector<vector<char>> maze;
public:
    Maze();
    string solve(string s);
    void PrintDaMaze(int MazeHeight, int MazeWidth);
    virtual ~Maze(){}
};

#endif // MAZE_H
