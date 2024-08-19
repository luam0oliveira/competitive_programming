// https://br.spoj.com/problems/REDOTICA/
// Grafos - MST

#include <bits/stdc++.h>

using namespace std;

int pai[101];
int altura[101];

int find(int u){
  if (u != pai[u]) pai[u] = find(pai[u]);
  return pai[u];
}

bool join(int u, int v){
  u = find(u);
  v = find(v);

  if (u == v) return false;

  if (altura[u]>altura[v]){
    pai[v] = u;
  }else{
    pai[u] = v;
    if (altura[u]==altura[v])
      altura[v]++;
  }
  return true;
}


int main() {
  int n,m,cases=1;
  while(cin>>n>>m && !(n==0 && m==0)){
    for(int i = 0 ; i <= n;i++){
      pai[i]=i;
      altura[i]=0;
    }
    vector<pair<int,pair<int,int>>> caminhos;
    for(int i = 0 ; i < m;i++){
      int x,y,z;
      cin>>x>>y>>z;
      caminhos.push_back({z,{min(x,y), max(x,y)}});
    }
    sort(caminhos.begin(), caminhos.end());
    int cont=0;
    cout<<"Teste "<<cases++<<endl;
    for(int i = 0;i<m;i++){
      if (join(caminhos[i].second.first, caminhos[i].second.second)){
        // cout<<caminhos[i].first<<endl;
        cout<< caminhos[i].second.first<<" "<<caminhos[i].second.second<<endl;
      }
    }
    cout<<endl;
  }
}
