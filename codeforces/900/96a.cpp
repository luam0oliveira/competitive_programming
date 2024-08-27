// https://codeforces.com/problemset/problem/96/A
// ad-rock

#include<bits/stdc++.h>
#define ll long long
#define QUAT(x) x*x;
using namespace std;


int main(){
    string s;cin>>s;
    int pos =true, seguidos1 = 0, seguidos0 = 0;
    for(int i=0;i<(int)s.size();i++){
        if(s[i]=='1'){
            seguidos0=0;
            seguidos1++;
        }
        else{
            seguidos0++;
            seguidos1=0;
        }
        if(seguidos1==7 || seguidos0==7)pos=false;
    }
    if (pos) printf("NO\n");
    else printf("YES\n");
}
