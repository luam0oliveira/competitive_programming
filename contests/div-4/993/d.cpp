/**
 *     author: demot.r
 *     created: 2024-12-15 12:13:08
 *     source: 
 *     description: 
**/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int t;cin>>t;
    while(t--) {
        set<int> numbers;
        int n;cin>>n;
        vector<int> ordem(n);
        map<int, int> pos;
        for(int i=0;i<n;i++) {
            ordem[i] = i+1;
            pos[i+1] = i;
        }

        for(int i=0;i<n;i++) {
            int a; cin>>a;
            if (numbers.find(a) == numbers.end()) {
                pos[ordem[i]] = pos[a];
                swap(ordem[pos[a]], ordem[i]);
                pos[a] = i;
                
                
            }
            numbers.insert(ordem[i]);
        }

        cout<<ordem[0];
        for(int i=1;i<n;i++) {
            cout<<" " << ordem[i];
        }
        cout<<endl;
    }   
    return 0;
}