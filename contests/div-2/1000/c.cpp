#include<bits/stdc++.h>
#include<bits/extc++.h>
#define ll long long
#define ii pair<int,int>
#define INF 1e9
#define EPS 1e-9
#define ALL(X) X.begin(), X.end()
#define LSOne(S) (S & -(S))
using namespace std;
using namespace __gnu_pbds;
// Template to use pbds
template<class T>
using Tree = tree<T, null_type, less<T>,splay_tree_tag, tree_order_statistics_node_update>;
// Template to use pbds
typedef vector<ii> vii;
typedef vector<int> vi;
vector<vi> adj;
bitset<400000> visite;

void dfs(int u) {
    visite[u] = true;
    for(auto v: adj[u]) {
        if (!visite[v]) {
            visite[v] = true;
            dfs(v);
        }
    }
}
int main() {
    int t;cin>>t;
    while (t--) {
        adj.clear();
        visite.reset();
        int n;cin>>n;
        vii edges;
        vi nodes(n, 0);
        for(int i=0;i<n-1;i++) {
            int u, v;cin>>u>>v;
            u--,v--;
            nodes[u]++;
            nodes[v]++;
            edges.push_back({u, v});
        }
        if (n == 2) {
            cout << 0 <<endl;
            continue;
        }
        auto nod = max_element(nodes.begin(), nodes.end());
        int torem = nod - nodes.begin();
        cout << torem << endl;
        visite[torem] = true;
        nodes.assign(n,0);
        vii nedges;
        for(auto e: edges) {
            if (e.first != torem && e.second != torem) {
                nedges.push_back(e);
                nodes[e.first]++;
                nodes[e.second]++;
            }
        }
        nod = max_element(nodes.begin(), nodes.end());
        torem = nod - nodes.begin();
        cout << torem << endl;
        visite[torem] = true;
        adj.assign(n, {});
        for(auto e: nedges) {
            if (e.first != torem && e.second != torem) {
                adj[e.first].push_back(e.second);
                adj[e.second].push_back(e.first);
            }
        }


        int count = 0;
        for(int i = 0;i<n;i++) {
            if (!visite[i]) dfs(i), count++;
        }

        cout << count << endl;


        
    }
    
    return 0;
}