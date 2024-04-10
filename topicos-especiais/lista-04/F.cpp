#include <bits/stdc++.h>

using namespace std;

bool ok(vector<int> distances, int jump)
{
    for(auto it = distances.begin(); it != distances.end(); it++ )
    {
        int distance = *it;
        if (distance == jump)
            jump --;
        else if (distance > jump)
            return false;
    }
    return true;
}


int main()
{
    int n, t,h, ant, cases = 1;
    cin >> t;
    
    while (t--)
    {
        cin >>n;
        
        std::vector<int> distances;
        
        ant = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> h;
            distances.push_back(h - ant);
            ant = h;
        }
        
        int maximo = *max_element(distances.begin(), distances.end());
        
        while (!ok(distances, maximo))
        {
            maximo++;
        }
        
        cout<<"Case "<<cases<<": "<<maximo<<endl;
        
        cases++;
    }   
    
    return 0;
}
