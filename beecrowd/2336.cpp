#include <bits/stdc++.h>
using namespace std;

const int MODULO = 1000000007;

int exp_mod(long long a, unsigned b)
{
    int res = 1;

    if (a == 0) return 0;

    while (b > 0)
    {
        if (b & 1)
            res = (res*a) % MODULO;

        b>>=1;
        a = (a*a) % MODULO;
    }

    return res;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a;
    while(cin >> a)
    {
        int  letra, to_add, tam_string = a.size();
        long int b = 0;

        for(int i = 0; i < tam_string; i++)
        {
            to_add = exp_mod(26, tam_string - 1 - i);
            letra = a[i] - 'A';

            b = (((((long)to_add * letra) % MODULO) + b) % MODULO);
        }

        cout << b << "\n";        
    }

    return 0;
}