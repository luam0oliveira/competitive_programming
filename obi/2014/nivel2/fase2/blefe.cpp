// https://olimpiada.ic.unicamp.br/pratique/p2/2013/f2/troia/
// componentes conexos

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0) , cout.tie(0);
    int n, m, a;cin>>n>>m;
    unordered_set<int> conjuntoA;

    for(int i =0;i<n;i++){
        cin >>a;
        conjuntoA.insert(a);
    }
    bool certo = true;
    vector<int>sq;
    unordered_set<int> um;
    for(int i =0;i<m && certo;i++){
        cin>>a;

        certo = conjuntoA.find(a) != conjuntoA.end();
        for(int j=0;j<i;j++){
            um.insert(a-sq[j]);
        }

        auto fim = um.end();
        if (!certo){
            for(int j=0;j<i &&!certo;j++)
                if (um.find(sq[j])!=fim) certo = true;
        }

        sq.push_back(a);
    }
    if (certo) cout<<"sim";
    else cout<<a;
}