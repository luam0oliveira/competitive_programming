// https://br.spoj.com/problems/TENTA/
// ad-rock

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    while(1)
    {
        int n; scanf("%d", &n);        
        if (!n) break;
        
        vector<ll> valores(n);

        for(int i = 0; i < n;i++)
            scanf("%lld ", &valores[i]);
        
        sort(valores.begin(), valores.end());
        
        do{
            printf("%lld", valores[0]);
            for (int i = 1; i < n;i++)
            {
                printf(" %lld", valores[i]);
            }
            printf("\n");
            
        }
        while (next_permutation(valores.begin(), valores.end()));
        printf("\n");
    }
}
