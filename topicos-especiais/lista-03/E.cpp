#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    int n, t, tracks[21], ans, res, fitas;
    string line;
    while(getline(cin, line))
    {
        stringstream in(line);
        res = 0;
        ans = 0;
        fitas = 0;
        in >> n >> t;
        
        for (int i = 0; i < t; i++)
        {
            in >> tracks[i];
        }
        
        int bmask = 1 << t;
        int sums[bmask] = {};
        
        for (int i = 0; i < bmask; i++)
        {
            int cont = 0;
            for (int j = 0; j < t; j++)
            {
                if (i & (1 << j))
                {
                    sums[i] += tracks[j];
                    cont += 1;
                }
            }
            
            if (sums[i] <= n && ((res <= sums[i] && fitas < cont) || (res < sums[i])))
            {
                res = sums[i];
                ans = i;
                fitas = cont;
            }
        }
        
        for (int i = 0; i < t; i++)
        {
            if (ans & (1 << i))
                cout<<tracks[i]<<" ";
        }
        cout<<"sum:"<<res<<endl;
    }

    return 0;
}
