#include<bits/stdc++.h>
#include<bits/extc++.h>
#define ll long long
#define ii pair<int,int>
#define il pair<int, ll>
#define INF 1e9
#define EPS 1e-9
#define LINF 0x3f3f3f3f3f3f3f3f
#define ALL(X) X.begin(), X.end()
#define LSOne(S) (S & -(S))
#define ZZZZ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
// using namespace __gnu_pbds;
// Template to use pbds
// template<class T>
// using Tree = tree<T, null_type, less<T>,splay_tree_tag, tree_order_statistics_node_update>;
// Template to use pbds
typedef vector<ii> vii;
typedef vector<il> vil;
int main() {
    ZZZZ
    int n,m;cin>>n>>m;
    int p,g;cin>>p>>g;

    vector<ll> d(n+1,LINF);
    vector<int> through(n+1,0);
    vector<vil> adj; adj.assign(n+1, {});
    through[g] = 1;
    for(int i=0;i<m;i++) {
        int u,v,c;cin>>u>>v>>c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }

    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0, p});
    d[p] = 0;

    while(!pq.empty()) {
        auto top = pq.top(); pq.pop();
        ll cost = top.first;
        int u = top.second;
        if (d[u] != cost) continue;

        for(auto [v, c]: adj[u]) {
            if (cost + c < d[v]) {
                d[v] = cost + c;
                pq.push({cost + c , v});
                if (v == g) through[v] = 1;
                else through[v] = through[u];
            } else if (cost + c == d[v]) {
                if (v == g) through[v] = 1;
                else through[v] = min(through[u], through[v]);
            }
        }
    }

    vector<int> funciona;
    ll c = 2*d[g];
    for(int i = 1; i<=n;i++) {
        if (d[i] == c && through[i]) funciona.push_back(i);
    }

    if (funciona.empty()) cout << "*" << endl;
    else {
        cout <<funciona[0];
        for(int i=1;i<funciona.size();i++) cout<<" " << funciona[i];
        cout<<endl;
    }
 
    return 0;
}
