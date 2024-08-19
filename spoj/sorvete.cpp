// https://br.spoj.com/problems/SORVETE/
// Greedy - Escalonamento de intervalos

#include <bits/stdc++.h>

using namespace std;

void fastIO(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

pair<int,int> inter[5001];
int main(){
  fastIO();
  int l,p, cases=1;
  while(cin>>l>>p && !(l == 0 && p == 0)){
    for(int i = 0; i<p;i++){
      cin>>inter[i].first>>inter[i].second;
    }

    sort(inter, inter + p);
    cout<<"Teste "<<cases++<<endl;
    int inicio = inter[0].first, fim = inter[0].second;
    for(int k = 1 ; k < p;k++){
      auto [s, e] = inter[k];
      if (s > fim){
        cout<<inicio<<" "<<fim<<endl;
        inicio = s;
        fim = e;
      }else{
        fim = max(fim, e);
      }
    }
    cout << inicio<<" "<<fim<<endl<<endl;
  }  
}
