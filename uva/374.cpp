// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=310
// ad-rock

#include<bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define QUAT(x) x*x;
using namespace std;

ll fastpow(ll a, ll b, ll mod){
    ll ans = 1;

    while (b>0){
        if (b & 1){
            ans = (ans*a) % mod;
        }
        b>>=1;
        a = (a*a) % mod;
    }
    return ans;
}


int main(){
    ll a,b,c;
    while(cin>>a>>b>>c){
        cout << fastpow(a,b,c)<<endl;
    }
    return 0;
}
