// https://olimpiada.ic.unicamp.br/pratique/p2/2018/f2/wifi/
// Sweep-line / (feito a partir da explicação do video https://www.youtube.com/watch?v=piijfz4n7Zk)

#include <bits/stdc++.h>
using namespace std;

struct event {
  int x, yi, yf, type;
  bool operator < ( const event& o ) const {
    return x < o.x;
  }
};


int main(){
int n;cin >> n;
  vector<event> eventos;
  for( int i = 0; i < n; i++ ){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    eventos.push_back({x1,y2,y1,0});
    eventos.push_back({x2,y2,y1,1});    
  }

  sort(eventos.begin(), eventos.end());

  int res = 0;

  map<int,int> yocupados;

  for ( int i = 0; i < eventos.size(); i++ ){

    if (eventos[i].type == 0){
      yocupados[eventos[i].yi] = 0;
      yocupados[eventos[i].yf] = 1;
    }else{
      if (yocupados[eventos[i].yi] == 0) res++;
      auto it = yocupados.find(eventos[i].yi);
      it--;
      it->second = 1;
      yocupados.erase(eventos[i].yi);      
      yocupados.erase(eventos[i].yf);     
      
    }
    
  }
  
  cout << res << endl;
  
  return 0;
}