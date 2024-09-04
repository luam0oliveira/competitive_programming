#include<bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define QUAT(x) x*x;
#define UNVISITED -1
#define EXPLORED -2

using namespace std;

const int maxn = 2e5+1;

int colored[maxn];
int v[maxn];
int visited[maxn];

int dfs(int u, int cont){
    visited[u] = EXPLORED;

    if (visited[v[u]] == UNVISITED)
        dfs(v[u], cont + colored[v[u]]);
    
    return visited[u] = max(cont , visited[v[u]]);
}

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i =1;i<=n;i++){
            cin>>v[i];
            visited[i] = UNVISITED;
        }
        string s;cin>>s;
        for(int i = 0;i<n;i++){
            colored[i+1] = s[i] == '0'; 
        }
        
        for(int i = 1;i<=n;i++){
            if (visited[i] == UNVISITED){
                dfs(i, colored[i] == 1);
            }
        }
        cout<<visited[1];
        for(int i = 2;i<=n;i++){
            cout<<" "<<visited[i];
        }
        cout<<endl;
    }
    return 0;
}
