/**
 *     author: demot.r
 *     created: 2024-11-28 15:27:42
 *     source: 
 *     description: 
**/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n, l;cin>>n>>l;
    vector<int> vec(n);
    for(int i=0;i<n;i++) {
        cin>>vec[i];
    }   

    sort(vec.begin(), vec.end());
    int count = 0;
    for(int i=n-1;i>=0;i--) {
        if (l >= (100 - vec[i])) {
            l -= (100 - vec[i]);
            count++;
        } else {
            break;
        }
        
    }
    cout<<count<<endl;
    return 0;
}