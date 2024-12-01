/**
 *     author: demot.r
 *     created: 2024-11-30 11:47:15
 *     source: 
 *     description: 
**/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int t;cin>>t;
    while(t--) {
        int n,m,k; cin>>n>>m>>k;
        string s;cin>>s;
        int op = 0;
        for(int i=0;i<n;) {
            if (s[i] == '0') {
                int count = 0;
                for(;i<n && count < m;i++) {
                    if (s[i] == '1') {
                        break;
                    }
                    count++;
                }

                if (count >= m) {
                    op++;
                    i+=k-1;
                }
            } else {
                i++;
            }
        }
        cout<<op<<endl;
    }   
    return 0;
}