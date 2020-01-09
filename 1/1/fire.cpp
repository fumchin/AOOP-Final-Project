#include "fire.h"
#include <string>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<sstream>
using namespace std;
typedef long long ll;
const int maxn = 1005;

Fire::Fire(){

}

typedef struct
{
    int x;
    int y;
    int step;
} node;

char map[maxn][maxn];
int vis[maxn][maxn];
int num[maxn][maxn];
int ne[4][2] = {1,0,-1,0,0,1,0,-1};
int sx,sy;
int r,c;
priority_queue<node> q;

bool operator< (node a,node b)
{
    return a.step> b.step;
}

void ff()//先让火苗蔓延
{
    while(!q.empty())
    {
        node t = q.top();
        q.pop();
        for(int i = 0;i< 4;i++)
        {
            int tx = t.x+ne[i][0];
            int ty = t.y+ne[i][1];
            if(tx< 0||tx>= r||ty< 0||ty>= c||map[tx][ty]!= '.'||vis[tx][ty])
                continue;
            vis[tx][ty] = 1;
            node temp;
            temp.x = tx;
            temp.y = ty;
            temp.step = t.step+1;
            q.push(temp);
            num[tx][ty] = temp.step;
        }
    }
    for(int i = 0;i< r;i++)
        for(int j = 0;j< c;j++)
            if(num[i][j] == 0)
                num[i][j] = 1e7;
    return ;
}

int bfs()//再让人尽量出去
{
    memset(vis,0,sizeof(vis));
    while(!q.empty())
        q.pop();
    node st;
    st.step = 0;
    st.x = sx;
    st.y = sy;
    vis[sx][sy] = 1;
    for(int i = 0;i< 4;i++)
    {
        int tx = sx+ne[i][0];
        int ty = sy+ne[i][1];
        if(tx< 0||tx>= r||ty< 0||ty>= c)
            return (st.step+1);
    }
    q.push(st);
    while(!q.empty())
    {
        node t = q.top();
        q.pop();
        for(int i = 0;i< 4;i++)
        {
            int tx = t.x+ne[i][0];
            int ty = t.y+ne[i][1];
            if(tx< 0||tx>= r||ty< 0||ty>= c)
                return (t.step+1);
            if(map[tx][ty]!= '.'||vis[tx][ty]||t.step+1>= num[tx][ty])
                continue;
            vis[tx][ty] = 1;
            node temp;
            temp.x = tx;
            temp.y = ty;
            temp.step = t.step+1;
            q.push(temp);
        }
    }
    return 0;
}

string Fire::solve(string s){
    stringstream ss;
    ss<<s;
    string input;
    string temp;
    string result="";
    //while(ss){
    ss>>r;
    ss>>c;
    while(ss){
        ss>>temp;
        input+=temp;
    }
    //cout<<input<<endl;
    //cout<<r<<endl<<c<<input<<endl;
    while(!q.empty())
        q.pop();
    memset(num,0,sizeof(num));
    memset(map,0,sizeof(map));
    memset(vis,0,sizeof(vis));

    //scanf("%d %d",&r,&c);
    //getchar();
    for(int i = 0;i< r;i++)
    {
        for(int j = 0;j< c;j++)
        {
            //scanf("%c",&map[i][j]);
            map[i][j] = (char)input[i*c+j];
            if(map[i][j] == 'J')
                sx = i,sy = j;
            if(map[i][j] == 'F')
            {
                node temp;
                temp.x = i;
                temp.y = j;
                temp.step = 0;
                q.push(temp);
                num[i][j] = 0;
                vis[i][j] = 1;
            }
        }
    }
    ff();
    int ans = bfs();
    if(ans == 0){
        //printf("IMPOSSIBLE\n");
        result+="N";
    }
    else{
         //printf("%d\n",ans);
        result+=(to_string(ans));
    }

    return result;
}
