#include "maze.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>
#include <stack>
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
    COORD StartingPoint(-1,-1);
    COORD EndingPoint(-1,-1);
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
                StartingPoint.X = i;
                StartingPoint.Y = j;
            }
            else if (ele == 'E')
            {
                EndingPoint.X = i;
                EndingPoint.Y = j;
            }
        }
        maze.push_back(row);
    }

    mark = maze;
    mark[StartingPoint.X][StartingPoint.Y] = Free;
    mark[EndingPoint.X][EndingPoint.Y] = Free;
    result = "";
    int x=StartingPoint.X;
    int y=StartingPoint.Y;
//    trajactoryStack.push(COORD(x,y));
//    mark[x][y] = Wall;
    while (!(x==EndingPoint.X && y==EndingPoint.Y))
    {
        trajactoryStack.push(COORD(x,y));
        mark[x][y] = Wall;
        if (y < colNum && (mark[x][y + 1] == Free || mark[x][y + 1] == End))//can go right
            y++;
        else if (x < rowNum && (mark[x + 1][y] == Free || mark[x + 1][y] == End))//can go down
            x++;
        else if (y > 0 && (mark[x][y - 1] == Free || mark[x][y - 1] == End))//can go left
            y--;
        else if (x > 0 && (mark[x - 1][y] == Free || mark[x - 1][y] == End))//can go top
            x--;
        else//dead end
        {
            while (mark[x - 1][y]==Wall&&mark[x + 1][y]==Wall&&mark[x][y - 1]==Wall&&mark[x][y + 1]==Wall)
            {
                x = trajactoryStack.top().X;
                y = trajactoryStack.top().Y;
                trajactoryStack.pop();
            }
        }
    }

    while (!trajactoryStack.empty())
    {
        x = trajactoryStack.top().X;
        y = trajactoryStack.top().Y;
        trajactoryStack.pop();
        maze[x][y] = SomeDude;
    }
    maze[StartingPoint.X][StartingPoint.Y] = 'S';
    maze[EndingPoint.X][EndingPoint.Y] = 'E';
//    PrintDaMaze(rowNum, colNum);

    for (int i=0; i<rowNum; i++)
    {
        for (int j=0; j<colNum; j++)
        {
            result += maze[i][j];
            result.append(" ");
        }
    }
    result.erase(result.length()-1);
    maze.clear();//to avoid bug, prepare for next input

    return result;
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
