// https://codeforces.com/contest/469/problem/A
// ad-rock

#include<bits/stdc++.h>
#define ll long long
#define QUAT(x) x*x;
using namespace std;

bitset<100> levels;

int main(){
    int n;cin>>n;
    levels.reset();
    for(int i =0;i<n;i++){
        levels.set(i);
    }
    int m,l;cin>>m;
    for(int i = 0;i<m;i++){
        cin>>l;
        levels.reset(l-1);
    }
    cin>>m;
    for(int i = 0;i<m;i++){
        cin>>l;
        levels.reset(l-1);
    }

    if (levels.count() == 0) cout<<"I become the guy.\n";
    else cout<<"Oh, my keyboard!\n";    
}
