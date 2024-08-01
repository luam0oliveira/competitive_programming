// https://br.spoj.com/problems/ONZE/
// ad-rock (saber regra de divisão por 11)

#include <bits/stdc++.h>

// 11 22 33 
// 110 121 132
// 209 220 231
// 308 319 330
// 1100 1111 1121
// 112233 
// 2937
// 112234
// 5038297

using namespace std;

int main()
{
	string num;

	while (cin >> num && num != "0")
	{
		cout << num << " ";
		if (num.size() == 1 || (num.size() == 2 && num[0] != num[1]))
			cout << "is not a multiple of 11." <<endl;
		else
		{
			int soma = 0;
			for (int i = num.size()-1; i >= 0; i-=2)
			{
				soma += (i-1 >= 0 ? (num[i-1] - '0') : 0)*10 + num[i] - '0';
			}

			if (soma % 11 == 0)
				cout << "is a multiple of 11." <<endl;
			else
				cout << "is not a multiple of 11." <<endl;
		}

	}
}