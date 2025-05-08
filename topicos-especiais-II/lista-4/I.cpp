#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
  int n,m;cin>>n>>m;
  double aa = 0, bb= 0;
  for(int i=0;i<n;i++) {
    double a;cin>>a;
    aa+=(a+1)/2;
  }
  for(int i=0;i<m;i++) {
    double a;cin>>a;
    bb+=(a+1)/2;
  }


  if (aa == bb) cout <<"TIED\n";
  else if (aa > bb) cout <<"ALICE\n";
  else cout <<"BOB\n";
}