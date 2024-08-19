  // https://br.spoj.com/problems/MIOJO/
  // ad-rock

  #include <bits/stdc++.h>

  using namespace std;

  int main(){
    int a,b,c;cin>>a>>b>>c;
    int ac = 0, acc=0;
    while(abs(ac-acc)!= a){
      if(ac - acc < 0){
        ac+=b;
      }
      else{
        acc+=c;
      }
    }
    cout<<max(acc,ac)<<endl;
  }
