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
    int a,b,c;cin>>a>>b>>c;
    int ans = 1;
    for(int i=0;i<a;i++) {
        string s1,s2;cin>>s1>>s2;
        int q = 0;
        for(auto c: s1) {
            if (c == '-') q=1;
        }
        for(auto c:s2) {
            if (q && c == '*') {
                ans = 0;
            }
        }
    }
    if (ans) cout <<"Y"<<endl;
    else cout<<"N"<<endl;

    return 0;
}