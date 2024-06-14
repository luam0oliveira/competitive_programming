#include <bits/stdc++.h>

using namespace std;

#define ii pair<int,int>
#define dd pair<double,double>


vector<pair<double,double>> v;
vector<int> alt;
vector<int> pai;
vector< pair<double, ii> > EdgeList;


int find(int u)
{
    if (pai[u] == u)
        return u;
    int v = pai[u];
    return pai[u] = find(v);
}


bool join(int u, int v)
{
    if (find(u) == find(v))
        return false;

    if (alt[u] > alt[v])
    {
        pai[v] = u;
    }
    else
    {
        pai[u] = v;
        if (alt[u] == alt[v])
            alt[v] = alt[u] + 1;
    }
    return true;
}



int main()
{

    int cases, quant, arestas;
    double x, y, custo;

    cin >> cases;

    while(cases--)
    {
        custo = 0;
        cin >> quant;
        
        alt.assign(quant, 0);
        pai.clear();
        v.clear();
        EdgeList.clear();
        for (int i = 0; i < quant; i++)
        {
            pai.push_back(i);
        }
        for (int i = 0; i < quant; i++)
        {
            cin >> x >> y;

            v.push_back({x, y});
        }


        for (int i = 0; i < quant; i++)
        {
            for (int j = i + 1; j < quant; j++)
            {
                double dist = sqrt(pow(v[i].first - v[j].first, 2) + pow(v[i].second - v[j].second, 2));
                EdgeList.push_back({dist, {i, j}});
            }
        }

        sort(EdgeList.begin(), EdgeList.end());

        arestas = 0;

        for (int i = 0; arestas != quant - 1; i++)
        {
            int u = find(EdgeList[i].second.first);
            int v = find(EdgeList[i].second.second);
            if (join(u,v))
            {
                custo += EdgeList[i].first;
                arestas++;
            }
        }

        cout << fixed<<setprecision(2) << custo << endl;

        if (cases)
            cout<<endl;

    }

    
}
