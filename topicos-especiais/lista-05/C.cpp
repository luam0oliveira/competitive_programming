// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3743
// Greedy - Escalonamento de intervalos

#include<bits/stdc++.h>
using namespace std;

int main(){
  int l, p;
  vector<pair<int,int>> inter;
  while(cin>>l>>p && !(l == 0 && p==0)){
    inter.clear();
    for(int i = 0 ; i < p;i++){
      int xi, r;cin>>xi>>r;
      inter.push_back({max(xi-r,0), xi+r});
    }

    sort(inter.begin(), inter.end());
    int maiorX = 0;
    int cont = 0;
    for(int i = 0 ; i < p;i++){
      auto [inicio, fim] = inter[i];
      if (inicio > maiorX){
        break;
      }
      int j = 0;
      int maior = inter[i].second;
      while(j+i+1 < p && inter[i+j+1].first <= maiorX){
        j++;
        maior = max(maior, inter[i+j].second);
      }
      cont+=j;
      i+=j;
      maiorX = max(maiorX,maior);
      if (maiorX >= l){
        cont+=p-i-1;
        break;
      }
    }
    if (maiorX < l)
      cout<<"-1"<<endl;
    else
      cout<<cont<<endl;
  }
}