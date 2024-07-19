// https://olimpiada.ic.unicamp.br/pratique/p2/2014/f2/notas/

#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> notas;

int main(){
    int n,a; cin>>n;
    notas.assign(101, {0,0});
    for(int i =0;i<n;i++){
        cin>>a;notas[a].first++;notas[a].second=a;
    }
    sort(notas.begin(), notas.end());
    cout<<notas[100].second<<endl;
}