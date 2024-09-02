#include<bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define QUAT(x) x*x;
using namespace std;

ll calcN(ll s){
    ll delta = 1 + 8*s;
    int sq = sqrt(delta);
    return (sq-1)/2;
}


int main(){
    int t;cin>>t;
    while(t--){
        int l,r;cin>>l>>r;
        cout<<1+calcN(r-l)<<endl;
    }
    return 0;
}
