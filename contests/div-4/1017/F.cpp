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
        int n,m,k;cin>>n>>m>>k;
        // vector<vector<int>> matrix(n, vector<int>(m));
        if (k == 2) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++) {
                    cout << (i + j) % k  + 1 <<" ";
                    // matrix[i][j] = (i + j) % k  + 1;
                }
                cout<<endl;
            }    
        } else if (m % k == 0) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++) {
                    cout << (i*m + i%2 + j) % k  + 1 <<" ";
                    // matrix[i][j] = (i + j) % k  + 1;
                }
                cout<<endl;
            }
        } else {
            for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++) {
                    cout << (i*m + j) % k  + 1 <<" ";
                }
                cout<<endl;
            }
        }

    }
    
    return 0;
}