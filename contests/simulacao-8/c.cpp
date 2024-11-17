/**
 *     author: demot.r
 *     created: 2024-11-16 14:09:01
 *     source: 
 *     description: 
**/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool usado[1000001];

int main() {
    ll n;cin>>n;
    memset(usado, 0, sizeof(usado));
    ll sum = (n*(n+1))/2;
    vector<int> a;
    if (sum % 2) {
        cout <<"NO"<<endl;
    }else {
        ll obj = sum/2;
        ll ss = 0;
        for(int i =n;n>0;i--) {
            if (ss + i > obj) break;
            usado[i] = true;
            a.push_back(i);
            ss += i;
        }
        cout<<"YES"<<endl;
        if (obj - ss > 0) {
            a.push_back(obj - ss);
            usado[obj - ss] = true;
        }
        cout<<a.size()<<endl;
        cout<< a[0];
        for(int i=1;i<a.size();i++) {
        cout<< " "<< a[i];
        }
        cout<<endl;
        bool primeiro = true;
        cout<<n-a.size()<<endl;
        for(int i=1;i<=n;i++) {
            if (!usado[i] && primeiro) {
                cout <<i;
                primeiro = false;
            }else if (!usado[i]) {
                cout<<" "<<i;
            }
        }
        cout<<endl;
    }

    return 0;
}