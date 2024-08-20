// https://br.spoj.com/problems/DENGUE/
// Grafos - Encontrar centro do grafo

#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > rel;
vector<int> visitados;

int dfs(int u, int prof){
    visitados[u] = true;
    int maxx = prof;
    for(int i = 0; i<rel[u].size();i++){
        if (!visitados[rel[u][i]])
            maxx = max(maxx, dfs(rel[u][i], prof+1));
    }
    visitados[u] = false;
    return maxx;
}

int main() {
    int n,cases=1;
    while(cin>>n && n!=0){
        visitados.assign(n,0);
        rel.assign(n, vector<int>());
        for(int i = 0;i<n-1;i++){
            int a, b;cin>>a>>b;
            a--,b--;
            rel[a].push_back(b);
            rel[b].push_back(a);
        }
        int minimo = 1e4;
        int id = 0;


        for(int i = 0;i<n;i++){
            int at = dfs(i, 1);
            if (minimo > at){
                minimo = at;
                id = i;
            }
        }
        cout<<"Teste "<<cases++<<endl;
        cout<<id+1<<endl<<endl;
    }
    return 0;
}