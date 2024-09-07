// https://codeforces.com/contest/707/problem/A
// ad-rock

#include<bits/stdc++.h>
#define ll long long
#define QUAT(x) x*x;
using namespace std;

map<string,int> score;

int main(){
    int n, m;cin>>n>>m;
    int bw = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            string c; cin>>c;
            if (c != "B" && c != "W" && c!="G") bw = false;
        }
    }
    if (bw) cout <<"#Black&White\n";
    else cout<<"#Color\n";
}
