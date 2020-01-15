#include "getsignature.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
GetSignature::GetSignature()
{

}

string GetSignature::solve(string s)
{
    stringstream ss;
    ss<<s;
    ss>>N;
    graph.assign(N, -1);
    sum.assign(N, -1);
    vis.assign(N, false);
    for(int i = 0; i < N; i++)
    {
        ss>>a>>b;
        graph[a - 1] = b - 1;
    }
    int ans = 0, best_len = 0;
    for(int i = 0; i < N; i++)
    {
        if(sum[i] == -1)
            dfs(i);
        if(sum[i] > best_len)
        {
            best_len = sum[i];
            ans = i;
        }
    }
    return to_string(ans+1);
}

int GetSignature::dfs(int u) {
    vis[u] = true;
    int tot = 0;
    if(graph[u] != -1 && !vis[graph[u]])
        tot += 1 + dfs(graph[u]);
    vis[u] = false;
    return sum[u] = tot;
}
