#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int t;cin>>t;
  while(t--) {
    int n,m;cin>>n>>m;
    vector<pair<ll, vector<int>>> sums(n);
    for(int i=0;i<n;i++) {
      ll sum = 0;
      for(int j=0;j<m;j++) {
        int a;cin>>a;
        sum+=a;
        sums[i].second.push_back(a);
      }
      sums[i].first = sum;
    }

    sort(sums.rbegin(), sums.rend());
    ll ans = 0, pref = 0;
    for(int i=0;i<n;i++) {
      for(int j=0;j<m;j++) {
        pref += sums[i].second[j];
        ans += pref;
        // cout<<ans<<endl;
      }
    }
    cout<<ans<<endl;
  }
}