// https://br.spoj.com/problems/DENGUE/
// Grafos - Encontrar centro do grafo

#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > rel;
vector<int> visitados;


// descobrir qual sao os vertices mais distantes
int dfs(int u, int prof, int& depthVortex, int& maxDepth){
    visitados[u] = true;
    int maxx = prof;
    if (maxDepth < prof){
        maxDepth = prof;
        depthVortex = u;
    }
    for(int i = 0; i<rel[u].size();i++){
        if (!visitados[rel[u][i]])
            maxx = max(maxx, dfs(rel[u][i], prof+1, depthVortex, maxDepth));
    }
    visitados[u] = false;
    return maxx;
}

// montar o caminho
void dfs(int u, int v, vector<int>&way){
    visitados[u] = true;
    if (u == v){
        return;
    }
    for(int i = 0; i<rel[u].size();i++){
        if (!visitados[rel[u][i]]){
            dfs(rel[u][i], v, way);
            
            if(rel[u][i] == v || way.size()!=0){
                way.push_back(rel[u][i]);
                return;
            }
        }
    }
}


int find_center(){
    int v1=0,v2=0;
    int dp1=0, dp2=0;
    dfs(0, 0, v1, dp1);
    dfs(v1, 0, v2, dp2);
    // dp2 eh o diametro da arvore
    // o vertice com prof dp2/2 eh o centro da arvore
    vector<int> way;
    dfs(v1, v2, way);
    way.push_back(v1);
    
    return way[dp2/2];
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

        // Brute force O(n^2)
        // for(int i = 0;i<n;i++){
        //     int at = dfs(i, 1);
        //     if (minimo > at){
        //         minimo = at;
        //         id = i;
        //     }
        // }

        // Encontrando o centro O(n)
        id = find_center();

        cout<<"Teste "<<cases++<<endl;
        cout<<id+1<<endl<<endl;
    }
    return 0;
}
