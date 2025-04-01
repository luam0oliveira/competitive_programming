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

int color[1010];
int pos;
vector<vector<int>> adj;
void dfs(int u, int c) {
    color[u] = c;
    for(int v: adj[u]) {
        if (color[v] && color[v] == c) pos = false;
        else if (color[v] == 0) dfs(v, c*-1);
    }
}


int main() {
    pos = true;
    int n;cin>>n;
    vii vet(n);
    for(int i=0;i<2*n;i++) {
        int a;cin>>a;
        if (a > 0) {
            vet[a-1].first = i;
        } else {
            vet[abs(a)-1].second = i; 
        }
    }

    adj.assign(n,{});
    for(int i=0;i<n;i++) {
        auto ele = vet[i];
        for(int j =0;j<n;j++) {
            auto ele1 = vet[j];
            if (ele.first < ele1.first && ele.second < ele1.second && ele1.first < ele.second) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    for(int i=0;i<n;i++) {
        if (!color[i]) dfs(i, 1);
    }

    if (pos) {
        for(int i=0;i<n;i++) {
            if (color[i] == 1) cout <<"G";
            else cout <<"S";
        }
        cout<<endl;
    } else {
        cout <<"*\n";
    }


    return 0;
}