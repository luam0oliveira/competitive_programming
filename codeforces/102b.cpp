/**
 *     author: demot.r
 *     created: 2024-10-15 22:13:34
 *     source: https://codeforces.com/contest/102/problem/B
 *     description: simulation
**/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    string s;cin>>s;
    int count = 0;
    while(s.size() > 1) {
        string n;
        int sum = 0;
        for(int i = 0; i < (int) s.size(); i++) {
            sum += s[i] - '0';
        }
        while(sum > 0) {
            n += (sum % 10) + '0';
            sum/=10;
        }
        s = n;
        count++;
    }
    cout<<count<<endl;
    return 0;
}
