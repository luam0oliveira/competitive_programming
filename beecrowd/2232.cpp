#include <bits/stdc++.h>

using namespace std;

// para este problema nao era necessario criar uma funcao para calcular a
// exponenciacao, porque jah eh implementada pela linguagem, porem o fiz para
//  aprender a binary exponentiation

int poww(int a, int b)
{
    int power = a, sum = 1;

    while (b > 0)
    {
        if ((b & 1) == 1)
            sum *= power;

        power = power * power;
        b >>= 1;
    }
    return sum;

    return 1;
}

int main()
{
    int c, t;

    if (scanf("%d", &c) != 1)
        return 0;

    for (int i = 0; i < c; i++)
    {
        if (scanf("%d", &t) != 1)
            return 0;

        cout << poww(2, t) - 1 << endl;
    }

    return 0;
}
