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
    map<string, int> pos;
    string s; cin>>s;
    int let[26]; memset(let, 0, sizeof(let));
    for(auto c: s) let[c-'a'] = 1;
    pos["*****"] = 1;
    for(int i=0;i<n-1;i++) {
        string a,f;cin>>a;
        for(int  i=0;i<5;i++) {
            if (a[i] == s[i]) f+="*";
            else if (let[a[i]-'a']) f+="!";
            else f+="X";
        }
        pos[f]++;
    }
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>s;
        cout << pos[s] << endl;
    }
    return 0;
}
