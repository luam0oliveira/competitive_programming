#include <bits/stdc++.h>

using namespace std;

int num_nodes;

vector<vector<int>> rel;
vector<int> visited;
vector<int> fl;
vector<vector<int>> ans;


void dfs(int i, int x)
{
    if (i == x) return;
    visited[i] = 1;
    
    for (int j = 0; j < num_nodes; j++)
    {
        if (!visited[j] && rel[i][j])
            dfs(j,x);
    }
}

void dd()
{
    for (int j = 0; j < num_nodes;j ++)
    {
        fl[j] = visited[j];
    }
}

void dd1(int i)
{
    for (int j = 0; j < num_nodes; j++)
    {
        ans[i][j] = !(fl[j] && !visited[j]);
    }
}

void linha(int i)
{
    cout << "+";
    
    for (int j = 0;j < i * 2 - 1; j++)
        cout << "-";
    cout << "+"<<endl;
    
}


int main()
{
    int cases, cont = 1, num;
    
    cin >> cases;
    while (cases--)
    {
        cin >> num_nodes;
        
        rel.assign(num_nodes, vector<int>(num_nodes, 0));
        visited.assign(num_nodes, 0);
        ans.assign(num_nodes, vector<int>(num_nodes, 1));
        fl.assign(num_nodes, 0);
        
        for (int i = 0; i < num_nodes;i ++)
        {
            for (int j = 0; j < num_nodes;j ++)
            {
                cin >> rel[i][j];
            }
        }
   
        dfs(0,-1);
        dd();
        
        for (int i = 0; i < num_nodes;i ++)
        {
            visited.assign(num_nodes, 0);
            dfs(0,i);
            dd1(i);
        }
        cout << "Case "<<cont<<":"<<endl;
        linha(num_nodes);
        for (int i = 0; i < num_nodes;i ++)
        {
            cout << "|";
            for (int j = 0; j < num_nodes;j ++)
            {
                if (ans[i][j])
                    cout << "N";
                else
                    cout << "Y";
                cout << "|";
            }
            cout << endl;
            linha(num_nodes);
        }
        
        cont++;
        
    }

    return 0;
}
