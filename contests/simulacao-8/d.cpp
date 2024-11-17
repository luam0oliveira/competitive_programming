#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n;cin>>n;
    ll acc = 0;
    ll d = 5;
    while(n/d != 0) {
        acc+=n/d;
        d*=5;
    }
    cout <<acc<<endl;

    return 0;
}