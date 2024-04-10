#include <bits/stdc++.h>

using namespace std;

int main()
{
    string enc, search;
    int num_search;
    
    cin >> enc;
    
    map<char,vector<int>> pos;
    map<char,int> verificados;
    
    for(int i = 0; i < enc.size();i++)
    {
        pos[enc[i]].push_back(i);
    }
    
    
    cin >> num_search;
    
    for (int i = 0; i < num_search; i++)
    {
        cin>>search;
        bool ok = true;
        int left = -1;
        int first = 1000000000, right = -1;
        for (int j = 0; j < search.size() && ok;j++)
        {
            if (pos.find(search[j]) == pos.end())
            {
                ok = false;
            }
            bool encontrado = false;
            for (int k = 0; k < pos[search[j]].size(); k++)
            {
                if (pos[search[j]][k] > left)
                {
                    if (first > pos[search[j]][k])
                    {
                        first = pos[search[j]][k];
                    }
                    if (right < pos[search[j]][k])
                    {
                        right = pos[search[j]][k];
                    }
                    left = pos[search[j]][k];
                    encontrado = true;
                    break;
                }
            }
            
            if (!encontrado)
                ok = false;
        }
        
        if (ok)
            cout << "Matched "<<first <<" "<<right<<endl;
        else
            cout <<"Not matched"<<endl;
        
    }

    return 0;
}
