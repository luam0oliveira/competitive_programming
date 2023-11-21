#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, q;

    while (true)
    {
        if (scanf("%d %d", &n, &q) != 2)
            return 0;

        int notas[n];

        int nota;
        for (int i = 0; i < n; i++)
        {
            if (scanf("%d", &nota) != 1)
                return 0;
            notas[i] = nota;
        }
        sort(notas, notas + n);

        int pesquisa;
        for (int i = 0; i < q; i++)
        {
            if (scanf("%d", &pesquisa) != 1)
                return 0;

            printf("%d\n", notas[n - pesquisa]);
        }
    }

    return 0;
}
