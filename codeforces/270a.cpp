// http://codeforces.com/contest/270/problem/A
// ad-rock

#include<bits/stdc++.h>
#define ll long long
#define QUAT(x) x*x;
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int angle;cin>>angle;

        angle = 180 - angle;
        if ((360 % angle) == 0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
