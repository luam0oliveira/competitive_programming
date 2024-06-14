#include <bits/stdc++.h>

using namespace std;

set<int> possibilidades;
vector<vector<int>> arr;
vector<int> mark;
vector<int> prof;

int main()
{
    int cases = 1;
    
    int inicio, fim, quant, a;
    
    while (true)
    {
        possibilidades.clear();
        arr.assign(10000, vector<int>());
        mark.assign(10000, 0);
        prof.assign(10000, -1);
        
        vector<int> aumentos;
        cin >> inicio >> fim >> quant;
        if (inicio == fim && quant == fim && quant == 0) break;
        while (quant--)
        {
            cin >> a;
            arr[inicio].push_back(a);
            aumentos.push_back(a);
            possibilidades.insert(a);
        }
        
        
        queue<int> fila;
        int s = inicio;
        fila.push(s);
        prof[s] = 0;
        mark[s] = 1;
        while (!fila.empty())
        {
            int atual = fila.front(); fila.pop();
            // cout << atual << endl;
            
            for(auto aumento: aumentos)
            {
                int v = (atual + aumento) % 10000;
                if (mark[v] == 0)
                {
                    mark[v] = 1;
                    prof[v] = prof[atual] + 1;
                    fila.push(v);
                }
            }
            
        }

        cout << "Case "<<cases<<": ";
        if (prof[fim] != -1)
            cout << prof[fim] <<endl;
        else
            cout << "Permanently Locked"<<endl;
        
        cases++;
    }
    
    return 0;
}
