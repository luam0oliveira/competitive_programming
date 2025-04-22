// Depois de fazer uma solução com accept, tentei encontrar uma solução mais correta, e encontrei essa
// O que acontece é que o que o problema requeria era encontrar os sao atingidos por ultimo ou que iniciam
// que iniciam a busca
// A ideia de ser os ultimos é que eles não são descentes dos que já foram visitados e podem de duas, uma:
// - Ser ascendente de um já encontrado, assim quando atingido ele inicia uma cadeia maior
// - Ser um vértice isolado eles terão de ser atingidos isoladamente (+1 obrigatoriamente)

#include <bits/stdc++.h>
using namespace std;

vector<int> visitados;
vector<vector<int>> norma;
vector<int> ord;

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

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;cin>>t;
    while(t--) {
        int n,m;cin>>n>>m;
        norma.assign(n,{});
        visitados.assign(n,0);
        for(int i=0;i<m;i++) {
            int u,v;cin>>u>>v;
            norma[u-1].push_back(v-1);
        }

        ord.clear();
        ord.reserve(n);

        for(int i=0;i<n;i++) {
            if (!visitados[i]) {
                dfs(i,1);
            }
        }
        
        visitados.assign(n,0);
        int count = 0;
        reverse(ord.begin(), ord.end());
        for(auto u: ord) {
            if(!visitados[u]) {
                count++;
                dfs(u);
            }
        }

        cout << count << endl;
    
    }
}
