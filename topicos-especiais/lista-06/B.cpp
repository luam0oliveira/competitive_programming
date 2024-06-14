#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, cases=1;

	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		int alturas[n], larguras[n], dp0[n], dp1[n];

		for(int i = 0; i < n; i++)
			cin >> alturas[i];

		for(int i = 0; i < n; i++)
			cin >> larguras[i];
		
		// para crescimento
		dp0[0] = larguras[0];
		int maiorc = larguras[0];
		int maiord = larguras[0];
		for(int i = 0; i < n;i++)
		{
			dp0[i] = larguras[i];
			dp1[i] = larguras[i];
			for (int j = 0; i > j; j++)
			{
				if (alturas[i] > alturas[j] )
				{
					dp0[i] = max(dp0[i], dp0[j] + larguras[i]);
				}
				else
				if (alturas[i] < alturas[j])
				{
					dp1[i] = max(dp1[i], dp1[j] + larguras[i]);
				}
				maiorc = max(maiorc, dp0[i]);
				maiord = max(maiord, dp1[i]);
			}
		}


		if (maiorc >= maiord)
			cout <<"Case "<<cases<< ". Increasing (" << maiorc<<"). Decreasing ("<<maiord<<")."<<endl;
		else
			cout <<"Case "<<cases<< ". Decreasing (" << maiord<<"). Increasing ("<<maiorc<<")."<<endl;


		cases++;
	}

}
