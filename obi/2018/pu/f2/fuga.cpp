// https://olimpiada.ic.unicamp.br/pratique/p2/2018/f2/fuga/
// Backtracking

#include <bits/stdc++.h>
using namespace std;

const int MAXN =  11;

int matriz[MAXN][MAXN], visitados[MAXN][MAXN], mark[MAXN][MAXN];

int n, m;
int maximo = 0;

pair<int, int> vizinho[] = {
  {1,0},
  {-1,0},
  {0,1},
  {0,-1},
};

int possivel(int x, int y){
  return  !(x < 0 || y < 0 || x >= n || y >= m || matriz[x][y]);
}

void solve(int& x, int& y, int& xf, int& yf, int passo){

  if (x == xf && y == yf){
    maximo = max(maximo, passo);
    // cout<<passo<<endl;
    return;
  }

  for(int i = 0 ; i < 4;i++){
    int nx = x+vizinho[i].first;
    int ny = y+vizinho[i].second;
    if(possivel(nx, ny)){
      matriz[nx][ny] = 1;
      solve(nx,ny, xf, yf, passo+1);
      matriz[nx][ny] = 0;
    }
  }  
}




int main(){
  cin>>n>>m;
  for(int i = 1 ; i<n;i+=2)
    for(int j = 1 ; j<m;j+=2)
        matriz[i][j] = 1;
  
  int xi,xf,yi,yf;cin>>xi>>yi>>xf>>yf;
  xi--;yi--;xf--;yf--;
  matriz[xi][yi] = 1;
  solve(xi,yi, xf,yf,1);
  cout<<maximo<<endl;
}