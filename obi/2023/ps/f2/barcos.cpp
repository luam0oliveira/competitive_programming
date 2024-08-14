// https://olimpiada.ic.unicamp.br/static/extras/obi2023/provas/ProvaOBI2023_f2ps.pdf
// A ideia era fazer uma MST para diminuir os caminhos e deixar somente os cami
// nhos otimos, e entao fazer uma busca e pegar o minimo. Eh necessario alguma
// otimizacao ou a forma de resolver esta errada.
// UPD 01: Precisava saber como resolver, entao vi a solucao no site da bot, ta
// nto que boa parte da solucao eh uma copia da do site.

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9 + 10;
const int MAXN = 100100;
const int MAXLOG = 21;

vector<int> pai;
vector<int> altura;
vector<int> parent;
vector<int> depth;
vector<int> parent_cap;
int dp[MAXN][MAXLOG], dpmin[MAXN][MAXLOG]; // vertice
int dp_cap[MAXLOG][MAXN];                  // capacidade minima no caminho
vector<vector<pair<int, int>>> adjList;

int find(int u){
  if (pai[u] != u)
    pai[u] = find(pai[u]);
  return pai[u];
}

bool join(int u, int v){
  u = find(u);
  v = find(v);
  if (u == v)
    return false;

  if (altura[u] < altura[v])
    pai[u] = v;
  else{
    pai[v] = u;
    if (altura[v] == altura[u])
      altura[u]++;
  }
  return true;
}

// Tentativa anterior
int findLCA(int u, int v)
{
  while (depth[u] != depth[v]){
    if (depth[u] > depth[v])
      u = parent[u];
    else
      v = parent[v];
  }
  while (u != v){
    u = parent[u];
    v = parent[v];
  }
  return u;
}

void dfs(int v, int p, int peso, int fg)
{
  depth[v] = depth[p] + 1;
  dp[v][0] = p;
  dpmin[v][0] = peso;
  cout<<v <<" "<<p<<endl;
  for (int k = 1; k < MAXLOG; k++){
    dp[v][k] = dp[dp[v][k - 1]][k - 1];
    dpmin[v][k] = min(dpmin[v][k - 1], dpmin[dp[v][k - 1]][k - 1]);
  }

  for (auto [viz, vizP] : adjList[v])
    if (viz != p)
      dfs(viz, v, vizP, 0);
}

int calcPath(int x, int y){
  // Deixar assim para que o de maior profundidade chegue na prof daquele de me
  // nor
  if (depth[x] < depth[y])
    swap(x, y);
  int jump = depth[x] - depth[y], resp = INF;
  for (int k = 0; k < MAXLOG; k++)
    if (jump & (1 << k))
    {
      resp = min(resp, dpmin[x][k]);
      x = dp[x][k];
    }
  if (x == y)
    return resp;

  // Caso nao esteja no mesmo ramo
  for (int k = MAXLOG - 1; k >= 0; k--)
  // acontece ate que chegam nos mais proximos do root
    if (dp[x][k] != dp[y][k]) {
      resp = min({resp, dpmin[x][k], dpmin[y][k]});
      x = dp[x][k], y = dp[y][k];
      cout<<x<< " "<<y<<endl;
    }

  // tira o minimo entre os minimos ate os nos mais proximos e o minimo entre o
  // no e o root
  return min({resp, dpmin[x][0], dpmin[y][0]});
}

int main()
{
  int n, m;
  cin >> n >> m;
  adjList.assign(n + 1, {});
  altura.assign(n + 1, 0);
  parent.assign(n + 1, 0);
  depth.assign(n + 1, 0);
  parent_cap.assign(n + 1, INF);

  for (int i = 0; i < n; i++)
    pai.push_back(i);

  priority_queue<pair<int, pair<int, int>>> pq;
  for (int i = 0; i < m; i++){
    int u, v, c;
    cin >> u >> v >> c;
    pq.push({c, {u, v}});
  }
  int con = 0;

  while (!pq.empty() && con != n - 1){
    auto top = pq.top();
    pq.pop();
    int c = top.first;
    int u = top.second.first;
    int v = top.second.second;
    if (join(u, v)){
      adjList[u].push_back({v, c});
      adjList[v].push_back({u, c});
      con++;
    }
  }

  dfs(2, 2, INF, 0);
  for (int  i =1 ;i<=n;i++){
    for (int j =0 ;j<MAXLOG;j++)
      cout<<dp[i][j]<<" ";
    cout<<endl;
  }

  int q; cin >> q;

  for (int i = 0; i < q; i++)
  {
    int u, v;
    cin >> u >> v;
    cout << calcPath(u, v) << endl;
  }
}