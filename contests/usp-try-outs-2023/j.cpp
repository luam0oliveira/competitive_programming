// NAO TERMINADA
// https://codeforces.com/gym/104505/problem/J
// Grafos

#include<bits/stdc++.h>
#define ll long long
#define QUAT(x) x*x;
using namespace std;

int n, m;

struct edge {
    int v, id;
};

vector<int> usada;
vector<int> sol;
vector<vector<edge>> rel;
vector<int> mark;
vector<int> estados;


int dfs(int u){
    mark[u] = true;
    int sum = 0;

    // cout<<"u = "<<u<<endl;
    // cout<<estados[u]<<endl;
    for(int i = 0;i<(int)rel[u].size();i++){
        if (!usada[rel[u][i].id] && estados[u]){
            sol.push_back(rel[u][i].id);
            estados[u] = 0;
            // cout<<estados[rel[u][i].v]<<" = v "<<rel[u][i].v<<endl;
            estados[rel[u][i].v] = (estados[rel[u][i].v] == 0);
            usada[rel[u][i].id] = 1;
            sum += dfs(rel[u][i].v);
            usada[rel[u][i].id] = 0;
        }
    }
    return sum+=estados[u];
}

int possivel(int u){
    mark[u] = true;
    int sum = estados[u];
    for(int i = 0;i<(int)rel[u].size();i++){
        if (!mark[rel[u][i].v]){
            sum += possivel(rel[u][i].v);
        }
    }
    return sum;
}


int main(){
    cin>>n>>m;
    mark.assign(m,0);
    rel.assign(m, {});
    estados.assign(m,0);
    usada.assign(n, 0);
    
    for(int i = 0;i<n;i++){
        int u,v;cin>>u>>v;
        u--;v--;
        rel[u].push_back({v,i});
        rel[v].push_back({u,i});
    }


    int pos = true;
    for(int i = 0;i<m;i++){
    
        cin>>estados[i];
    }


    for(int i =0;i<m && pos;i++){
        if (!mark[i]){
            pos = possivel(i) % 2 == 0;
        }
    }

    mark.assign(m,0);

    if (pos){
        for(int i =0;i<m && pos;i++){
        if (!mark[i] && estados[i])
            dfs(i);
        }
       
        cout<<sol.size()<<endl;
        sort(sol.begin(), sol.end());
        if (sol.size()){
            cout<<sol[0]+1;
            for(int i =1;i<(int)sol.size();i++)
                if (sol[i-1] != sol[i])
                    cout<<" "<<sol[i]+1;
            cout<<endl;

        }
    }
    else cout<<-1<<endl;

}