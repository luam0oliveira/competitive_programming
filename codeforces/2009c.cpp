// https://codeforces.com/contest/2009/problem/C
// ad-rock

#include<bits/stdc++.h>
#define ll long long
#define QUAT(x) x*x;
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int x,y,k;cin>>x>>y>>k;
        int xa = ceil(x*1.0/k*1.0);
        int ya = ceil(y*1.0/k*1.0);
        
        int minimo = max(xa,ya)*2;

        if (xa > ya) cout << minimo-1<<endl;
        else cout<<minimo<<endl;
    }    
}
