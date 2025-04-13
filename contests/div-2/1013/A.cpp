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
        vector<int>aa(10);
        aa[2] = 2;
        aa[0] = 3;
        aa[1] = 1;
        aa[3] = 1;
        aa[5] = 1;
        int td = 8;
        int ans = 0;
        for(int i=0;i<n;i++) {
            int a;cin>>a;
            if (aa[a] > 0) {
                td--;
            }
            if (td == 0) {
                ans = i+1;
            }
            aa[a]--;
        }
        cout << ans << endl;
    }   
    return 0;
}