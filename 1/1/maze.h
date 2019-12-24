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
    class COORD
    {
    public:
        int X;
        int Y;
        COORD(int x = 0, int y = 0) { X = x, Y = y; }
        COORD(const COORD &coord) { X = coord.X; Y = coord.Y; }
    };

    vector<vector<char>> maze;
public:
    Maze();
    string solve(string s);
    bool findPath(int X, int Y, COORD EndingPoint, int MazeHeight, int MazeWidth);
    void PrintDaMaze(int MazeHeight, int MazeWidth);
};

#endif // MAZE_H
