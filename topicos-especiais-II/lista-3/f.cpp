#include<bits/stdc++.h>
#include<bits/extc++.h>
#define ll long long
#define ii pair<int,int>
#define INF 1e9
#define EPS 1e-9
#define ALL(X) X.begin(), X.end()
#define LSOne(S) (S & -(S))
#define ZZZZ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using namespace __gnu_pbds;
// Template to use pbds
template<class T>
using Tree = tree<T, null_type, less<T>,splay_tree_tag, tree_order_statistics_node_update>;
// Template to use pbds
typedef vector<ii> vii;
bitset<400000> visitados;
int color[400000];
vector<vector<int>> adj;

void dfs(int u) {
    visitados[u] = 1;
    color[u] = 1;
    for(auto v: adj[u]) {
        if (!visitados[v]) {
            dfs(v);
        }
    }
}

int main() {
    ZZZZ
    int n,m;cin>>n>>m;
    memset(color, 0, sizeof(color));
    adj.assign(n, {});
    for(int i=0;i<m;i++) {
        int u,v;cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // sum of 2^0 + 2^1 + ... + 2^n-1 < 2^n
    visitados[n-1] = 1;
    dfs(n-2);
    for(int i=0;i<n;i++) {
        if (color[i]) cout << "B";
        else cout << "A";
    }
    cout<<endl;
    return 0;
}