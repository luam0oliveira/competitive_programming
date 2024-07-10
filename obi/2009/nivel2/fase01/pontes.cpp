// https://olimpiada.ic.unicamp.br/pratique/p2/2009/f1/pontes/
// Apenas a aplicação de dijkstra

#include <bits/stdc++.h>

using namespace std;

#define MAXX 1000000000

typedef pair<int,int> pii;

vector<int> distTo;
vector<vector<pii>> edgeList; 

bool relax(int u,int v, int cost){
    if (distTo[v] > distTo[u] + cost){
        distTo[v] = distTo[u] + cost;
        return true;
    }
    return false;
}

void dijkstra(int s){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0,s});
    distTo[s] = 0;
    while(!pq.empty()){
        pii top = pq.top();pq.pop();
        int d = top.first,u = top.second;
        if (distTo[u] == d)
            for (auto edge: edgeList[u]) 
                if (relax(u, edge.second, edge.first))
                    pq.push({distTo[edge.second],edge.second});
            
    }
}

int main(){
    int n,m;cin >> n >> m;

    edgeList.assign(n+2, vector<pii>());
    distTo.assign(n+2, MAXX);

    int u,v,c;
    for (int i=0;i<m;i++){
        cin>>u>>v>>c;
        edgeList[v].push_back({c,u});
        edgeList[u].push_back({c,v});
    }

    dijkstra(0);

    cout<<distTo[n+1]<<endl;
}
