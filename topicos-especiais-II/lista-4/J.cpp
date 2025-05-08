#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

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

// int getPath(int u, int dest, int p, vector<int>&path) {
//   if (u == dest) {
//     path.push_back(u);
//     return true;
//   }
//   for(auto v: adj[u]) {
//     if (v != p) {
//       if (getPath(v, dest, u, path)) {
//         path.push_back(u);
//         return 1;
//       }
//     }
//   }
//   return 0;
// }


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

  maxDepth = 0;
  farthest = 0;
  prof(0, -1, 0);

  int u = farthest;
  maxDepth = 0;
  prof(u, -1, 0);
  int v = farthest;
  if (maxDepth == n-1) cout << p << endl;
  else {
    int minimum = p/(n-1);
    // cout << leafs << endl;
    // p-=minimum*maxDepth; // valores valores que podem ser alocados
    
    int ans=minimum*maxDepth;
    int pLeaf = (p+leafs-1)/leafs;
    
    // cout << ans << endl;
    // if (ans == 0) {
    //   if (p%leafs == 1) ans +=1;
    //   else if (p%leafs >= 2) ans += 2;
    // }
    
    // else if (p%leafs) {
    //   // cout<<"Z"<<endl;
    //   ans++;
    // }
    // cout << p%leafs<<endl;
    cout << ans << endl;
  }
  // cout << maxDepth << endl;
  // int minimum = (p+maxDepth-1)/maxDepth;
  // maxDepth--;
  // cout << ((p-minimum)/maxDepth)*maxDepth + minimum<<endl;
  // cout << p-minimum<<endl;
  // cout << minimum << endl;
  // cout << ((p - minimum)*maxDepth) << endl;
}