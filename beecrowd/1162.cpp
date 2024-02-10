#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int cases,l,v,cont;
    int vagoes[50];
    scanf("%d", &cases);

    for (int casee = 0; casee < cases; casee++)
    {
        scanf("%d", &l);
        cont = 0;

        for (int i = 0; i < l ; i++ )
        {   
            scanf("%d", &v);

            vagoes[i] = v;
        }

        for (int i = 0; i < l ; i++ )
        {
            for (int j = i+1; j < l ; j++ )
            {
                if (vagoes[i] > vagoes[j]){
                    cont += 1;
                }
            }
        }

        printf("Optimal train swapping takes %d swaps.\n",cont);
    }
    return 0;
}