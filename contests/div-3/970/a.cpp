#include<bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define QUAT(x) x*x;
using namespace std;

// 23

int main(){
    int t;cin>>t;
    while(t--){
        int a,b;cin>>a>>b;
        int paresA = a/2;

        if (((b%2==1 && paresA!=0) || b%2 == 0) && a % 2 != 1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
