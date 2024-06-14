#include <bits/stdc++.h>

using namespace std;
/*
__int64 is a 64-bit integer data type in Visual C++. So the
following code was written in Visual C++.
*/

typedef unsigned long long int datatype;

datatype dp[62][62];


void trib(int n, int back)
{
	datatype sum = 1;
	for (int i = 1; i <= back; i++)
	{
		if (n - i > 0)
			sum += dp[n-i][back];
		else
			sum ++;
	}

	dp[n][back] = sum;
}


int main()
{
	for (int i = 0; i <= 61; i++)
	{
		dp[0][i] = 1;
		dp[1][i] = 1;
		dp[i][0] = 1;
		dp[i][1] = i;
	}

	for (int i = 2; i <= 61; i++)
	{
		for (int j = 2; j <= 61; j++)
		{
			trib(i,j);
		}
	}
	int n, back, cases = 1;
	while (true)
	{
		scanf("%d %d", &n, &back);
		if (n > 60)
			break;

		if (n >= 1 && back >= 1)
		{
			printf("Case %d: %llu\n" ,cases,dp[n][back]);
		}
		else
			printf("Case %d: 1\n" ,cases);
		cases++;
	}
	return 0;
}
