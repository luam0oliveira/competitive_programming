/**
 *     author: demot.r
 *     created: 2024-10-18 09:18:03
 *     source: https://codeforces.com/contest/746/problem/B
 *     description: simulation
**/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

//mine solution
void solve0() {
    int n;cin>>n;
    string s, ff(n, 'a');cin>>s;

    int meio = n/2;

    if (n & 1) {
        ff[meio] = s[0];

        for(int i = 1; i <= meio; i++) {
            ff[meio-i] = s[1 + (i-1)*2];
            ff[meio+i] = s[i*2];
        }
    } else {
        for(int i = 0; i < meio; i++) {
            ff[meio-1-i] = s[i*2];
            ff[meio+i] = s[i*2+1];
        }       
    }

    cout<<ff<<endl;
}
//solution ytb
void solve1() {
    int n;cin>>n;
    string s;cin>>s;
    string ff;
    ff.insert(ff.end(), s[0]);
    for(int i = 1; i < n;i++){
        if (i & 1)
            ff.insert(ff.begin(), s[i]);
        else
            ff.insert(ff.end(), s[i]);
    }

    if (n % 2  == 0) 
    reverse(ff.begin(), ff.end());
    cout<<ff<<endl;
}

int main() {
    solve0();
    return 0;
}