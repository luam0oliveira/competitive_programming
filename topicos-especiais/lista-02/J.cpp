#include <iostream>
#include <set>
#include <map>
#include <iomanip>

using namespace std;
int main()
{
    int cases, cont = 1, n, m, a;
    
    cin >> cases;
    while (cases--)
    {
        map<int,set<int>> cards;
        int pessoas[51], unique = 0;
        
        for (int i = 0; i < 51; i++){
            pessoas[i] = 0;
        }
        
        cin >> n;
        
        for( int i = 1; i <= n; i++)
        {
            cin >> m;
            
            for (int j = 1; j <= m; j++)
            {
                cin >> a;
                if (!cards[a].empty())
                    cards[a].insert(i);
                else
                    cards[a].insert(i);
            }
        }
        
        for(map<int,set<int>>::iterator it = cards.begin(); it != cards.end(); it++)
        {
            if (it->second.size() == 1)
            {
                pessoas[*(it->second.begin())] += 1;
                unique += 1;
            }
        }
        cout << fixed << "Case " << cont << ":" ;
        for(int i = 1; i <= n; i++ )
        {
            
            double perc = pessoas[i] * 100.0 / unique;
            cout << " " << setprecision(6) << perc << "%";
        }
        cout << "\n";
        cont ++;
    }

    return 0;
}
