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
        string a,b;cin>>a>>b;
        int imp = 0, par = 0;
        for(int i=0;i<n;i++) {
            if (i%2 == 0) {
                imp+=a[i]=='1';
                par+=b[i]=='1';
            } else {
                imp+=b[i]=='1';
                par+=a[i]=='1';    
            }
        }
        int vagImp = (n+1)/2;
        int vagPar = n-vagImp;
        // cout << imp << " "<<par<<endl;
        // cout << 
        if (imp <= vagPar && par <= vagImp) cout <<"YES"<<endl;
        else cout<<"NO"<<endl;
    }   
    return 0;
}