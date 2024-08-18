// https://olimpiada.ic.unicamp.br/pratique/ps/2021/f2/sanduiche/
// Ad-rock

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int btc[21];

int main(){
  int n,m;cin>>n>>m;
  vector<vector<int>> numeros(21);


  int minimo = n;
  for(int i = 0;i<m;i++){
    int a,b;cin>>a>>b;
    a--;b--;
    numeros[a].push_back(b);
    numeros[b].push_back(a);
    
    // numeros[a][b] = 0;
    // numeros[b][a] = 0;
    // numeros[a][0]--;
    // numeros[b][0]--;
    // minimo = min({numeros[b][0], numeros[a][0], minimo});
  }

  int cont=0;
  for(int i = 0; i < 20;i++){
    for(auto g: numeros[i]){
      btc[i]|=1<<g;
    }
  }


  int bitmask = 1 << n;
  for(int i = 1; i < bitmask;i++){
    int aux = 0;
    for(int j = 0; j<n;j++){
      if (i&(1<<j))
        aux |= btc[j];
    }

    if(!(aux&i)) cont++;
  }
  cout<<cont<<endl;


  // int cont =0;
  // int pares = n;
  // set<vector<int>> pp;
  // for(int i = 1 ; i<=n;i++){
  //   vector<int> h(21,0);
  //   numeros[i][0] = 0;
  //   h[i] = 1;
  //   pp.insert(h);
  // }

  // set<vector<int>> ant = pp;
  // while(cont <= minimo){
  //   cout<<"AHHA"<<endl;
  //   set<vector<int>> hh;
  //   for(auto it = ant.begin();it!=ant.end();it++){
  //     vector<int> vv = *it;
  //     for(int i = 1; i<=n;i++){
  //       for(int j = 1; j<=n;j++){
  //         if((*it)[j] == 0 && numeros[i][j] == 1){
  //           cout<<i<<endl;
  //           vv[j] = 1;
  //           hh.insert(vv);
  //           pp.insert(vv);
  //           vv[j] = 0;
  //         }
  //       }
  //     }
  //   }
  //   ant = hh;
  //   cont++;
  // }

  // for(auto i = ant.begin();i!=ant.end();i++){
  //   vector<int> vv = *i;
  //   cout<<"AHA"<<endl;

  //   for(int j = 1;j<vv.size();j++){
  //     cout<<(vv[j])<<" ";
  //   }
  //   cout<<endl;
  // }
  // cout<<pp.size()<<endl;
}