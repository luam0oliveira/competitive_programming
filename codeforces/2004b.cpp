// https://codeforces.com/problemset/problem/2004/B
// ad-rock

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;cin>>n;
    while(n--){
        int l,r,L,R;cin>>l>>r>>L>>R;
        
        int ans;
        if (l == L && r == R) ans = R - L;
        else if (r < L || R < l){
            ans = 1;
        } else{
            ans = abs(max(L,l) - min(R,r));
            ans += min(l,L) <= max(l,L) && max(l,L) <= min(r,R);
            ans += max(l,L) <= min(r,R) && min(r,R) <= max(r,R);
            ans -= L == l;
            ans -= R == r;
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}
