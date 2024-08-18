// https://br.spoj.com/problems/DESCULPA/
// Dynamic programming

#include <bits/stdc++.h>

using namespace std;

int p,f, n;
vector<vector<int>> dp;
vector<int> letras, desc;

int dpp(int t, int g){
  if (g < 0) return 0;
  if (dp[g][t] != -1) return dp[g][t];
  if (t < letras[g]) return dp[g][t] = dpp(t, g-1);

  return dp[g][t] = max(desc[g] + dpp(t - letras[g], g-1), dpp(t, g-1));
}


// funcao para printar quais bilhetes foram utilizados no pedido, feito para tr
// einar a recuperacao a partir da tabela de dp
void printItems(){
  int weight = p;
  for(int i = f-1; i > 0;i--){
    if (dp[i-1][weight] !=dp[i][weight] ){
      weight-=letras[i];
      cout<<i<<endl;
    }
  }
  if (dp[0][weight] != -1){
    cout<<0<<endl;
  }
}

int main() {
  int cases = 1;
  while(cin>>p>>f && !(p == 0 && f==0)){
    letras.assign(f,0);
    desc.assign(f,0);
    for(int i = 0 ; i < f;i++){
      cin>>letras[i]>>desc[i];
    }

    dp.assign(f, vector<int>(p+1, -1));
    dpp(p,f-1);

    cout<<"Teste "<<cases++<<endl;
    cout<<dp[f-1][p]<<endl<<endl;
  }
}