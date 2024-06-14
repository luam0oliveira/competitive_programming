#include <bits/stdc++.h>

using namespace std;

int main()
{
   int v;
   int e;
   int cases = 1;
   string name, name1;
   while (cin >> v)
   {
      map<string,vector<string>> inc;
      map<string,vector<string>> out;
      vector<string> orrr;
      for (int i = 0; i < v; i++)
      {
         cin >> name; 
         inc[name] = {};
         out[name] = {};
         orrr.push_back(name);
      }

      cin >> e;

      for (int i = 0; i < e; i++)
      {
         cin >> name >> name1;
         // recebe 
         inc[name1].push_back(name);
         // envia
         out[name].push_back(name1);
      }

      vector<string> order;
      string fila;

      for (auto it = orrr.begin(); it != orrr.end();it++)
      {
         auto v = *it;

         if (inc[v].size() == 0)
         {
            fila = v;
            inc.erase(v);
            orrr.erase(it);
            break;
         }
      }

      while(!out.empty())
      {
         auto u = fila;
         
         for (int i = 0; i < out[u].size(); i++)
         {
            auto v = out[u][i];
            for (auto it = inc[v].begin(); it != inc[v].end(); it++)
            {  
               if (*(it) == u)
               {
                  inc[v].erase(it);
                  break;
               }
            }
         }

         out.erase(u);
         order.push_back(u);

         for (auto it = orrr.begin(); it != orrr.end();it++)
         {
            auto v = *it;

            if (inc[v].size() == 0)
            {
               fila = v;
               inc.erase(v);
               orrr.erase(it);
               break;
            }
         } 
      }

      cout << "Case #" << cases<<": Dilbert should drink beverages in this order:";
      for (auto it = order.begin(); it != order.end(); it++)
         cout << " " << (*it);
      cout <<"."<< endl << endl;
      cases++;
   }


   return 0;
}
