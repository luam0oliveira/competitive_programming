// https://codeforces.com/contest/807/problem/A
// ad-rock

#include<bits/stdc++.h>
#define ll long long
#define QUAT(x) x*x;
using namespace std;

int main(){
    int n;cin>>n;
    int menor = 1e5;
    bool decrescente = true, diff = false;
    for(int i = 0;i < n;i++){
        int a,b;cin>>a>>b;
        if (menor < a) decrescente = false;
        if (a != b) diff = true;
        menor = min(a, menor);
    }

    if (diff) cout<<"rated\n"<<endl;
    else if (!decrescente && !diff)cout<<"unrated\n";
    else cout<<"maybe\n";
}
