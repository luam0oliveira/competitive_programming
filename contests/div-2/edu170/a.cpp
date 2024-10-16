/**
 *     author: demot.r
 *     created: 2024-10-14 11:35:04
 *     source: https://codeforces.com/contest/2025/problem/0
 *     description: ad-rock
**/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int t;cin>>t;
    while(t--){
        string s,ss;cin>>s>>ss;
        int count = s.size() + ss.size();
        int sz = min(s.size(), ss.size());
        int i;
        int usou = false;
        for(i = 0; i < sz; i++) {
            if (s[i] == ss[i]){
                count--;
                usou = true;
            }
            else {
                break;
            }
        }
        if (usou) count++;
        cout<<count<<endl;
    }
    return 0;
}
