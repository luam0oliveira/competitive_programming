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
        int n,m;cin>>n>>m;
        vector<int> vec;
        for(int i=0;i<n;i++) {
            int a;cin>>a;
            vec.push_back(a);
        }
        sort(vec.rbegin(), vec.rend());
        int ans = 0;
        int actual = 1e9;
        int count = 0;
        for(int i=0;i<n;i++) {
            actual = min(actual, vec[i]);
            count++;
            if (actual * count >= m) {
                ans++;
                actual = 1e9;
                count = 0;
            }
        }
        cout << ans << endl;
    }   
    return 0;
}