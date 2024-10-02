#/**
 *     author: demot.r
 *     created: 2024-10-01 21:13:59
 *     source: https://codeforces.com/contest/680/problem/B
 *     description: ad-rock
**/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n,a; cin>>n>>a;
    a--;
    vector<int> cities(n);
    for(int i =0;i<n;i++) {
        cin>>cities[i];
    }
    int count=0;
    for(int i = 0;i<n;i++) {
        int m = a-i >= 0 && cities[a-i];
        int M = a+i < n && cities[a+i];

        if((m && M)){
            count+= 1 + ((a-i) != (a+i));
        } 
        else if ((m && a+i >= n) || (M && a - i < 0)){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}
