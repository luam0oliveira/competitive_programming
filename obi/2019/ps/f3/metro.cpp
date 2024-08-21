// https://olimpiada.ic.unicamp.br/pratique/pu/2019/f3/metro/
// Grafos - Encontrar centro do grafo

#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > rel;
vector<int> visitados;


// descobrir qual sao os vertices mais distantes
int dfs(int u, int prof, int& depthVortex, int& maxDepth, vector<vector<int> >&rel, vector<int> &visitados){
    visitados[u] = true;
    int maxx = prof;
    if (maxDepth < prof){
        maxDepth = prof;
        depthVortex = u;
    }
    for(int i = 0; i<rel[u].size();i++){
        if (!visitados[rel[u][i]])
            maxx = max(maxx, dfs(rel[u][i], prof+1, depthVortex, maxDepth, rel, visitados));
    }
    visitados[u] = false;
    return maxx;
}

// montar o caminho
void dfs(int u, int v, vector<int>&way, vector<vector<int> >&rel, vector<int> &visitados){
    visitados[u] = true;
    if (u == v){
        return;
    }
    for(int i = 0; i<rel[u].size();i++){
        if (!visitados[rel[u][i]]){
            dfs(rel[u][i], v, way, rel, visitados);
            
            if(rel[u][i] == v || way.size()!=0){
                way.push_back(rel[u][i]);
                return;
            }
        }
    }
}


int find_center(vector<vector<int> >&rel, vector<int> &visitados){
    int v1=0,v2=0;
    int dp1=0, dp2=0;
    dfs(0, 0, v1, dp1, rel, visitados);
    dfs(v1, 0, v2, dp2, rel, visitados);
    // dp2 eh o diametro da arvore
    // o vertice com prof dp2/2 eh o centro da arvore
    vector<int> way;
    dfs(v1, v2, way, rel, visitados);
    way.push_back(v1);
    if (way.size()%2==0){
        return  max(way[dp2/2], way[dp2/2+1]);
    }
    return way[dp2/2];

}

int main() {
    int n,m;cin>>n>>m;
    vector<vector<int> > g1(n);
    vector<int> v1(n);
    vector<vector<int> > g2(m);
    vector<int> v2(m);
    for(int i = 0 ;i<n-1;i++){
        int u,v;cin>>u>>v;
        u--;v--;
        g1[u].push_back(v);
        g1[v].push_back(u);
    }
    for(int i = 0 ;i<m-1;i++){
        int u,v;cin>>u>>v;
        u--;v--;
        g2[u].push_back(v);
        g2[v].push_back(u);
    }

    int m1 = find_center(g1, v1);
    int m2 = find_center(g2, v2);

    cout<<m1+1<<" "<<m2+1<<endl;

    return 0;
}
