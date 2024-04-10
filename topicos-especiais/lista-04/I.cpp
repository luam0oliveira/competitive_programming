#include <bits/stdc++.h>

using namespace std;

double getValue(double irr, vector<int> cf, int t)
{
    double ac = 0;
    
    for (int i = 0; i <= t; i++)
    {
        ac += cf[i]/pow(1+irr, i);
    }
    
    return ac;
}



int main()
{
    while(true)
    {
        vector<int> cfs;
        int t;
        cin >> t;
        
        if (t==0) return 0;
        int a;
        cin >> a;
        cfs.push_back(a);
        for (int i = 0; i < t; i++)
        {
            cin >> a;
            cfs.push_back(a);
        }
        double irr, left = -0.9999999, right = 1000000;
        right = left;
        
        double fa = getValue(left, cfs, t), fb = getValue(right, cfs, t);
        
    
        
        while (fb >0)
        {
            right+=100;
            fb = getValue(right, cfs, t);
        }
    
        bool ok = false;
        double c = (left + right)/2;
        double fc = getValue(c, cfs, t);
        while (fa>fb)
        {
            if (abs(fc) < 0.0001)
            {
                ok = true;
                break;
            }
            
            if (fc > 0)
            {
                left = c;
                fa = getValue(left, cfs, t);
            }
            else
            {
                right = c;
                fb = getValue(right, cfs, t);
            }
            c = (left + right)/2;
            fc = getValue(c, cfs, t);   
        }
        
        if (ok)
            printf("%.2f\n", c);
        else
            printf("No\n");
        
    }
    
    
    return 0;
}
