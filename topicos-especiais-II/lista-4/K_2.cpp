#include<bits/stdc++.h>
#include<bits/extc++.h>
#define ll long long
#define ii pair<int,int>
#define INF 1e9
#define EPS 1e-9
#define ALL(X) X.begin(), X.end()
#define LSOne(S) (S & -(S))
#define ZZZZ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using namespace __gnu_pbds;
// Template to use pbds
template<class T>
using Tree = tree<T, null_type, less<T>,splay_tree_tag, tree_order_statistics_node_update>;
// Template to use pbds
typedef vector<ii> vii;

int main() {
  ZZZZ
  int n;cin>>n;
  Tree<int> T;
  for(int i=0;i<n;i++) {
    T.insert(i+1);
  }

  vector<pair<int,int>> queries(n/2);
  for(int i=0;i<n/2;i++) {
    cin>>queries[i].first;
  }
  for(int i=0;i<n/2;i++) {
    cin>>queries[i].second;
  }

  for(int i=0;i<n/2;i++) {
    auto to = T.find_by_order(queries[i].first-1);
    queries[i].first = *to;
    T.erase(to);
    to = T.find_by_order(queries[i].second-1);
    queries[i].second = *to;
    T.erase(to);
  }

  for(int i=0;i<n/2;i++) {
    cout<<queries[i].first<<" ";
  }
  cout<<endl;
  for(int i=0;i<n/2;i++) {
    cout<<queries[i].second<<" ";
  }

  cout<<endl;

  return 0;
}