#include <bits/stdc++.h>

using namespace std;


double get(double x, int p,int q,int r,int s,int t,int u)
{
    return p*exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t*x*x + u;
}

int main()
{
    int p,q,r,s,t,u;
    
    while (cin >> p)
    {
        cin >>q>>r>>s>>t>>u;
        double left= 0,right=1;
        
        double x = (left + right)/2;
        double fa = get(left, p,q,r,s,t,u), fb = get(right,p,q,r,s,t,u); 
        double fc = get(x,p,q,r,s,t,u);
        bool ok = false;
        if (fa == 0)
            {
                ok = true;
                x = left;
            }
        if (fb == 0)
            {
                ok = true;
                x = right;
            }
        while ((fa > 0 && fb < 0) || (fa < 0 && fb > 0))
        {
            if (abs(fc) < 0.000000001)
            {
                ok = true;
                break;
            }
            if (fa > 0 && fc < 0)
            {
                right = x;
            }
            else
            {
                left = x;
            }
            fa = get(left, p,q,r,s,t,u), fb = get(right,p,q,r,s,t,u);
            x = (left + right)/2;
            fc = get(x,p,q,r,s,t,u);
        }
        
        if (ok)
            printf("%.4f\n",x);
        else
            printf("No solution\n",x);
            
    }
    return 0;
}
