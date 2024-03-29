#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    while (true)
    {
        string str;
        
        cin >> str;
        
        if (str == "#")
            return 0;
        
        char pl[str.size()+1], ord[str.size()+1];
        
        for(int i = 0; i < str.size(); i ++)
        {
            pl[i] = str[i];
            ord[i] = str[i];
        }
        sort(ord, ord + str.size());
        next_permutation(pl, pl + str.size());
        
        int l = str.size();
        
        
        bool igual = true;
        for (int i = 0; i < l; i++)
        {
            if (ord[i] != pl[i])
            {
                igual = false;
                break;
            }
        }
        
        if (igual)
            cout << "No Successor\n";
        else
        {
            for(int i = 0; i < l; i ++)
            {
                cout << pl[i];
            }
            
            cout << "\n";
        }
        
    }
    
    return 0;
}
