// https://olimpiada.ic.unicamp.br/pratique/pu/2019/f2/matriz/
// Ad-rock

#include <bits/stdc++.h>
using namespace std;

int n,m;

vector<vector<int>> matrizBool, matriz;

bool verificaSubMatriz(int x, int y){
  if (x + 1 >= n || y + 1 >= m) return false;
  
  return matriz[x][y] + matriz[x+1][y+1] <= matriz[x][y+1] + matriz[x+1][y];
}


int c2(vector<int> &hist){
  int maximo = 0;
  for(int i = 1; i < hist.size()-1;i++){
    int j0 = i;
    // if (hist[i] == 0) continue;
    while(j0 > 0 && hist[j0] >= hist[i]){
      j0--;
    }
    int j1 = i;
    while(j1 < m && hist[j1] >= hist[i]){
      j1++;
    }
    maximo = max(maximo, (j1 - j0) * (hist[i]+1));
  }

  return maximo;
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
  cin>>n>>m;

  matrizBool.assign(n, vector<int>(m));
  matriz.assign(n, vector<int>(m));

  for (int i =0;i<n;i++){
    for (int j =0;j<m;j++){
      cin >> matriz[i][j];
    }
  }

  int maxi = 0;
  vector<int> hist(m+1);
  hist[m] = 0;
  hist[0] = 0;

  for(int i = 0;i<n-1;i++){
    for(int j =0;j<m-1;j++){
      if (verificaSubMatriz(i,j))
        hist[j+1]++;
      else
        hist[j+1] = 0;
    }
    maxi = max(maxi, c2(hist));
  }
  cout<<maxi<<endl;
}