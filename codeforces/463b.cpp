/**
 *     author: demot.r
 *     created: 2024-10-02 21:58:14
 *     source: https://codeforces.com/contest/463/problem/B
 *     description: ad-rock
**/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n;
    cin>>n;
    int atual = 0 ;
    ll acumulador = 0;
    ll minimum = 0;
    for(int i = 0; i < n;i++) {
        int a;cin>>a;
        acumulador += atual - a;
        if (acumulador < 0) {
            minimum = max(-acumulador, minimum);
        }
        atual = a;
    }

    cout<<minimum<<endl;
}   