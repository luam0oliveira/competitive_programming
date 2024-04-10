#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef struct constraint {
	int a, b, d, f;
} Constraint;


bool solve(Constraint regras[], int disp[],int n,int m)
{
	for (int i = 0; i < m; i++)
	{
		int a = regras[i].a, b = regras[i].b, d = regras[i].d, f = regras[i].f;

		int p1 = -1 ,p2 = -1;
		for (int j = 0; j < n; j++)
		{
			if (disp[j] == a)
				p1 = j;

			if (disp[j] == b)
				p2 = j;
		}

		if ((f && (abs(p1 - p2) > d)) || (!f && (abs(p1 - p2) < d)))
		{
			return false;
		}
	}
	return true;
}


int main()
{
	int n, m, cont;

	while (true)
	{
		cin >> n >> m;
		if (n == m && m == 0) return 0;
		int first[n];
		cont = 0;
		Constraint regras[m];
		
		for (int i = 0; i < m; i++)
		{
			Constraint c;
			int d;
			cin >> c.a >> c.b >> d;
			if (d < 0)
			{
				c.f = 0;
				c.d = (-1) * d;
			}
			else
			{
				c.f = 1;
				c.d = d;
			}
			regras[i] = c;
		}

		for (int i = 0; i < n; i++)
			first[i] = i;
			

		do
		{
			if (solve(regras, first, n, m)) cont++;
		}
		while (next_permutation(first, first + n));

		cout << cont << endl;
	}
}
