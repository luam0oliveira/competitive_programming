#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define MAXX 2000000

typedef pair<int,int> pi;
typedef pair<double, pi> pdii;
typedef pair<double, int> pdi;

vector<double> distTo;
vector<vector<pdi>> edgeList; // caminhos possiveis entre duas pedras
vector<pi> pos_pedras;

void dijkstra(int s)
{
    priority_queue<pdi, vector<pdi>, greater<pdi>> pq;

    pq.push({0, s});

    distTo[s] = 0;

    while (!pq.empty())
    {
        pdi t = pq.top(); pq.pop();
        double d = t.first; int u = t.second;
        if (d == distTo[u])
        {

            for(auto edge: edgeList[u])
            {
                double cost = edge.first;
                int v = edge.second;
                if (distTo[v] > max(cost, distTo[u]) || distTo[v] == -1)
                {
                    distTo[v] = max(cost, distTo[u]);
                    pq.push({distTo[v], v});
                }
            }
        }
    }

}


int main()
{
    int cases = 1;
    while (true)
    {
        int pedras, x, y;
        cin >> pedras;

        if (!pedras) break;

        edgeList.assign(pedras, vector<pdi>());
        distTo.assign(pedras, -1);
        pos_pedras.assign(pedras, {0,0});


        for (int i = 0; i < pedras; i++)
        {
            cin >> x >> y;

            pos_pedras[i] = {x, y};
        }

        for (int i = 0; i < pedras; i++)
        {
            pi u = pos_pedras[i]; 
            if (i == 1)
                continue;
            for (int j = 1; j < pedras; j++)
            {
                if (i == j)
                    continue;
                pi v = pos_pedras[j];

                double d = sqrt(pow(v.first - u.first, 2) + pow(v.second - u.second, 2));
                edgeList[i].push_back({d, j});
            }
        }

        dijkstra(0);

        cout << "Scenario #" << cases++ <<endl;
        cout << "Frog Distance = " << fixed << setprecision(3) << distTo[1]<<endl<<endl;
    }
}
