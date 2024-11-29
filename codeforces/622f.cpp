/**
 *     author: demot.r
 *     created: 2024-11-25 16:35:14
 *     source: 
 *     description: 
**/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 1e9 + 7;
const int maxK = 1e6+5;
ll fast(ll a, ll b) {
    ll mult = 1;
    while (b) {
        if (b&1) mult = (mult * a) % mod; 
        b>>=1;
        a = (a * a) % mod;
    }
    return mult;
}

// inverse factorial
ll inverse[maxK];
// Prod
ll prefix[maxK], posfix[maxK];

// Its from a internet solution
ll inverseF(ll a) {
    // return fast(a, mod - 2);
    if (inverse[a] != -1) return inverse[a];
    else return inverse[a] = fast(a, mod - 2); // by little theorem of fermat a^(p-2) (mod p) = a^-1 (mod p)
}

ll interpolation(ll n, ll k) {
    ll ans = 0;

    memset(inverse, -1, sizeof(inverse));
    
    inverse[0] = 1;
    prefix[0] = 1;
    posfix[k + 3] = 1;

    // OK
    for (ll i=1;i<=k+2;i++){
        prefix[i] = (prefix[i-1] * (n - i)) % mod;
    }

    // OK
    for (ll i=k+2;i>=1;i--){
        posfix[i] = ((posfix[i+1] * (n - i))) % mod;
    }

    // OK
    for (ll i=1;i<=k+2;i++) {
        inverse[i] = (inverse[i-1] * inverseF(i)) % mod;
    }

    ll yi = 0;

    // k + 2 points
    // same way, its necessary k + 2 inversed factorials
    for(int i=1;i<=k+2;i++) {
        // calc f(i)
        yi = (yi + fast(i, k)) % mod;
        ll num, den;

        num = (prefix[i-1] * posfix[i+1]) % mod;

        den = (inverse[i-1] * inverse[k - i + 2]) % mod;

        if ((i - k) & 1) {
            ans -= (((num * yi) % mod) * den) % mod;
        } else {
            ans += (((num * yi) % mod) * den) % mod;
        }

        ans = (ans + mod) % mod;
    } 
    return ans;
}

int main() {
    ll n,k;cin>>n>>k;
    cout<<interpolation(n, k)<<endl;
    return 0;
}