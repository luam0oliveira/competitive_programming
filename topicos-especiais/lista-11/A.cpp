// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3346
// Para cada ponto ha pontos que podem ter a dist iguais em relacao a origem, quando isso acontecer significa que podese construir triangulos

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef struct point
{
	ll x, y;
} point;

ll vv(ll a)
{
	return a * a;
}

int main()
{
	while (1)
	{
		int p;

		cin >> p;

		if (!p)
			break;

		vector<point> points(p);

		for (int i = 0; i < p; i++)
		{
			cin >> points[i].x >> points[i].y;
		}

		// map<ll, int> dist;
		vector<ll> dd(p);
		ll cont = 0;
		for (int i = 0; i < p; i++)
		{
			// dist.clear();
			for (int j = 0; j < p; j++)
			{
				dd[j] = vv(points[i].x - points[j].x) + vv(points[i].y - points[j].y);
			}

			sort(dd.begin(), dd.end());
			ll iguais = 0;
			for (int j = 1; j < p; j++)
			{
				if (dd[j] == dd[j - 1])
				{
					iguais++;
				}
				else
				{
					cont += iguais * (iguais - 1) / 2;
					iguais = 1;
				}
			}

			cont += iguais * (iguais - 1) / 2;

			// for (auto d: dist)
			//     cont += max(d.second*(d.second-1)/2, 0);
		}

		cout << cont << endl;
	}
}