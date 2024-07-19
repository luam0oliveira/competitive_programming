// https://olimpiada.ic.unicamp.br/pratique/p2/2013/f2/troia/
// simulação

#include <bits/stdc++.h>

using namespace std;

int main(){
    int c, n;cin>>c>>n;
    vector<pair<int,int>> fila;
    for(int i=0;i<n;i++){
        int t,d;cin>>t>>d;
        fila.push_back({t,d});
    }
    priority_queue<int> pq;
    for(int i =0;i<c;i++){
        pq.push(0);
    }

    int cont=0;
    for (int i=0;i<n;i++){
        int tempoInicial = fila[i].first, demora = fila[i].second; 
        int menor = pq.top();pq.pop();
        int novo = min(-tempoInicial, menor) - demora;
        if (-tempoInicial-20 > novo+demora)
            cont++;
        pq.push(novo);
    }
    cout<<cont<<endl;
}