// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1117
// Uso de modular exponentiation para que o que a exponenciação caiba em inteiros

#include <bits/stdc++.h>
using namespace std;

#define MODULE 131071

long long power(long long a, long long b)
{
	long long result = 1;
	while (b)
	{
		if (b & 1)
			result = (result * a) % MODULE;
		a = (a * a) % MODULE;
		b >>= 1;
	}
	return result;
}

int main()
{
	long long num;
	char a;
	while (cin >> a)
	{
		num = 0;
		string bin = "";
		bin += a;
		while (cin >> a && a != '#')
		{
			bin += a;
		}

		reverse(bin.begin(), bin.end());

		for (int i = 0; i < bin.size(); i++)
		{
			if (bin[i] == '1')
				num = (num + power(2, i)) % MODULE;
		}

		if (num == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}