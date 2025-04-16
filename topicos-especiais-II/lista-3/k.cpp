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
    int n;cin>>n;
    int ar[26];
    memset(ar,0, sizeof(ar));
    vector<string> ss;
    for(int i=0;i<n;i++) {
        string s;cin>>s;
        ss.push_back(s);
        ar[s[0]-'A']=1;
    }
    int ans = 0;
    for(int i=0;i<n && !ans;i++) {
        ans = 1;
        for(auto c:ss[i]) {
            if(!ar[c-'A']) {ans = 0;break;}
        }
    }
    if (ans) cout<<"Y"<<endl;
    else cout<<"N"<<endl; 
    return 0;
}