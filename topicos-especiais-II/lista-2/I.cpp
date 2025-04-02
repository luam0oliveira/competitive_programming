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
// using namespace __gnu_pbds;
// Template to use pbds
// template<class T>
// using Tree = tree<T, null_type, less<T>,splay_tree_tag, tree_order_statistics_node_update>;
// Template to use pbds
typedef vector<ii> vii;
int const maxn = 32;
int const MOD = 1000000007;
int a[maxn+1], b[maxn+1], vec[200001];
void add(int arr[], int pos) {
    for(int i=pos;i<=maxn;i+=LSOne(i)) {
        arr[i] += 1; 
    }
}

ll sum(int arr[], int pos) {
    ll s = 0;
    for(int i=pos;i>0;i-=LSOne(i)) {
        s += arr[i];
    }
    return s;
}


// INUTIL
ll mult_mod(ll a, ll b, ll mod = 1e9 + 7) {
    a = a%mod;
    b = b%mod;
    ll result = 0;
    while(b) {
        if (b & 1) result = (result + a) % mod;
        a = (a + a) % mod;
        b>>=1; 
    }
    return result;
}

int main() {
    string s;cin>>s;
    ll n;cin>>n;
    for(int i=0;i<s.size();i++) {
        vec[i] = s[i] - 'a' + 1;
    }
    
    ll inver = 0;
    
    for(int i=s.size()-1;i>=0;i--) {
        add(a, vec[i]);
        inver += sum(a, vec[i]-1);
    }
    
    ll ans = inver;
    if (n > 1) {
        ll inverB = 0;
        for(int i=s.size()-1;i>=0;i--) {
            add(a, vec[i]);
            inverB += sum(a, vec[i]-1);
        }
        inverB-=inver;
        
        if (n&1) {
            ll term = (inverB % MOD) * (((n-1)/2)%MOD);
            inver = inver%MOD;
            ans = ((inver + term) % MOD) *(n % MOD)%MOD ;
        } else {
            ll term = (inverB % MOD)*((n-1)%MOD);
            inver = (inver%MOD)*2;
            ans = ((inver + term) % MOD) *((n/2) % MOD) % MOD ;
        }
    }
    
    cout << ans << endl;
    return 0;
}
