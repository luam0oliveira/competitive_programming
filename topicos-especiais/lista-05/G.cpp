#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, zzz;
    while (true)
    {
        cin >> n;
        if (n == 0) break;
        std::vector<int> seq = vector<int>();
        zzz = 1;
        for (int i = 0; i < n;i++)
        {
            cin >> a;
            if (a != 0)
            {
                seq.push_back(a);
                zzz = 0;
            }
        }
        
        if (zzz)
            cout << 0 << endl;
        else
        {
            cout << seq[0];
            for (int i = 1; i < seq.size();i++)
            {
                cout <<" "<< seq[i]; 
            }
            cout << endl;
        }
    }
    return 0;
}
