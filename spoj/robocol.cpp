// https://br.spoj.com/problems/ROBOCOL/
// simulacao

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m, s;
	while (cin >> n >> m >> s && n != 0 && m != 0 && s != 0)
	{
		vector<vector<char>> matrix(n, vector<char>(m));

		// 0=cima,1=direita,2=baixo,3=esquerda;
		int posX, posY, dire;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> matrix[i][j];
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (matrix[i][j] == 'S' || matrix[i][j] == 'O' || matrix[i][j] == 'L' || matrix[i][j] == 'N')
				{
					posX = j;
					posY = i;
					if (matrix[i][j] == 'N')
						dire = 0;
					else if (matrix[i][j] == 'L')
						dire = 1;
					else if (matrix[i][j] == 'S')
						dire = 2;
					else
						dire = 3;
					matrix[i][j] = '.';
				}
			}
		}

		string path;
		cin >> path;

		int cont = 0;

		for (int i = 0; i < s; i++)
		{
			if (path[i] == 'F')
			{
				int nx = posX, ny = posY;
				if (dire == 0)
					ny -= 1;
				else if (dire == 1)
					nx += 1;
				else if (dire == 2)
					ny += 1;
				else
					nx -= 1;

				if (nx < 0 || nx >= m || ny < 0 || ny >= n || matrix[ny][nx] == '#') continue;
				
				if (matrix[ny][nx] == '*')
					cont++;
				matrix[ny][nx] = '.';
				posX = nx;
				posY = ny;
			}
			else if (path[i] == 'E')
				dire = (dire + 3) % 4;
			else
				dire = (dire + 1) % 4;
		}
		cout<<cont<<endl;
	}
}