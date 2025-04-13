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
int main() {
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        if (n & 1) {
            int imp = (n+1)/2;
            int par = n - imp;
            for(int i=0;i<imp;i++) {
                cout << i * 2 + 1 << " ";
            }
            for(int i=1;i<=par;i++) {
                cout << i * 2 << " ";
            }
            cout<<endl;
        } else cout << -1 << endl;
    }   
    return 0;
}