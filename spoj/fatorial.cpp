// https://br.spoj.com/problems/FATORIAL/
// matematica

#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> f(1000001);
    long long current = 1;
    
    for (int i = 1; i <= 1000000;i++)
    {
        current *= i;
        
        while (current % 10 == 0)
            current /=10;
        
        f[i] = current%10;
        current %= (int)10e6;
    }
    int n, cases = 1;
    while (scanf("%d ", &n) != EOF)
    {
        printf("Instancia %d\n%d\n\n", cases++, f[n]);
    }
}
