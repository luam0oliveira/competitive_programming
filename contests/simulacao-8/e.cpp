/**
 *     author: demot.r
 *     created: 2024-11-16 19:37:23
 *     source: 
 *     description: 
**/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int t;cin>>t;
    ll mod = 1e9 + 7;
    while(t--){
        ll a,b;cin>>a>>b;


        ll mult = 1;
        while(b) {
            if(b&1){
                mult = (mult*a) % mod;
            }
            b>>=1;
            a = (a*a)%mod;
        }

        cout<<mult<<endl;
    }
    return 0;
}