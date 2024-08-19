// https://br.spoj.com/problems/PARPROX/
// Divisao e conquista - closest pair of points using divide and conquer algorithm
// fonte: https://www.geeksforgeeks.org/closest-pair-of-points-using-divide-and-conquer-algorithm/

#include <bits/stdc++.h>
#define INF 1e14
#define ll long long
#define min(a,b) (a >= b) ? b : a;
using namespace std;


// without square root
ll calcDist(ll a, ll b){
  return a*a + b*b;
}

ll bruteForce(vector<pair<int,int>>& p, int l, int r){
  ll d = INF;
  for(int i = l; i<r;i++){
    for(int j = i+1;j<=r;j++){
      d = min(d, calcDist(p[i].first - p[j].first, p[i].second - p[j].second));
    }
  }
  return d;
}

ll strip(vector<pair<int,int>>& stripP, int n , ll d){
  ll minimo = d;
  sort(stripP.begin(), stripP.end(), [] (auto &p0, auto& p1) {
    return p0.second > p1.second;
  });
  for(int i = 0 ; i < n;i++){
    ll dist;
    for(int j = i+1;j<n && (dist = calcDist(stripP[i].first - stripP[j].first, stripP[i].second - stripP[j].second)) < minimo;j++){
      minimo = min(minimo, dist);
    }
  }


  return minimo;
}


ll divide(vector<pair<int,int>>& pontos, int l, int r){
  if (r - l + 1 <= 5){
    return bruteForce(pontos,l,r);
  }

  int mid = l + (r-l)/2;
  pair<int,int> midPoint = pontos[mid];
  ll dl = divide(pontos, l, mid);
  ll dr = divide(pontos, mid+1, r);
  ll d = min(dl, dr);

  vector<pair<int, int>> stripVec;
  for(int i = l; i <= r;i++){
    if (abs(pontos[i].first - pontos[mid].first) < d) stripVec.push_back(pontos[i]);

  }
  
  return strip(stripVec, stripVec.size(), d);
}


int main(){
  int n;cin>>n;
  vector<pair<int,int>> pontos(n);
  for(int i = 0 ; i < n;i++)
    cin>>pontos[i].first>>pontos[i].second;
  sort(pontos.begin(), pontos.end());
  printf("%.3f\n", sqrt((double)divide(pontos, 0, n-1)));
  return 0;
}