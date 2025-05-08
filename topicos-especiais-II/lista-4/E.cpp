#include <bits/stdc++.h>
#define int long long
using namespace std;

int gcd(int a, int b) {
  if (b > a) return gcd(b,a);

  while (b) {
    int aux = b;
    b = a % b;
    a = aux;
  }

  return a;
}

pair<double, pair<int,int>> calcLis(vector<int> &number) {
  int k = 0, n = number.size();
  vector<int> maior(n), maior_id(n);
  double bestHeight = 0;
  pair<int,int> escolhido = {0,1};
  for(int i=0;i<n;i++) {
    int pos = lower_bound(maior.begin(), maior.begin() + k, number[i]) - maior.begin();
    if (pos == k) {
      k++;
    } else if (pos == 0){
      double alturaNova = abs(i - maior_id[pos]) - 1 + ((double)(maior[pos] - number[i-1]))/(1.0*(number[i] - number[i-1]));
      if (alturaNova > bestHeight) {
        escolhido = {(abs(i - maior_id[pos]) - 1)*(abs(number[i] - number[i-1])) - maior[pos] + number[i-1], -(number[i] - number[i-1])};
        bestHeight = alturaNova;
      }
    }
    maior_id[pos] = i;
    maior[pos] = number[i];
  }
  return {bestHeight, escolhido};
}

// A ideia é utilizar a lis para encontrar dois pontos, um que era maior e outro que é maior atualmente
// com isso temos a garantia de que não há nenhum monte maior entre esses dois montes e é possível fazer
// uma linha horizontal

signed main() {
  int n;cin>>n;
  vector<int> heights;
  for(int i=0;i<n;i++) {
    int a;cin>>a;
    heights.push_back(-a);
  }

  auto height = calcLis(heights);
  
  reverse(heights.begin(), heights.end());
  height = max(calcLis(heights), height);

  int gc = gcd(height.second.first, height.second.second);
  int nf =height.second.first/gc, ng = height.second.second/gc;  
  if (ng == 1) cout << nf;
  else {
    cout << nf <<"/"<<ng;
  }
  cout<< endl;

}