// https://br.spoj.com/problems/TIROS/
// Ad-rock / Geometria

#include <bits/stdc++.h>

using namespace std;

bool linear(pair<int, int> &ab, pair<int, int> &ac){
    return (ab.first*ac.second - ac.first*ab.second) == 0;
}

pair<int,int> toVec(pair<int, int> &a, pair<int, int> &b){
    return {a.first - b.first, a.second - b.second};
}


int main(){
    int t;scanf("%d ", &t);
    while(t--){
        int n;scanf("%d ", &n);
        vector<pair<int,int>> baloes(n);
        for(int i =0;i<n;i++){
            scanf("%d %d ", &baloes[i].first, &baloes[i].second);
        }
        int maximo = -1;
        for (int i =0;i<n-2;i++)
            for (int j=i+1;j<n-1;j++){
                pair<int,int> ab = toVec(baloes[i], baloes[j]);
                int cont =2;
                for (int k=j+1;k<n;k++){
                    pair<int,int> ac = toVec(baloes[i],baloes[k]);
                    if (linear(ab, ac)) cont++;
                }
                maximo = max(maximo, cont);
            }
        cout<<maximo<<endl;
    }
}