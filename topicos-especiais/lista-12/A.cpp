// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1335
// Uso de sieve of eratothenes 

#include <bits/stdc++.h>

#define SIEVE_SIZE 20000010
#define TWIN_PRIME 100000

using namespace std;

bitset<SIEVE_SIZE> sieve;

vector<pair<int, int>> twin_primes(TWIN_PRIME);

void generateSieve()
{
	sieve.set(0);
	sieve.set(1);
	int cont = 0;

	for (int i = 2; i < SIEVE_SIZE && cont < TWIN_PRIME; i++)
	{
		if (sieve[i] == 1)
			continue;

		for (int j = 2 * i; j < SIEVE_SIZE; j += i)
		{
			sieve.set(j);
		}

		if (sieve[i] == 0 && sieve[i + 2] == 0)
			twin_primes[cont++] = {i, i + 2};
	}
}

int main()
{
	generateSieve();
	int n;
	while (scanf("%d ", &n) != EOF)
	{
		printf("(%d, %d)\n", twin_primes[n - 1].first, twin_primes[n - 1].second);
	}
	return 0;
}