#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define INF 100;
using namespace std;

const int maxN = 1e6;

int visited[maxN], fi[maxN], cod[maxN];
ll n_fi[maxN], dp[maxN];
vector<int> adj[maxN], in_adj[maxN], ord;
vector<unordered_set<int>> arestas;
int n,m,s,e;

void kosaraju (int u, int inverted = 0) {
    visited[u] = 1;
    for(auto v: adj[u]) {
        if (!visited[v]) kosaraju(v, inverted);
    }
    ord.push_back(u);
}

ll findSCC (int u, int ind, unordered_set<int> &n_arestas) {
    visited[u] = 1;
    cod[u] = ind;
    ll ans = fi[u];
    for(auto v: in_adj[u]) {
        if (!visited[v]) ans += findSCC(v, ind, n_arestas);
        else if (cod[v] != ind) arestas[cod[v]].insert(cod[u]);
    }
    return ans;
}

ll solve(int u) {
    if (dp[u] != -1) return dp[u];
    if (u == cod[e-1]) return n_fi[cod[e-1]];
    if (!arestas[u].size() && u != e) return dp[u] = -INF;
    ll ans = 0;
    for(auto v: arestas[u]) {
        ans = max(solve(v), ans);
    }
    return dp[u] = ans + n_fi[u];
}


int main() {
    cin>>n>>m>>s>>e;
    memset(visited, 0, sizeof(visited));

    for(int i=0;i<n;i++) {
        cin>>fi[i];
    }
    
    for(int i=0;i<m;i++) {
        int u,v;cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
        in_adj[v].push_back(u);
    }
    
    ord.clear();
    ord.reserve(n);
    for(int i=0; i < n; i++) {
        if (!visited[i]) {
            kosaraju(i);
        }
    }

    
    int count = 0;
    memset(visited, 0, sizeof(visited));
    for(int i=n-1; i >= 0; i--) {
        if (!visited[ord[i]]) {
            arestas.push_back({});
            n_fi[count] = findSCC(ord[i], count, arestas.back());
            count++;
        }
    }
    memset(dp, -1, sizeof(dp));
    ll ans = solve(cod[s-1]);
    cout << ans << endl;
}
