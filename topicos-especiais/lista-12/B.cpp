// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1120
// Encontrar o eulerphi(n) que encontra a quantia de números que são primos relativos a n

#include <bits/stdc++.h>
#define MAX_N 1000000000
#define SIEVE_SIZE 100000

using namespace std;

typedef long long ll;

bitset<SIEVE_SIZE> sieve;
vector<int> primes;

void generateSieve()
{
	sieve.set(0);
	sieve.set(1);

	for (int i = 2; i < SIEVE_SIZE; i++)
	{
		if (sieve[i] == 1)
			continue;
		primes.push_back(i);
		for (int j = 2 * i; j < SIEVE_SIZE; j += i)
		{
			sieve.set(j);
		}
	}
}

vector<int> phi(SIEVE_SIZE);

// From halim
ll EulerPhi(ll N)
{
	ll PF_idx = 0, PF = primes[PF_idx], ans = N;
	while (PF * PF <= N)
	{
		if (N % PF == 0)
			ans -= ans / PF;
		while (N % PF == 0)
			N /= PF;
		PF = primes[++PF_idx];
	}
	if (N != 1)
		ans -= ans / N;
	return ans;
}

int main()
{
	generateSieve();

	int n;
	while (scanf("%d ", &n) != EOF && n != 0)
	{
		printf("%lld\n", EulerPhi(n));
	}
}