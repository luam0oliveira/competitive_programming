#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<ll> g(k);
        for(int i =0;i<k;i++){
            int b,c;cin>>b>>c;
            g[b-1]-=c;
        }
        sort(g.begin(), g.end());
        ll sum = 0;
        for(int i =0;i<n && i < k;i++){
            sum-=g[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}