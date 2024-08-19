// https://br.spoj.com/problems/TRILHAS/
// ad-rock

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;cin>>n;
  int menor = 1e6;
  int id = 0;
  for(int i =0 ;  i< n;i++){
    int q;cin>>q;
    int indo = 0;
    int voltando = 0;
    int ant;
    cin>>ant;
    for(int j=1;j<q;j++){
      int v;cin>>v;
      if (v - ant > 0){
        indo += v - ant;
      }else{
        voltando += ant-v;
      }
      ant = v;
    }
    if (menor > min(indo, voltando)){
      id=i;
      menor = min(indo, voltando);
    }
  }
  cout<<id+1<<endl;
}
