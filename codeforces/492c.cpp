/**
 *     author: demot.r
 *     created: 2024-10-19 19:42:30
 *     source: https://codeforces.com/contest/492/problem/C
 *     description: ad-rock
**/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n,r,avg;cin>>n>>r>>avg;
    ll sum = 0;
    ll needed = avg*n;
    priority_queue<pair<int,int>> pq;
    for(int i = 0; i < n;i++){
        int a,b;cin>>a>>b;
        needed -= a;
        if (a != r) {
            pq.push({-b,a});
        }
    }

    while(needed > 0) {
        auto top = pq.top();pq.pop();
        ll a = top.second,b = -top.first;

        int utilizados = min(needed, r-a);
        needed-=utilizados;
        sum+=utilizados * b;
    }

    cout<<sum<<endl;
    return 0;
}