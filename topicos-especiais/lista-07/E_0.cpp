// Depois de fazer uma solução com accept, tentei encontrar uma solução mais correta, e encontrei essa
// O que acontece é que o que o problema requeria era encontrar os sao atingidos por ultimo ou que iniciam
// que iniciam a busca
// A ideia de ser os ultimos é que eles não são descentes dos que já foram visitados e podem de duas, uma:
// - Ser ascendente de um já encontrado, assim quando atingido ele inicia uma cadeia maior
// - Ser um vértice isolado eles terão de ser atingidos isoladamente (+1 obrigatoriamente)

#include <bits/stdc++.h>
using namespace std;

vector<int> visitados;
vector<vector<int>> adj,norma,ndj;
vector<int> ord, cod;
vector<unordered_set<int>> adjsss;
void dfs(int u, int save = 0) {
    visitados[u] = 1;
    for(auto v: norma[u]) {
        if (!visitados[v]) {
            dfs(v, save);
        }
    }
    if (save)
        ord.push_back(u);
}

void dfs2(int codigo, int u, vector<int>&vec,unordered_set<int> &extra) {
    visitados[u] = 1;
    vec.push_back(u);
    for(auto v: adj[u]) {
        if (!visitados[v]) {
            cod[u] = codigo;
            dfs2(codigo, v, vec, extra);
        } else {
            adjsss[cod[v]].insert(codigo);
        }
    }
}

void dfs3 (int u) {
    visitados[u] = 1;
    for(auto v: adjsss[u]) {
        if (!visitados[v]) {
            dfs3(v);
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;cin>>t;
    while(t--) {
        int n,m;cin>>n>>m;
        adj.assign(n,{});
        norma.assign(n,{});
        ndj.clear();
        adjsss.clear();
        visitados.assign(n,0);
        for(int i=0;i<m;i++) {
            int u,v;cin>>u>>v;
            adj[v-1].push_back(u-1);
            norma[u-1].push_back(v-1);
        }
        ord.clear();
        ord.reserve(n);
        for(int i=0;i<n;i++) {
            if (!visitados[i]) {
                dfs(i,1);
            }
        }
        
        cod.assign(n,0);

        visitados.assign(n,0);
        int count = 0;
        reverse(ord.begin(), ord.end());
        for(auto u: ord) {
            if(!visitados[u]) {
                count++;
                dfs(u);
            }
        }
        // for(auto u: ord) {
        //     if (!visitados[u]) {
        //         ndj.push_back({}), adjsss.push_back({});
        //         dfs2(count++, u, ndj.back(), adjsss.back());
        //     }
        // }
        // visitados.assign(ndj.size(), 0);
        // int ans = 0;
        // for(int i =0;i<count;i++) {
        //     if (!visitados[i]) {
        //         ans++;
        //         dfs3(i);
        //     }
        // }

        cout << count << endl;
    
    }
}