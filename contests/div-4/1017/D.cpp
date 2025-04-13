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
    while(t--) {
        string s1,s2;cin>>s1>>s2;
        int n = s1.size();
        int pos_i = 0, pos_j = 0;
        int ans = s1.size() <= s2.size();
        while(pos_i < s1.size() && ans) {
            int c1 = 1, c2 = 1;
            for(int i=pos_i+1;i<n;i++) {
                if (s1[i] == s1[i-1]) c1 ++;
                else break;
                pos_i++;
            }
            for(int i=pos_j+1;i<s2.size();i++) {
                if (s2[i] == s2[i-1]) c2++;
                else break;
                pos_j++;
            }

            pos_i++;
            pos_j++;

            int pos = c1 <= c2 && c1 * 2 >= c2;
            ans = pos_i<=s1.size() && pos_j <= s2.size() && s1[pos_i-1] == s2[pos_j-1] && pos;
        }
        if (ans && pos_j == s2.size()) cout <<"YES"<<endl;
        else cout <<"NO"<<endl;

    }   
    return 0;
}