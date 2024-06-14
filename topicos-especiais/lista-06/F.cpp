#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll memo[21][21];

int n;

ll rec(int i, int j)
{   
    // cout << i << j <<endl;
    if (memo[i][j] >= 0)
        return memo[i][j];
    
    
    if (i >= j)
    {
        ll valueI = 0;
        if (i < n)
            for (int k = i + 1; k <= n;k++)
                valueI = max<ll>(valueI, rec(k, 1)+rec(k, j));
        
        
        ll valueJ = 0;
        if ( j > 0)
            for (int k = 1; k < j;k++)
                valueJ = max<ll>(valueJ, rec(i, k) +rec(n, k));
        
        memo[i][j] = valueJ + valueI;
    }
    else
    {
        ll valueJ = 0;
        if ( j > 0)
            for (int k = i; k < j;k++)
                valueJ = max<ll>(valueJ, rec(i, k) + rec(k+1, j));
                
        memo[i][j] = valueJ;
    }
    
    return memo[i][j];
    
}




int main()
{
    int a1;
    while (cin >> n >> a1)
    {
        int nn = n;
        for (int i = 0; i < 22; i++)
            for (int j = 0; j < 22; j++)
                memo[i][j] = -1;


        
        // memset(memo, -1, sizeof memo);
        n = nn;
        memo[n][1] = a1;
        cout << rec(1,n)<<endl;
    }

    return 0;
}
