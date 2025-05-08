#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
// SOLUTION AFTER EDITORIAL
int maxDepth, farthest, farthestLeafCount;

void prof(int u, int p, int depth) {
  if (maxDepth < depth) {
    farthest = u, maxDepth = depth;
    farthestLeafCount = 0;
  }
  if (maxDepth == depth) farthestLeafCount++;

  for(auto v: adj[u]) {
    if (v != p) prof(v, u, depth+1);
  }
}

int main() {
  int n, p;cin>>n>>p;
  adj.assign(n,{});
  
  for(int i=0;i<n-1;i++) {
    int a,b;cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int leafs = 0;
  for(int i=0;i<n;i++) {
    leafs+=adj[i].size()==1;
  }
  
  cout << 2*(p/leafs) + min(p%leafs, 2)<<endl;
}