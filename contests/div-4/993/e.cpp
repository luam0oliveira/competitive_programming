/**
 *     author: demot.r
 *     created: 2024-12-17 20:04:36
 *     source: https://codeforces.com/contest/2044/problem/E
 *     description: math
**/


#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll maximum = 1e9+10;

int main() {
    int t;cin>>t;
    while(t--) {
        ll k, l1, r1, l2, r2;
        cin>> k>>l1>>r1>>l2>>r2;
        ll kn = 1;
        ll count = 0;

        for(int i=0;i<32; i++) {
            ll yleft, yright;
            ll xleft, xright;
            
            yleft = (l2 + kn-1)/kn;  // first element y in interval
            yright = r2/kn; // last element y in interval

            xleft = max(yleft, l1); // first element x in interval
            xright = min(yright, r1); // last element x in interval

            count += max(xright - xleft + 1, 0LL);
            kn *= k;
            if (kn >= maximum) break;
        }

        cout << count<<endl;
    }   
    return 0;
}