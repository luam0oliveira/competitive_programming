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
int main() {
    int t;cin>>t;
    while(t--){
        int l, r;cin>>l>>r;
        if (l == 1 && r == 1) {
            cout << 1<<endl;
        } else {
            cout << r - l << endl;
        }
    }
    return 0;
}