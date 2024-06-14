#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define MAXX 2000000

typedef pair<int,int> pi;

vector<ll> distTo;
vector<vector<pi>> edgeList;

int main()
{
    int  t, v, e, n, m, c;

    cin >>t;

    while (t--)
    {
        cin >> v >> e;

        edgeList.assign(v, vector<pi>());

        distTo.assign(v, MAXX);

        for (int i = 0; i < e;i++)
        {
            cin >> n >> m >> c;

            edgeList[n].push_back({c, m});
        }

        for (int k = 0; k < v - 1; k++)
        {
            for (int i = 0; i < v; i++)
            {
                for (auto edge: edgeList[i])
                {
                    int v = edge.second;
                    int cost = edge.first;

                    if (distTo[v] > distTo[i] + cost)
                    {
                        distTo[v] = distTo[i] + cost; 
                    }
                }
            }
        }

        bool pos = false;

        for (int i = 0; i < v && !pos; i++)
        {
            for (auto edge: edgeList[i])
            {
                int v = edge.second;
                int cost = edge.first;

                if (distTo[v] > distTo[i] + cost)
                {
                    pos = true;
                    break;
                }
            }
        }

        if (pos)
            cout << "possible" << endl;
        else
            cout << "not possible" << endl;

    }
}
