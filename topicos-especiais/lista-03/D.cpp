#include <iostream>
#include <algorithm>
using namespace std;

int ans[3];

bool isOk(int x,int y, int z,int a,int b,int c)
{
	return x + y + z == a && x*y*z == b && x*x+y*y+z*z == c; 
}


bool solve(int a,int b,int c)
{
	for (int i = min(b, -b); i <= max(b,-b); i++)
	{
	    if (i == 0)
	    {
	        continue;
	    }
		for (int j = min((b/i),-(b/i)); j <= max((b/i),-(b/i)); j++)
		{
		    if (j == 0 || j == i)
		    {
		        continue;
		    }
			for (int k = min(-(b/(i*j)), (b/(i*j))); k <= max(-(b/(i*j)), (b/(i*j))); k++)
			{
			    if (k == 0 || j == k || k == i)
			    {
			        continue;
			    }
			    
				if (isOk(i,j,k,a,b,c))
				{
					ans[0] = i;
					ans[1] = j;
					ans[2] = k;
					return true;
				}
			}	
		}	
	}
	return false;
}

int main()
{
	int n, a, b, c;

	cin >> n;

	while (n --)
	{
		cin >> a >> b >> c;

		if (solve(a,b,c))
			cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
		else
			cout << "No solution.\n";
	}
}
