#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;cin>>n>>m;
  vector<int> cor(m+1, 0), unv(m+1,0);
  vector<vector<int>> m_cor(n,vector<int>());
  for(int i=0;i<n;i++) {
    int aa;cin>>aa;
    for(int j=0;j<aa;j++) {
      int a;cin>>a;
      m_cor[i].push_back(a);
      cor[a]++;
    }
  }
  int ans = 0;
  for(int i=0;i<n;i++) {
    int count1 = 0;
    int count1_t = 1;
    int unk = 0;
    for(auto u: m_cor[i]) {
      cout << u <<" ";
      if (count1_t < u) count1_t = u;
      if (cor[u] == count1_t) count1++;
      else if (!unv[u]) unk++;
    }
    cout << count1<<endl;
    if (count1>=m_cor[i].size()) ans++;
    else {
      for(auto u: m_cor[i]) {
        unv[u] = 1;
      }
      ans+=unk;
    }
  }

  cout << ans<<endl;

  cout<<min(ans, min(n,m))<<endl;
}