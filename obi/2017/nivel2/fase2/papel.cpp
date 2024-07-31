// https://olimpiada.ic.unicamp.br/pratique/ps/2017/f2/papel/
// Guloso

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, a;cin>>n;
    vector<int> alturas;
    alturas.push_back(0);
    for(int i =0;i<n;i++){
        int a; cin>>a;
        
        if ( alturas[i] != a)
            alturas.push_back(a);
    }
    alturas.push_back(0);

    int maxx = 0, cont = 0;
    vector<pair<int,int>> especial;


    for (int i = 1;i<alturas.size()-1;i++){
        if (alturas[i-1] < alturas[i] && alturas[i+1] < alturas[i]){
            especial.push_back({alturas[i], -1});
            // cout <<"pico "<<alturas[i]<<endl; 
        }
        else if (alturas[i-1] > alturas[i] && alturas[i+1] > alturas[i]){
            especial.push_back({alturas[i], 1});
            // cout <<"vale "<<alturas[i]<<endl; 
        }
    }

    sort(especial.begin(), especial.end());

    for(auto altura: especial)
        maxx = max(maxx, cont+=altura.second);

    cout<<maxx+2<<endl;
    return 0;
}