#include <bits/stdc++.h>

using namespace std;

// pode ser calculada tbm a partir da raiz de um numero triangular

long long int sequence(long long n)
{
    return (long long int)(sqrt(8 * n + 1) - 1) / 2;
}

int main()
{
    int cases;
    if (scanf("%d", &cases) != 1)
        return 0;
    for (int i = 0; i < cases; i++)
    {
        long long n;

        if (scanf("%lli", &n) != 1)
            return 0;

        long long int lines = sequence(n);
        printf("%lli\n", lines);
    }
}
