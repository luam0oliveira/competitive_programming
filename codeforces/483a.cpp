// https://codeforces.com/contest/483/problem/A
// ad-rock

#include<bits/stdc++.h>
#define ll long long
#define QUAT(x) x*x;
using namespace std;

ll gcd(ll a, ll b){
    if (a < b) return gcd(b,a);

    while(b!=0){
        ll aux = b;
        b = a%b;
        a = aux;
    }

    return a;
}


int main(){
    ll l,r;cin>>l>>r;
    ll i, j, k;
    int pos = false;
    for(i = l; i <= r && !pos; i++){
        for(j = i+1; j <= r && !pos; j++){
            ll x = gcd(i,j);
            if (x != 1) continue;
            for(k = j+1; k <= r && !pos; k++){
                ll y = gcd(j,k);
                if (y != 1) continue;
                if (gcd(i,k) != 1) pos = true;
            }
        }
    }

    if (pos) cout <<i-1<<" "<<j-1<<" "<<k-1<<endl;
    else cout<<-1<<endl;
}
