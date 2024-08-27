// https://codeforces.com/problemset/problem/318/A
// ad-rock

#include<bits/stdc++.h>
#define ll long long
#define QUAT(x) x*x;
using namespace std;

int main(){
    ll n,k;cin>>n>>k;
    ll metade = (n+1)/2, ans;
    if (k <= metade) ans = k*2-1;
    else ans = (k-metade)*2;

    cout<<ans<<endl;
}
