// https://br.spoj.com/problems/SORVETE/
// Grafos - Ordenamento topologico com cicloss

#include <bits/stdc++.h>

using namespace std;

map<string,int> vertices;
vector<string> names;
vector<int> mark;
vector<vector<int>> rel;
vector<int> markH;
vector<int> passagem;
bool pos;

void dfs(int u){
  mark[u] = true;
  markH[u] = true;
  for(int adj: rel[u]){
    if (markH[adj]){
      pos = false;
      break;
    }
    if (!mark[adj])
      dfs(adj);
  }
  markH[u] = false;
  passagem.push_back(u);
}

int main(){
  int p, cases=1;
  while(cin>>p && p!=0){
    pos = true;
    names.clear();
    markH.assign(p,0);
    vertices.clear();
    mark.assign(p,0);
    rel.assign(p,{});
    passagem.clear();
    for(int i =0;i<p;i++){
      string name;
      cin>>name;
      vertices[name] = i;
      names.push_back(name);
    }
    vector<int> iniciais;
    for(int i =0;i<p;i++){
      int q, u,v;
      string inicio,fim;cin>>inicio>>q;
      u = vertices[inicio];
      for(int j = 0 ; j <q;j++){
        cin>>fim;
        rel[u].push_back(vertices[fim]);
      }
    }
    for(int i = 0 ; i < p;i++){
      if (!mark[i])
        dfs(i);
    }
    cout<<"Teste "<<cases++<<endl;
    if (pos){
      cout<<names[passagem[0]];
      for(int i = 1; i < p;i++){
        cout<<" "<<names[passagem[i]];
      }
    }else{
      cout<<"impossivel";
    }
    cout<<endl<<endl;
  }
}