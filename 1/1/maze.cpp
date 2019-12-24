#include "maze.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>
using namespace std;
char brick = '2';
char path = '0';
enum spotClass {deadEnd=0,continuing=1,intersection=2,end=5};//status of spot
Maze::Maze()
{

}

string Maze::solve(string s)
{

    stringstream ss;
    ss<<s;
    int colNum, rowNum;
    ss>>colNum>>rowNum;

//|-- j
//|
//i
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
                startPos.x = i;
                startPos.y = j;
            }
            else if (ele == 'E')
            {
                endPos.x = i;
                endPos.y = j;
            }
        }
        maze.push_back(row);
    }

    cout << endl;
    for (int i=0; i<rowNum; i++)
    {
        for (int j=0; j<colNum; j++)
            cout << maze[i][j] << " ";
        cout << endl;
    }

    x=startPos.x;
    y=startPos.y;

    int status = getStatus();
    while (status != spotClass::end && !(status == deadEnd && alternativeStack.size() == 0))
    {
        if (status == continuing)//continuing
        {
            visitedStack.push(make_point(x,y));
            if (up==path)
                x--;
            else if(down==path)
                x++;
            else if(left==path)
                y--;
            else if(right==path)
                y++;
            cout << "(" << x << "," << y << ")" << endl;
            status = getStatus();
        }
        else if(status > continuing && status < spotClass::end)//intersection
        {
            visitedStack.push(make_point(-1,-1));
            visitedStack.push(make_point(x,y));
            int firstFound = 0;
            //順序: 上下右左
            int tempX = x;//確保要push到alternativeStack的值不會被影響
            int tempY = y;
            if (up==path)
            {
                firstFound = 1;
                x--;
            }
            if(down==path)
            {
                if (firstFound == 0)
                {
                    firstFound = 1;
                    x++;
                }else//alternative
                {
                    int temp = tempX;
                    temp++;
                    alternativeStack.push(make_point(temp,tempY));
                }
            }
            if(right==path)
            {
                if (firstFound == 0)
                {
                    firstFound = 1;
                    y++;

                }else
                {
                    int temp = tempY;
                    temp++;
                    alternativeStack.push(make_point(tempX,temp));
                }
            }
            if(left==path)
            {
                if (firstFound == 0)
                {
                    firstFound = 1;
                    y--;
                }else//alternative
                {
                    int temp = tempY;
                    temp--;
                    alternativeStack.push(make_point(tempX,temp));
                }
            }
            cout << "(" << x << "," << y << ")" << endl;
            status = getStatus();
        }
        else if (status == deadEnd && alternativeStack.size() != 0)
        {
            int popX, popY;
            while (!(visitedStack.top().x == -1 && visitedStack.top().y == -1))
            {
                popX = visitedStack.top().x;
                popY = visitedStack.top().y;
                visitedStack.pop();
                printf("(%d,%d)\n", popX+1, popY+1);
            }
            visitedStack.push(make_point(popX,popY));
            //go to alterative
            if (sqrt(pow(popX-alternativeStack.top().x,2)+pow(popY-alternativeStack.top().y,2)) == 1)
            {
                popX = alternativeStack.top().x;
                popY = alternativeStack.top().y;
                alternativeStack.pop();
            }
            x = popX;
            y = popY;
            cout << "(" << x << "," << y << ")" << endl;
            status = getStatus();
            printf("*");
        }

    }

    if (status == spotClass::end)
//        printf("(%d,%d)\t<- maze end \n",x,y);
        cout << "\t<- maze end" << endl;
    else if (status == deadEnd)
        printf("(%d,%d)\t<- dead end\n",x,y);

    return "";
}

int Maze::getStatus()
{
    if (x==endPos.x && y==endPos.y)
        return 5;
    up = down = left = right = path;
    int whiteNum = 4;
    if (visitedStack.size() != 0)
    {
        if ( maze[x-1][y] == '2' || (x-1 == visitedStack.top().x && y == visitedStack.top().y))
        {
            up = brick;
            whiteNum--;
        }
        if ( maze[x+1][y] == '2' || (x+1 == visitedStack.top().x && y == visitedStack.top().y))
        {
            down = brick;
            whiteNum--;
        }
        if ( maze[x][y-1] == '2' || (x == visitedStack.top().x && y-1 == visitedStack.top().y))
        {
            left = brick;
            whiteNum--;
        }
        if ( maze[x][y+1] == '2' || (x == visitedStack.top().x && y+1 == visitedStack.top().y))
        {
            right = brick;
            whiteNum--;
        }
    }
    else
    {
        if ( maze[x-1][y] == '2' )
        {
            up = brick;
            whiteNum--;
        }
        if ( maze[x+1][y] == '2' )
        {
            down = brick;
            whiteNum--;
        }
        if ( maze[x][y-1] == '2' )
        {
            left = brick;
            whiteNum--;
        }
        if ( maze[x][y+1] == '2' )
        {
            right = brick;
            whiteNum--;
        }
    }
    return whiteNum;
}

Maze::Point Maze::make_point(int X, int Y) {
    Point mypoint = {X, Y};
    return mypoint;
}
