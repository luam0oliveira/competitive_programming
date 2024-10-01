/**
 *     author: demot.r
 *     created: 2024-09-30 21:42:48
 *     source: https://codeforces.com/gym/105230/problem/C
 *     description: math
**/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9+7;

int fastPow(ll a, ll b) {  
    ll result = 1;

    if (b == 0) return 1;
    
    while(b > 0) {
        if (b & 1) {
            result = (result * a) % MOD;
        }
        b>>=1;
        a = (a * a) % MOD;
    }

    return (int) result;
}

ll mult (ll n, int quant) {
    ll result = 1;
    for(int i = 0; i < quant; i++) {
        result = (result*((n - i) % MOD)) % MOD;
    }

    return (int) result % MOD;
}

int gcdExtended(int a, int b, int &x, int &y) { 
    if (a == 0) { 
        x = 0; 
        y = 1; 
        return b; 
    } 

    int x1, y1;
    int gcd = gcdExtended(b%a, a, x1, y1); 

    x = y1 - (b/a) * x1; 
    y = x1; 

    return gcd; 
} 

int modInverse(int A, int M)
{
    int x, y;
    gcdExtended(A, M, x, y);

    int res = (x % M + M) % M;

    return res;
}


int main() {
    int t; cin>>t;
    while(t--) {
        ll x,n;cin>>n>>x;
        ll diff = (n - x);
        if (diff >= 365) {
            ::cout << 0 << endl;
            continue;
        }

        ll a = mult(n,diff);
        ll b = (365L*mult(364, diff)) % MOD;
        ll c = fastPow(365, n);
        ll fac = mult(diff, diff);
        b = (a * b) % MOD;
        fac = (fac * c) % MOD;
        ll xi = modInverse(fac, MOD);
        cout << (xi * b) % MOD << endl;
    }
}