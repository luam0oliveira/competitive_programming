/**
 *     author: demot.r
 *     created: 2024-10-16 09:00:22
 *     source: https://codeforces.com/contest/227/problem/B
 *     description: ad-rock
**/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n;cin>>n;
    pair<int, int> a[n];
    for(int i =0; i<n;i++){
        int b;cin>>b;
        a[b-1] = {i+1, n-i};
    }
    int m;cin>>m;
    ll sA =0, sB = 0; 
    for(int i = 0; i<m;i++){
        int b;cin>>b;
        sA+=a[b-1].first;
        sB+=a[b-1].second;
    }
    cout<<sA<<" "<<sB<<endl;
    return 0;
}
