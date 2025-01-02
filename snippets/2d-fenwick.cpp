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
typedef vector<ll> vll;

vector<vll> ft;

void update(int x, int y, ll v) {
    for(;x<ft.size();x+=LSOne(x)) {
        for(int j=y;j<ft[0].size();j+=LSOne(j)) {
            ft[x][j] += v;
        }
    }
}

ll find(int x, int y) {
    ll sum = 0;
    for(;x>0;x-=LSOne(x)) {
        for(int j=y;j>0;j-=LSOne(j)) {
            sum += ft[x][j];
        }
    }
    return sum;
}

ll query(int xf, int yf, int xo, int yo) {
    ll sum = find(xf, yf) + find(xo-1, yo-1) - find(xf, yo-1) - find(xo-1, yf);
    return sum;
}



int main() {
    int n,m;cin>>n>>m;
    ft.assign(n+1, vll(m+1, 0));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int a;cin>>a;
            update(i+1, j+1, a);
        }
    }
    cout << query(3,3, 2,2)<<endl;
    return 0;
}