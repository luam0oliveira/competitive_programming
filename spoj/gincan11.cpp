// https://br.spoj.com/problems/GINCAN11/
// grafos - componentes conexas

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adjList;
vector<int> vortex;
vector<bool> mark;


void dfs(int u)
{
    mark[u] = true;
    
    for (auto v: adjList[u])
    {
        if (!mark[v])
            dfs(v);
    }
}

int main()
{
    int n, e, u, v,cont=0;
    
    scanf("%d %d ", &n, &e);
    
    adjList.assign(n, {});
    vortex.assign(n,0);
    mark.assign(n,false);
    
    for(int i = 0; i < e;i++)
    {
        scanf("%d %d ", &u, &v);
        u--;v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    for (int i = 0; i < n;i++)
    {
        if (!mark[i])
        {
            dfs(i);
            cont++;
        }
    }
    
    printf("%d\n", cont);

    return 0;
}
