// https://olimpiada.ic.unicamp.br/pratique/p2/2013/f2/troia/
// componentes conexos

#include <bits/stdc++.h>

using namespace std;

vector<int> mark;
vector<vector<int>> adjList;

void dfs(int u){
    mark[u] =true;
    for (auto v: adjList[u]){
        if (!mark[v])
            dfs(v);
    }
}

int main(){
    int n,m;cin>>n>>m;
    mark.assign(n,0);
    adjList.assign(n, {});
    while(m--){
        int a,b;cin>>a>>b;
        a--;
        b--;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    int cont =0;
    for(int i =0; i<n;i++){
        if (!mark[i]){
            cont++;
            dfs(i);
        }
    }
    cout<<cont<<endl;
}