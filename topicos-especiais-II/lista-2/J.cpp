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
typedef vector<int> vi;
const int maxN = 1e5 + 1;

int is_removed[maxN], subtree_size[maxN];
vi adjs[maxN];
vii ancestroids[maxN];

// DFS para calcular tamanho (#nós) das subárvores abaixo de u
int get_subtree_size(int u, int parent = -1) {
    subtree_size[u] = 1;
    for (int v : adjs[u]) {
        if (v == parent or is_removed[v]) continue;
            subtree_size[u] += get_subtree_size(v, u);
    }
    return subtree_size[u];
}

// Retorna um centróide (pode ter até 2) da subárvore
int get_centroid(int u, int tree_size, int parent = -1) {
    for (int v : adjs[u]) {
        if (v == parent or is_removed[v]) continue;
        if (subtree_size[v] * 2 > tree_size)
            return get_centroid(v, tree_size, u);
    }
    return u;
}

void set_dists(int v, int centroid, int parent, int cur_dist) {
    // if (v < centroid) {
    //     // if (centroid == 6) cout << v << endl;
    //     if (ancestroids[v].size()) {
    //         if (ancestroids[v][0].first > cur_dist){
    //             ancestroids[v].pop_back();
    //             ancestroids[v].push_back({cur_dist, centroid});
    //         } else if (ancestroids[v][0].first == cur_dist && ancestroids[v][0].second > centroid) {
    //             ancestroids[v][0].second = centroid;
    //         } 
    //     } else
            ancestroids[v].push_back({cur_dist, centroid});
    // } else if (v > centroid) {
    //     // if (centroid == 6) cout << v << endl;
    //     if (ancestroids[centroid].size()) {
    //         if (ancestroids[centroid][0].first > cur_dist){
    //             ancestroids[centroid].pop_back();
    //             ancestroids[centroid].push_back({cur_dist, v});
    //         } else if (ancestroids[centroid][0].first == cur_dist && ancestroids[centroid][0].second > v) {
    //             ancestroids[centroid][0].second = v;
    //         } 
    //     } else
    //         ancestroids[centroid].push_back({cur_dist, v});
    // }
    for (int w : adjs[v]) {
        if (w != parent and !is_removed[w])
            set_dists(w, centroid, v, cur_dist + 1);
    }
}


int build_centroid_decomp(int u) {
    int subtree_size = get_subtree_size(u, -1);
    int centroid = get_centroid(u, subtree_size, -1);
    
    // Manda avisar a todos os nós na subárvore centrada *neste*
    // centróide, que ele é um de seus ancestróides e também
    // já (pré)calcula as dists dos nós até ele
    for (int v : adjs[centroid]) {
        if (!is_removed[v])
            set_dists(v, centroid, centroid, 1);
    }
    is_removed[centroid] = true; // Este já foi tratado
    for (int v : adjs[centroid]) {
        if (!is_removed[v])
            build_centroid_decomp(v); // Vai para sub-centróides
    }

    return centroid;
}




int main() {
    int n;cin>>n;
    for(int i=1;i<n;i++) {
        int a,b;cin>>a>>b;
        // a--;b--;
        adjs[a].push_back(b);
        adjs[b].push_back(a);
    }
    int uu = build_centroid_decomp(1);
    
    for(int i=1;i<=n;i++) {
        for(auto u: ancestroids[i]) {
            // cout <<u.second<<" ";
            cout <<"{"<<u.second<<", "<<u.first<<"} ";
        }
        cout<<endl;
        // if (ancestroids[i].size()) {
        //     cout <<ancestroids[i][0].second<<endl;            
        // } else {
        //     cout <<i<<endl;
        // }
    }

    return 0;
}