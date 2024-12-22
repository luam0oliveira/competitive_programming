/**
 *     author: demot.r
 *     created: 2024-12-22 11:35:00
 *     source: 
 *     description: 
**/

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
        int n;cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        
        for(int i=0;i<n;i++) {
            cin>>b[i];
        }
        int diff = 0;
        for(int i=0;i<n-1;i++) {
            if (a[i] > b[i+1]) diff += (a[i] - b[i+1]);
        }

        cout << diff + a[n-1]<<endl;

    }
    return 0;
}