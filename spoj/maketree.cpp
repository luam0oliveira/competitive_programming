// https://www.youtube.com/watch?v=Rmi_2e6gt5M
// tive de usar o video para completar o exercicio

#include<bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define QUAT(x) x*x;
#define UNVISITED 0
#define EXPLORED -2

using namespace std;

const int maxn = 1e5+1;

int pai[maxn];
vector<int>filhos[maxn];
vector<int> topol;

void tp(int u, int f){
    pai[u] = f;
    for(int i=0;i<(int)filhos[u].size();i++){
        if (pai[filhos[u][i]] == UNVISITED)
            tp(filhos[u][i], u);
    }

    topol.push_back(u);
}

int main(){
    int n, k; cin>>n>>k;
    
    for(int z = 1;z<=k;z++){
        int t;cin>>t;
        for(int i = 0;i<t;i++){
            int x;cin>>x;
            filhos[z].push_back(x);
        }
    }
    
    for(int i = 1;i<=n;i++){
        if (pai[i] == UNVISITED){
            tp(i, -1);
        }
    }

    int boss = 0;
    for(int i = topol.size() - 1;i>=0;i--){
        pai[topol[i]] = boss;
        boss = topol[i];
    }

    for(int i =1;i<=n;i++){
        cout<<pai[i]<<endl;
    }
}
