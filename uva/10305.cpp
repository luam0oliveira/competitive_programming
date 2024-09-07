// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1246
// Grafos - ordenamento topologico

#include<bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define QUAT(x) x*x;
#define UNVISITED 0
#define EXPLORED -1
using namespace std;

const int maxn = 1e2+1;
int n,m;

vector<int> rel[maxn];
vector<int> order;
bitset<maxn> mark;

void dfs(int u){
    mark.set(u);

    for(int i = 0; i<(int)rel[u].size();i++){
        int v = rel[u][i];
        if (!mark.test(v))
            dfs(v);
    }
    order.push_back(u);
}


int main(){
    while(scanf("%d %d", &n, &m) && !(n==0 && m==0)){
        mark.reset();
        order.clear();
        for(int i=0;i<m;i++){
            int u,v;cin>>u>>v;
            rel[u].push_back(v);
        }
        for(int i =1;i<=n;i++){
            if(!mark.test(i)) dfs(i);
        }
        cout<<order[n-1];
        for(int i = n-2;i>=0;i--){
            cout<<" "<<order[i];
        }
        cout<<endl;
    }
}
