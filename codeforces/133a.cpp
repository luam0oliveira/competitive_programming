// https://codeforces.com/problemset/problem/160/A
// ad-rock

#include<bits/stdc++.h>
#define ll long long
#define QUAT(x) x*x;
using namespace std;

int main(){
    string s;cin>>s;
    int h = 0;
    for(int i =0 ;i<(int)s.size();i++){
        if (s[i] == 'H' || s[i] == 'Q' || s[i] == '+' ||  s[i] == '9') h++;
    }
    if (h)printf("YES\n");
    else printf("NO\n");

}
