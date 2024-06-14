#include <bits/stdc++.h>

using namespace std;

int num_nodes;

int contPost;
int contGuard;
int pos;

vector<vector<int>> adjs;
vector<bool> g;
vector<bool> marked;

void dfs(int u)
{
	marked[u] = true;
	contPost++;

	for (auto v: adjs[u])
	{
		if (!marked[v])
		{
			g[v] = !g[u];
			if (g[v])
				contGuard++;
			dfs(v);
		}
		else if (g[v] == g[u])
			pos = false;
	}
};


int main()
{

	int cases,e,a,b, total;
	cin >> cases;

	while (cases--)
	{
		cin >> num_nodes >> e;

		adjs = vector<vector<int>>(num_nodes, vector<int>());
		g = vector<bool>(num_nodes, 0);
		marked = vector<bool>(num_nodes, 0);
		pos = true;

		while (e--)
		{
			cin >> a >> b;
			adjs[a].push_back(b);
			adjs[b].push_back(a);
		}
		total = 0;
		for (int i = 0; i < num_nodes; i++)
		{
			contGuard = 0;
			contPost = 0;
			if (!marked[i])
			{
				contGuard = 1;
				g[i] = 1;
				dfs(i);
			}

			if (contGuard > contPost-contGuard && contGuard != contPost)
				total += contPost-contGuard;
			else
				total += contGuard;
		}

		if (pos)
			cout << total << endl;
		else
			cout << -1 << endl;

	}

    return 0;
}
