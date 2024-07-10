// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=761
// Apenas a aplicação de Edmonds-Karp (max flow)

#include <bits/stdc++.h>

#define INF 1000000

using namespace std;

typedef pair<int,int> pi;

vector<vector<int>> adjMatrix;
vector<set<int>> adjList;
vector<int> p;
int n;

bool hashMaximizingPath(int s, int t)
{
	vector<bool> mark (10, false);
	queue<int> q;
	p.assign(n, -1);
	q.push(s);
	mark[s] = true;
	p[s] = s;
	
	
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		
		for (int v: adjList[u])
		{
				
			if (!mark[v] && adjMatrix[u][v] > 0){
				p[v] = u;
				q.push(v);
				mark[v] = true;
			}
		}
		if (mark[t])
			break;
			
	}
	return mark[t];
}

int edmondskarp(int s, int t){
	int mf=0;
	
	
	while (hashMaximizingPath(s,t))
	{
		// cout <<"AHSUDHAS"<<endl;
		int heat = INF;
		
		for (int v = t; v != s; v = p[v])
			heat = min(heat, adjMatrix[p[v]][v]);

		
		for (int v = t; v != s; v = p[v])
		{
			adjMatrix[v][p[v]] += heat;
			adjMatrix[p[v]][v] -= heat;
		}
		
		mf+=heat;
	
	}
	
	return mf;
}



int main(){
	int cases = 0;
	
	while (1)
	{	
		cin >> n;	
		if (!n) return 0;
		
		int s,t,con, c,u,v;cin >> s >> t >> con;
		
		adjMatrix = vector<vector<int>>(n, vector<int>(n));
		adjList = vector<set<int>>(n);
		
		while (con--)
		{
			cin >> u >> v >> c;
			
			u--;
			v--;
			
			adjMatrix[u][v] += c;
			adjMatrix[v][u] += c;
			adjList[u].insert(v);
			adjList[v].insert(u);
		}
		s--;
		t--;		
		cout << "Network "<<++cases<<endl<<"The bandwidth is "<<edmondskarp(s,t)<<"."<<endl<<endl;        
	}
}
