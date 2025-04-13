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
    ll n;cin>>n;
    
    int sq = sqrt(n);
    vector<ll> ans;

    for(ll i = 1; i < n;i++) {
        ll b = n / i;
        if (b <= i+1) break;
        if (n % i  == 0) {
            ans.push_back(b-1);   
        }
    }

    for(int i=2;i<=sq;i++) {
        // ll num = 1;
        ll rev = 0, norm = 0;
        ll nn = n;
        ll pot = 1;
        // itaxo solution
        while (nn) {
            norm = norm*10 + nn%i;
            rev += (nn%i)*pot;
            nn/=i;
            pot*=10;
        }


        // my solution
        // while(nn) {
        //     ll quant = (nn / num) % i;
        //     norm += quant*num;
        //     nn -= quant*num;
        //     num*=i;
        // }
        // ll aux = 1;

        // nn = n;
        // while(nn) {
        //     ll quant = (nn / num) % i;
        //     rev += quant*(aux/i);
        //     nn -= quant*num;
        //     num/=i;
        //     aux*=i;
        // }

        if (rev == norm) {
            ans.push_back(i);
        }
    }
    sort(ALL(ans));
    if (ans.size()) {
        cout << ans[0];
        for(int i=1;i<ans.size();i++) cout <<" "<<ans[i];
    } else {
        cout <<"*";
    }
    cout<<endl;


    return 0;
}