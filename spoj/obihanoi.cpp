// https://br.spoj.com/problems/OBIHANOI/
// Ad-rock

#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,cases=1;
  while(cin>>n && n!=0){
    cout<<"Teste "<<cases++<<endl;
    cout<<((int)pow(2,n))-1<<endl<<endl;
  }
}
