// https://br.spoj.com/problems/VIVO/
// Ad-rock

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,m, cases=1;
  while(cin>>n>>m && !(n == 0 && m==0)){
    vector<int> ordem(n);
    for(int i= 0;i<n;i++)
      cin>>ordem[i];
    for(int k=0;k<m;k++){
      int q,op,v;cin>>q>>op;
      int ele = 0;
      for(int i=0;i<q;i++){
        cin>>v;
        if (v!=op){
          ordem.erase(ordem.begin()+i-ele);
          ele++;
        }
      }
    }
    cout<<"Teste "<<cases++<<endl;
    cout<<ordem[0]<<endl;

  }
}
