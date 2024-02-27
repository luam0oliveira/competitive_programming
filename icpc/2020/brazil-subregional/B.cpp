#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
    int n, d, l, r, c;

    cin >> n;

    bool grid[11][11], valido = true;

    for (int i = 0; i < 11; i++)
    {
    	for (int j = 0; j < 11; j++)
    	{
    		grid[i][j] = false;
    	}
    }

    while(n--)
    {
    	cin >> d >> l >> r >> c;

    	if (d == 0)
    	{
    		for (int i = c; i <= c+l-1; i++)
    		{
    			if (grid[r][i] || i > 10 || r > 10 || r < 1 || i < 1)
    			{
    				valido = false;
    				continue;
    			}
    				
    			grid[r][i] = true;
    		}
    	}
    	else
    	{
    		for (int i = r; i <= r+l-1; i++)
    		{
    			if (grid[i][c] || i > 10 || c > 10 || c < 1 || i < 1)
    			{
    				valido = false;
    				continue;
    			}

    			grid[i][c] = true;
    		}
    	}
    }
    if (valido)
    	cout << "Y" << endl;
    else
    	cout << "N" << endl;

    return 0;
}
