#include <bits/stdc++.h>

using namespace std;

map<string, vector<string>> rel;
map<string, bool> mark;
map<string, int> dist;

int bfs (string s, string f)
{
   queue<string> fila;
   fila.push(s);
   dist[s] = 0;
   mark[s] = true;

   while(!fila.empty())
   {
      string u = fila.front(); fila.pop();
      if (u == f)
         return dist[u];
      for (int i = 0; i < rel[u].size(); i++)
      {
         string v = rel[u][i];

         if (!mark[v])
         {
            dist[v] = dist[u] + 1;
            mark[v] = true;
            fila.push(v);
         }
      }
   }
   return 0;
}

bool diff (string a, string b)
{
    int diffen=0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            diffen++;
        
        if (diffen > 1)
            return false;
    }
    return true;
}

int main()
{
    int tests;
    string inp;
    
    getline(cin, inp);
    
    stringstream in(inp);
    in >> tests;
    
      map<int,vector<string>> dic; 
    while (tests--)
    {
      dic.clear();
      mark.clear();
      dist.clear();
        string palavra, p2;
        while (true)
        {
            getline(cin, inp);
            stringstream in(inp);
            in >> palavra;
            
            if (palavra == "*")
                break;
                
            dic[palavra.size()].push_back(palavra);
        }
        
        
        rel.clear();
        
        for (auto it = dic.begin(); it != dic.end() ; it++)
        {
            vector<string> palavras = it->second;
            
            for(int i = 0; i < palavras.size(); i++)
            {
                for (int j = 0; j < palavras.size(); j++)
                {
                    if (j == i)
                        continue;
                    
                    if (diff(palavras[i], palavras[j]))
                    {
                        rel[palavras[i]].push_back(palavras[j]);
                        rel[palavras[j]].push_back(palavras[i]);
                    }
                }
            }
        }
        
        while (getline(cin, inp) && inp != "")
        {
            stringstream in(inp);
            in >> palavra;
            
            if (inp.size() == 0)
                break;
            in >> p2;

            cout << palavra << " " << p2 << " " << bfs(palavra, p2) << endl;
            mark.clear();
        }
        if (tests != 0) cout << endl;

    return 0;
}
