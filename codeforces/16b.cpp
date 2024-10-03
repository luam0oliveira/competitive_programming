/**
 *     author: demot.r
 *     created: 2024-10-02 21:37:44
 *     source: https://codeforces.com/contest/16/problem/B
 *     description: ad-rock
**/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> caixas(m);
    for(int i = 0; i < m;i++) {
        cin>>caixas[i].second>>caixas[i].first;
    }   
    sort(caixas.begin(), caixas.end());
    ll count  = 0;
    for(int i = m-1; i >= 0;i--) {
        if (n <= 0) break;
        ll tiradas = (caixas[i].second - max(caixas[i].second - n, 0)) * caixas[i].first;
        n -= caixas[i].second;
          
        count += tiradas;
    }
    cout<<count<<endl;
    return 0;
}