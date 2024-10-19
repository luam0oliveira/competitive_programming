/**
 *     author: demot.r
 *     created: 2024-10-19 11:09:08
 *     source: https://codeforces.com/contest/2030/problem/0
 *     description: greedy
**/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int t;cin>>t;
    while(t--){
        ll maior=0, menor=1e4;
        int n;cin>>n;
        for (int i = 0; i < n;i++){
            int a;cin>>a;
            if (a > maior){
                maior = a;
            }
            if (a < menor) {
                menor = a;
            }
        }

        cout<<(maior-menor)*(n-1)<<endl;
    }
    return 0;
}