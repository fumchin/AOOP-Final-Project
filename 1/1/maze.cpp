#include "maze.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>
using namespace std;
const char Wall = '2';
const char Free = '0';
const char End = 'E';
const char SomeDude = '1';
Maze::Maze()
{

}

string Maze::solve(string s)
{

    stringstream ss;
    ss<<s;
    int colNum, rowNum;
    ss>>colNum>>rowNum;

    int start_x,start_y,end_x,end_y;
    for (int i=0; i<rowNum; i++)
    {
        vector<char> row;
        for (int j=0; j<colNum; j++)
        {
            char ele;
            ss>>ele;
            row.push_back(ele);
            if (ele == 'S')
            {
                start_x=i;
                start_y=j;
                row[j] = '0';
            }
            else if (ele == 'E')
            {
                end_x=i;
                end_y=j;
                row[j] = '0';
            }
        }
        maze.push_back(row);
    }

    cout << endl;
    for (int i=0; i<rowNum; i++)
    {
        for (int j=0; j<colNum; j++)
        {
            if (i==start_x&&j==start_y)
                cout << "S" << " ";
            else if (i==end_x&&j==end_y)
                cout << "E" << " ";
            else
                cout << maze[i][j] << " ";
        }
        cout << endl;
    }
    COORD StartingPoint(start_x, start_y);
    COORD EndingPoint(end_x, end_y);
    result = "";
    if (findPath(StartingPoint.X, StartingPoint.Y, EndingPoint, rowNum, colNum))
    {
        maze[start_x][start_y] = 'S';
        maze[end_x][end_y] = 'E';
        PrintDaMaze(rowNum, colNum);
        for (int i=0; i<rowNum; i++)
        {
            for (int j=0; j<colNum; j++)
            {
                result += maze[i][j];
                result.append(" ");
            }
        }
    }
    else
    {
        printf("Damn\n");
    }
    result.erase(result.length()-1);
    maze.clear();//to avoid bug, prepare for next input
    return result;
}

bool Maze::findPath(int X, int Y, COORD EndingPoint, int MazeHeight, int MazeWidth)
{
    // Make the move (if it's wrong, we will backtrack later.
    maze[X][Y] = SomeDude;
    // If you want progressive update, uncomment these lines...
    PrintDaMaze(MazeHeight, MazeWidth);
    //Sleep(50);

    // Check if we have reached our goal.
    if (X == EndingPoint.X && Y == EndingPoint.Y)
    {
        return true;
    }

    // Recursively search for our goal.

    if (Y < MazeWidth && maze[X][Y + 1] == Free && findPath(X, Y+1, EndingPoint, MazeHeight, MazeWidth))
    {//right
        return true;
    }
    if (X < MazeHeight && maze[X + 1][Y] == Free && findPath(X+1, Y, EndingPoint, MazeHeight, MazeWidth))
    {//down
        return true;
    }
    if (Y > 0 && maze[X][Y - 1] == Free && findPath(X , Y-1, EndingPoint, MazeHeight, MazeWidth))
    {//left
        return true;
    }
    if (X > 0 && maze[X - 1][Y] == Free && findPath(X - 1, Y, EndingPoint, MazeHeight, MazeWidth))
    {//up
        return true;
    }

    // Otherwise we need to backtrack and find another solution.
    maze[X][Y] = Free;

    // If you want progressive update, uncomment these lines...
    PrintDaMaze(MazeHeight, MazeWidth);
//    Sleep(50);
    return false;
}

void Maze::PrintDaMaze(int MazeHeight, int MazeWidth)
{
    cout << endl;
    for (int i=0; i<MazeHeight; i++)
    {
        for (int j=0; j<MazeWidth; j++)
            cout << maze[i][j];
        cout << endl;
    }
    cout << endl;
}
