#include <bits/stdc++.h>

using namespace std;

set<int> coins, selected;

int main()
{
    int t, qtd, value, sum;
    cin>> t;
    
    while(t--)
    {
        coins = set<int>(), selected = set<int>();
        cin >> qtd;
        int cont = 1;
        cin >> sum;
        for(int i = 0; i < qtd-1; i++)
        {
            cin >> value;
            coins.insert(value);
        }
        
        for (auto it = coins.begin(); it != coins.end();it++)
        {
            bool ok = true;
            auto itt = it;
            itt++;
            for (;itt!=coins.end();itt++)
            {
                // cout << *it << " " << *itt<<endl;
                if (sum+ *it >= *itt)
                {
                    ok = false;
                    break;
                }
            }
            
            if (ok)
            {
                sum += *it;
                cont++;
            }
        }
        
        cout << cont << endl;
    }
    

    return 0;
}
