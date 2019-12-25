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
//                row[j] = '0';
            }
            else if (ele == 'E')
            {
                EndingPoint.X = i;
                EndingPoint.Y = j;
//                row[j] = '0';
            }
        }
        maze.push_back(row);
    }

//    cout << endl;
//    for (int i=0; i<rowNum; i++)
//    {
//        for (int j=0; j<colNum; j++)
//        {
//            if (i==StartingPoint.X&&j==StartingPoint.Y)
//                cout << "S" << " ";
//            else if (i==EndingPoint.X&&j==EndingPoint.Y)
//                cout << "E" << " ";
//            else
//                cout << maze[i][j] << " ";
//        }
//        cout << endl;
//    }

    result = "";
    int x=StartingPoint.X;
    int y=StartingPoint.Y;
    stack<COORD> alternativeStack, trajactoryStack;
    while (!(x==EndingPoint.X && y==EndingPoint.Y))
    {
//        PrintDaMaze(rowNum, colNum);
        int choice=0;
        //push to stack in reverse order
        if (x > 0 && (maze[x - 1][y] == Free || maze[x - 1][y] == End))
        {//top
            alternativeStack.push(COORD(x-1,y));
            trajactoryStack.push(COORD(x-1,y));
            choice++;
        }
        if (y > 0 && (maze[x][y - 1] == Free || maze[x][y - 1] == End))
        {//left
            alternativeStack.push(COORD(x,y-1));
            trajactoryStack.push(COORD(x,y-1));
            choice++;
        }
        if (x < rowNum && (maze[x + 1][y] == Free || maze[x + 1][y] == End))
        {//down
            alternativeStack.push(COORD(x+1,y));
            trajactoryStack.push(COORD(x+1,y));
            choice++;
        }
        if (y < colNum && (maze[x][y + 1] == Free || maze[x][y + 1] == End))
        {//right
            alternativeStack.push(COORD(x,y+1));
            trajactoryStack.push(COORD(x,y+1));
            choice++;
        }

        if (choice!=0)
        {
            x=alternativeStack.top().X;
            y=alternativeStack.top().Y;
            alternativeStack.pop();
            trajactoryStack.pop();
            trajactoryStack.push(COORD(x,y));
            maze[x][y] = '1';
        }
        else if (!alternativeStack.empty())
        {//backtrack
            maze[x][y] = '0';
            x=alternativeStack.top().X;
            y=alternativeStack.top().Y;
            alternativeStack.pop();
            trajactoryStack.pop();
            while (!(trajactoryStack.top().X==x && trajactoryStack.top().Y==y))
            {
                maze[trajactoryStack.top().X][trajactoryStack.top().Y] = Free;
                //PrintDaMaze(rowNum, colNum);
                trajactoryStack.pop();
            }
            maze[x][y]  = '1';
        }
        else
        {
            cout << "error!" << endl;
            break;
        }
    }
//    PrintDaMaze(rowNum, colNum);
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

