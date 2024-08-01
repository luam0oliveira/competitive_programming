// https://br.spoj.com/problems/NATUREZA/
// Grafos - contagem de elementos numa componente conexa

#include <bits/stdc++.h>

using namespace std;
int maxprof;
map<string,vector<string>> animais;
map<string,bool> ent;

void dfs(string u, set<string> &k){
    ent[u] = true;
    k.insert(u);
    for(auto it=animais[u].begin();it!=animais[u].end();it++){
        if(!ent[*it])
            dfs(*it, k);
    }
}

int main(){
    bool first = 1;
    while(1){
        int c,r;cin>>c>>r;
        if (c==0 && r==0) break;
        if (!first)
            cout<<endl;
        first = false;
        ent.clear();
        animais.clear();
        string a, b;
        for(int i = 0;i<c;i++){
            cin>>a;
            animais[a] = {};
            ent[a] = false;
        }
        for(int i =0;i<r;i++){
            cin>>a>>b;
            animais[a].push_back(b);
            animais[b].push_back(a);
        }
        maxprof = 1;
        set<string> k;
        for(auto it = ent.begin();it!=ent.end();it++)
        {
            if (!it->second)
                dfs(it->first, k);
            maxprof = max(maxprof, (int) k.size());
            k.clear();
        }

        cout<<maxprof<<endl;
    }
}