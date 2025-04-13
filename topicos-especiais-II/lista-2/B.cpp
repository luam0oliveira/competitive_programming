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
    map<int,int> count;   
    for(int i=0;i<n*3;i++) {
        int a;cin>>a;count[a]++;
    }
    int ans = 1, zero = count[0];
    if (count.find(0) != count.end()) 
        count.erase(count.find(0));
    for(auto p:count) {
        if (p.second%3 && (3 - p.second % 3) > zero) {
            cout << zero << endl;
            ans = 0;
        }
        else {
            zero -=  (3 - p.second%3) % 3;
        }
    }
    if (ans) cout << "N" <<endl;
    else cout << "Y" << endl;
    return 0;
}
