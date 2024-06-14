#include <bits/stdc++.h>

using namespace std;

#define MAXX 1000010;

int maxx = 1000010;

vector<vector<int>> nodes;
vector<int> ts;
int visited[1000010];
int recStack[1000010];

int num_nodes, edges;
int pos;


int dfs(int i)
{
	// cout << i << endl;
	visited[i] = true;
	recStack[i] = true;
	if (pos == 0)
		return 0;
	int numN = nodes[i].size();
	for (int k = 0; k < numN; k++)
	{
		if (recStack[nodes[i][k]])
		{
			pos = 0;
			return 0;
		}
		
		if (!visited[nodes[i][k]])
			pos = dfs(nodes[i][k]);
			if (pos == 0)
			{
				// cout << "AHSDUHASUD" << endl;
				return 0;
			}
	}
	recStack[i] = false;
	ts.push_back(i);
	return 1;
}	

int main()
{
	while(true)
	{
		ts.clear();
		pos = 1;
		nodes.clear();
		for (int i = 0; i < maxx; i++)
		{
			visited[i] = 0;
			recStack[i] = 0;
		}

		cin >> num_nodes >> edges;
		
		if (num_nodes == 0 && edges == num_nodes)
			break;
		
		int a, b;
		
		nodes = vector<vector<int>>(num_nodes+1, vector<int>());

		for (int i = 0; i < edges; i++)
		{
			cin >> a >> b;
			nodes[b].push_back(a);
		}

		for (int i = 1; i <= num_nodes; i++)
			// for (int j = 0; j < nodes[i].size();j++)
			// 	cout << nodes[i][j]<<endl;
			if (!visited[i])
				dfs(i);
		
		for (int i = 1; i <= num_nodes; i++)
			if (!visited[i])
				dfs(i);
		
		if (ts.size() != num_nodes)
			cout << "IMPOSSIBLE" << endl;
		else
			for (int i = 0; i < ts.size(); i++)
				cout << ts[i] << endl;

	}

    return 0;
}
