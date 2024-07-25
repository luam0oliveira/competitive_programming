// https://br.spoj.com/problems/FUSOES1/
// Grafos - Union find

#include <bits/stdc++.h>

using namespace std;

vector<int> pai;
vector<int> amm;

int find(int u){
    if (pai[u] == u)
        return u;
    return pai[u] = find(pai[u]);
}

void join(int u, int v){
    int pu = find(u), pv = find(v); 
    if (amm[pu] > amm[pv]){
        amm[pu] += 1;
        pai[pu] = u;
    }else{
        amm[pv] += 1;
        pai[pv] = u;
    }
}



int main(){
    int n,k; cin>>n>>k;
    for(int i =0;i<n;i++){
        pai.push_back(i);
    }
    amm.assign(n, 1);
    // cout<<find(1)<<endl;
    for(int i =0;i<k;i++){
        char op;
        int u,v;cin>>op>>u>>v;
        u--; v--;
        if (op=='F')
            join(u,v);
        else{
            // cout<<u<<v<<endl;
            // cout<<find(v)<<endl;
            if (find(u) == find(v)) cout<<"S"<<endl; else cout<<"N"<<endl;
        }
    }

}