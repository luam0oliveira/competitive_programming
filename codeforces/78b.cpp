/**
 *     author: demot.r
 *     created: 2024-10-16 09:10:31
 *     source: https://codeforces.com/contest/78/problem/B
 *     description: simulation
**/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n;cin>>n;
    string s = "ROYGBIV";
    cout<<s;
    for(int i = 7; i < n;i++){
        cout<<s[3+(i-7)%4];
    }
    cout<<endl;
    return 0;
}