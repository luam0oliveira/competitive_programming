// https://br.spoj.com/problems/ENERGIA/
// union-find // (talvez seja possível fazer com DFS/componentes conexas, mas queria reforçar union-find)

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;


vector<vector<int>> conexoes;
bitset<100> visited;

void dfs(int u){
    visited.set(u);
    for(auto con:conexoes[u])
        if (!visited[con])
            dfs(con);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cases=1;
    while(1){
        int n,m;cin>> n>>m;
        if (n== 0 && m==0) break;
        conexoes.assign(n, {});
        visited.reset();
        for(int i =0;i<m;i++){
            int a,b;cin>>a>>b;
            a--;b--;
            conexoes[a].push_back(b);
            conexoes[b].push_back(a);
        }
        int cont = 0;
        for(int i =0;i<n;i++){
            if (!visited[i]){
                cont++;
                dfs(i);
            }
        }
        printf("Teste %d\n", cases++);
        if (cont==1) printf("normal\n\n");
        else printf("falha\n\n");

    }
}
