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
    while (t--){
        int n;cin>>n;
        ll sum =0;
        vector<int> vec, count(32,0);
        for(int i=0;i<n;i++) {
            int a;cin>>a;
            vec.push_back(a);
            sum += a;
            int j = 0;
            while(a) {
                if (a&1) count[j]++;
                a>>=1;
                j++;
            }
        }
        ll ans = 0;
        int m = n-1;
        for(auto a: vec) {
            ll actual = 0;
            ll pot = 1;
            for(int i=0;i<32;i++) {
                if (a & 1) {
                    actual += (n - count[i]) * pot;
                } else {
                    actual += count[i] * pot;
                }
                a>>=1;
                pot<<=1;
            }
            ans = max(actual, ans);
        }
        cout<<ans<<endl;
    }
       
    return 0;
}