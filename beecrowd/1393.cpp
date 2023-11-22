#include <bits/stdc++.h>

using namespace std;

int sequence(int n, int memo[])
{
    if (n == 1 or n == 2)
    {
        memo[n - 1] = n;
        return n;
    }
    else if (memo[n - 1] != 0)
    {
        return memo[n - 1];
    }

    memo[n - 1] = sequence(n - 1, memo) + sequence(n - 2, memo);

    return memo[n - 1];
}

int main()
{
    int memo[40];

    for (int i = 0; i < 40; i++)
    {
        memo[i] = 0;
    }

    while (true)
    {
        int n;

        if (scanf("%d", &n) != 1)
            return 0;
        if (n == 0)
        {
            return 0;
        }

        int value = sequence(n, memo);

        printf("%d\n", value);
    }
}
