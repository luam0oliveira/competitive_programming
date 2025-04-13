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
        int n;cin>>n;
        multiset<ll> par,impar;
        for(int i=0;i<n;i++) {
            int a;cin>>a;
            if (a%2) {
                impar.insert(a);
            } else {
                par.insert(a);
            }
        }

        while(impar.size() && par.size()) {
            if (1==*(--impar.end())) break;
            auto greaterPar = --par.end();
            auto greaterImpar = --impar.end();
            
            auto sum = *greaterPar + *greaterImpar - 1;
            impar.erase(greaterImpar);
            par.erase(greaterPar);
            par.insert(sum);
            impar.insert(1);
        }
        
        while(par.size() >= 2 && impar.size() >= 1) {
            auto greaterPar = --par.end();
            auto greaterImpar = --impar.end();
            
            
            auto sum = *greaterPar + *greaterImpar;
            impar.erase(greaterImpar);
            par.erase(greaterPar);
            impar.insert(sum);
        }
        
        ll ans= 0;
        if (par.size() && impar.size()) {
            ans = max(ans, *(--par.end()) + *(--impar.end()));
        } else if (par.size()) {
            ans = *(--par.end());
        } else {
            ans = *(--impar.end());
        }
        cout<<ans<<endl;
        
    }   
    return 0;
}