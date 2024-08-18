#include<bits/stdc++.h>

using namespace std;


int main(){
  int l,c,m;cin>>l>>c>>m;
  
  vector<int> colunas;
  vector<int> linhas;
  for(int i = 0 ; i<l;i++){
    linhas.push_back(i);
  }
  for(int i = 0 ; i<c;i++){
    colunas.push_back(i);
  }


  for(int i = 0; i<m;i++){
    char op;
    int a,b;cin>>op>>a>>b;
    a--;b--;
    int aux;
    if(op == 'C'){
      aux = colunas[a];
      colunas[a] = colunas[b];
      colunas[b] = aux;
    }
    else{
      aux = linhas[a];
      linhas[a] = linhas[b];
      linhas[b] = aux;
    }
  }
  vector<vector<int>> matriz(l, vector<int>(c));
  for(int i = 0 ; i<l;i++){
    for(int j = 0; j<c;j++){
      matriz[linhas[i]][colunas[j]] = i*c + j+1;
    }
  }

  for(int i = 0 ; i < l;i++){
    cout<<matriz[i][0];
    for(int j = 1 ; j < l;j++)
      cout<<" "<<matriz[i][j];
    cout<<endl;
  }
}