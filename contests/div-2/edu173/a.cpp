#include<bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define INF 1e9
#define EPS 1e-9
#define ALL(X) X.begin(), X.end()
using namespace std;

int main() {
    int t;cin>>t;
    while(t--) {
        ll n;cin>>n;
        int count = 0;
        while(n>3) {
            n>>=2;
            count++;
        }

        if (count == 0) cout << 1 << endl;
        else cout << (1L<<count)<<endl;
    }   
    return 0;
}