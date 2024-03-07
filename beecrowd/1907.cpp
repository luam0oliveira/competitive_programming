#include <bits/stdc++.h>
using namespace std;

#define MAX 1030
bool matrix[MAX][MAX], vis[MAX][MAX];
int n, m;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool valid(int x, int y)
{
	if (x >= n || y >=	m || x < 0 || y < 0)
		return false;
	return !matrix[x][y] && ! vis[x][y];
}

void bfs(int x, int y)
{
	deque<pair<int,int>> fila;

	fila.push_back({x,y});

	while (!fila.empty())
	{
		pair<int,int> actual = fila.front();
		fila.pop_front();
		bool ant = vis[actual.first][actual.second];
		matrix[actual.first][actual.second] = true;
		vis[actual.first][actual.second] = true;
		if (!ant)
		{
			for (int i = 0; i < 4; i++)
				if (valid(actual.first + dx[i], actual.second + dy[i]))
				{
					fila.push_back({actual.first + dx[i], actual.second + dy[i]});
				}
			
		}
	}
}

int main()
{
    scanf("%d %d", &n, &m)==0;

    string linha;

    for (int i = 0; i < n; i++)
    {
    	cin >> linha;
    	for (int j = 0; j < m; j++)
    	{
    		vis[i][j] = linha[j] == 'o';
    		matrix[i][j] = linha[j] == 'o';
    	}

    }

    int cont = 0;

	for (int i = 0; i < n; i++)
    	for (int j = 0; j < m; j++)
    		if (!matrix[i][j] && !vis[i][j])
    		{
    			bfs(i, j);
    			cont += 1;
    		}

    printf("%d\n", cont);

    return 0;
}
