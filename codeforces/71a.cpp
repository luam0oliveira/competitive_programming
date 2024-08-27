// https://codeforces.com/problemset/problem/71/A
// ad-rock

#include<bits/stdc++.h>
#define ll long long
#define QUAT(x) x*x;
using namespace std;


int main(){
    int t;cin>>t;
    while(t--){
        string w;cin>>w;
        if (w.size()>10) printf("%c%d%c\n", w[0], (int)w.size()-2, w[w.size()-1]);
        else printf("%s\n", w.c_str());
    }
}
