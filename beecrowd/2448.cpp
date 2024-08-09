#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;cin>>n>>m;
    map<int, int> casas;
    vector<int>cartas;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        casas[a] = i;
    }
    for(int i =0;i<m;i++){
        int a;cin>>a;
        cartas.push_back(a);
    }
    int cont = casas[cartas[0]];
    for(int i =0;i<m-1;i++){
        cont+= abs(max(casas[cartas[i]],casas[cartas[i+1]]) - min(casas[cartas[i]],casas[cartas[i+1]]));
    } 
    cout<<cont<<endl;
}