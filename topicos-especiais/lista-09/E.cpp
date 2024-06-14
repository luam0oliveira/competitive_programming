#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define MMAX 10000000

typedef pair<int,int> pi;
typedef pair<double, pi> pdii;
typedef pair<double, int> pdi;


vector<vector<int>> maze;
vector<vector<int>> removidos;

int main()
{

    int n;

    cin >> n;

    maze.assign(n, vector<int>(n, 0));
    removidos.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    int cont = 0;
    bool pos = true;
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (maze[i][j] > maze[i][k] + maze[k][j])
                    pos = false;
                else if (maze[i][j] == maze[i][k] + maze[k][j] && i != k && i != j && j != k && !removidos[i][j])
                {
                    removidos[i][j] = 1;
                    cont++;
                }
            }

    if (!pos)
        cout << -1 << endl;
    else   
        cout << cont/2 << endl;
}
