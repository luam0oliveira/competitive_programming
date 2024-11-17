/**
 *     author: demot.r
 *     created: 2024-11-16 10:14:51
 *     source: 
 *     description: 
**/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int k, n;cin>>k>>n;
    int count = (n+1)/2;
    string ans;
    int spc = 1;
    bool fs = n&1;
    for(int i=0;i<n;i++){
        if (spc == 2 || (spc == 1 && i == n-1)) {
            ans+='X';
            spc = 0;
        }else if (spc == 1 && count > k) {
            ans+='-';
            spc++;
            fs = (fs+1)%2;
            if (!fs) {
                count--;
            }
        } else if (spc == 0) {
            ans+='-';
            spc++;
        } else {
            ans+='X';
            spc = 0;
        }
    }
    // cout<<ans<<endl;
    if (count == k) {
        cout<<ans<<endl;
    }else{
        cout<<"*"<<endl;
    }
    return 0;
}