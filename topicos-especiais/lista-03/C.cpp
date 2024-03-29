#include <iostream>
#include <algorithm>
using namespace std;

int n, p, bars[21];

int main()
{
	int t;

	cin >> t;
	int resolvido;

	while (t --)
	{
		cin >> n;

		cin >> p;

		resolvido = false;
		
		for (int i = 0; i < p; i++)
		{
			cin >> bars[i];
		}

		int maximum = 1 << p;

		for (int i = 0; i < maximum && !resolvido; i++)
		{
			int sum = 0;
			
			for (int j = 0; j < p; j++)
			{
				if (i & (1 << j))
				{
					sum += bars[j];
				}
			}
			if (sum == n)
				resolvido = 1;
		}
		
		if (resolvido)
			cout << "YES" << endl;	
		else
			cout << "NO" << endl;
	}
}
