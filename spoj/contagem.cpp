// https://br.spoj.com/problems/CONTAGEM/
// ad-rock

#include <bits/stdc++.h>

using namespace std;


// 8 + 4 + 2 + 1 = 15
// 1 + 2 = 3
// 4 + 2 + 1 = 7

int main()
{
	string entrada;
	int cases = 1;
	while (cin >> entrada)
	{
		unsigned long long int soma = 0;
		bool b =  false;
		for (int i = 0; i < entrada.size(); i++)
		{
			if (entrada[i] == 'b')
				soma += (unsigned long long int)(1ULL << (entrada.size() - i-1));

		}

		cout << "Palavra " <<cases<<endl;
		printf("%llu\n", soma);
		

		cout<<endl;
		cases++;
	}

}
