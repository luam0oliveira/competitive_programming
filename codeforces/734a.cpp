// https://codeforces.com/contest/734/problem/A
// ad-rock

#include<bits/stdc++.h>
#define ll long long
#define QUAT(x) x*x;
using namespace std;

int main(){
    int n;scanf("%d ",&n);
    string matchs;cin>>matchs;
    int a=0,d=0;
    for(int i=0;i<n;i++){
        if (matchs[i]=='A') a++;
        else d++;
    }
    if (a==d) printf("Friendship\n");
    else if (a>d) printf("Anton\n");
    else printf("Danik\n");
}
