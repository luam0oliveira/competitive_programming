// https://codeforces.com/contest/216/problem/B
// Grafos - Bicoloracao
// Quando se controi um grafo bipartido, eh a mesma coisa que estar separando o
// grafo em dois grupos (os coloridos e os nao-coloridos)

#include<bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define QUAT(x) x*x;
using namespace std;

int n, b;
int colored[101];
vector<int> adjList[101];

void dfs(int u, int p){
    colored[u] = p;
    for(int i = 0;i < (int) adjList[u].size();i++){
        if (colored[adjList[u][i]] == 0){
            dfs (adjList[u][i], -p);
        }
        else if (colored[adjList[u][i]] == p){
            colored[u] = -2;
            b++;
        }
    }
}

int main(){
    int m;
    b = 0;
    scanf("%d %d ", &n, &m);

    for(int i  = 0; i < m;i++){
        int u,v;
        scanf("%d %d ", &u, &v);
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for(int i = 1; i<=n;i++){
        if (!colored[i])
            dfs(i, 1);
    }

    if ((n-b)%2) printf("%d\n", b+1);
    else printf("%d\n", b);
}
