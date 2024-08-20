// https://br.spoj.com/problems/OBITETRI/
// Ordenacao

#include<bits/stdc++.h>
using namespace std;

int main(){
  int cases = 1;
  int n;
  while(cin>>n && n!=0){
    string name;
    vector<pair<int,string>> pontuacoes;
    for(int i =0 ;i < n;i++){
      cin>>name;
      int soma = 0;
      int menor = 1e4;
      int maior = 0;
      for(int j = 0; j<12;j++){
        int pont;cin>>pont;
        soma+=pont;
        menor = min(pont, menor);
        maior = max(pont, maior);
      }
      soma -= menor+maior;
      pontuacoes.push_back({-soma, name});
    }
    sort(pontuacoes.begin(), pontuacoes.end());
    cout<<"Teste "<<cases++<<endl;
    int j =0 ;
    int ant = -1;
    for(int i = 0;i<n;i++){
      if (ant != pontuacoes[i].first) j = i+1;

      ant = pontuacoes[i].first;

      cout<<j<<" "<<-pontuacoes[i].first<< " "<<pontuacoes[i].second<<endl;
    
    }
    cout<<endl;
  }   
}