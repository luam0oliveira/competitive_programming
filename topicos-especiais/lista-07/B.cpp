#include <bits/stdc++.h>

using namespace std;
int cases;

string mapa[1000];
int visited[1000][1000];
pair<int,int> vizinhos[9] = {
	{-1,-1}, {-1,0}, {-1,1},
	{0,-1}, {0,0}, {0,1},
	{1,-1}, {1,0}, {1,1}
};



int dfs(int i, int j, int tamLinha, int tamCol)
{
	int cont = 0;
	if (i <= 0 || i >= tamLinha || j < 0 || j >= tamCol || visited[i][j] == 1)
		return 0;
	cont++;
	visited[i][j] = 1;
	// cout << i << " " << j << endl;
	for (int k = 0; k < 9; k++)
	{
		int x = i + vizinhos[k].first;
		int y = j + vizinhos[k].second;
		if (mapa[x][y] == 'W')
			cont += dfs(x, y, tamLinha, tamCol);

	}
	
	return cont;
}	

int main()
{
    cin >> cases;
	string ent;
	bool first = true;
	getline(cin, ent);
	getline(cin, ent);
	for (;cases > 0;cases--)
	{
		if (! first)
			cout << endl;
		int pos = 1;
		int tamLinha = 0;
		int tamCol = 0;
		while (true){
			getline(cin, ent);
			if (ent[0] != 'W' && ent[0] != 'L')
			{
				break;
			}
			// cout << ent << endl;
			mapa[pos] = ent;
			tamCol = ent.size();
			pos++;
		}
		tamLinha = pos;
		for (int i = 0; i < tamLinha; i++)
			for (int j = 0; j < tamCol; j++)
				visited[i][j] = 0;

		stringstream s(ent);
		int i, j;
		s >> i >> j;
		cout << dfs(i,j-1,tamLinha, tamCol) << endl;
		tamLinha = pos;
		for (int i = 0; i < tamLinha; i++)
			for (int j = 0; j < tamCol; j++)
				visited[i][j] = 0;
		while(true)
		{
			getline(cin, ent);
			if (! isdigit(ent[0]))
				break;
			stringstream s(ent);
			s >> i >> j;

			cout << dfs(i,j-1,tamLinha, tamCol) << endl;
			tamLinha = pos;
			for (int i = 0; i < tamLinha; i++)
				for (int j = 0; j < tamCol; j++)
					visited[i][j] = 0;
		}
		first = false;
	}
    return 0;
}
