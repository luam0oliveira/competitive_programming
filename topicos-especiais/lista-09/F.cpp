#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define MMAX 10000000

typedef pair<int,int> pi;
typedef pair<double, pi> pdii;
typedef pair<double, int> pdi;


vector<vector<int>> maze;

int main()
{
    int c, n, e, t, ed, a, b, d;

    cin >> c;

    while (c--)
    {
        cin >> n >> e >> t >> ed;

        e--;
        maze.assign(n, vector<int>(n, MMAX));

        for (int i = 0; i < ed; i++)
        {
            cin >> a >> b >> d;
            a--;
            b--;

            maze[a][b] = d;
        }

       for (int i = 0; i < n; i++)
            maze[i][i] = 0;

        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (maze[i][j] > maze[i][k] + maze[k][j])
                        maze[i][j] = maze[i][k] + maze[k][j];

        int cont = 0;

        for (int i = 0; i < n; i++)
            if (maze[i][e] <= t)
                cont++;
                // cout << i << e << maze[i][e]<< endl;

        cout << cont << endl;

        if (c)
            cout << endl;

    }
}
