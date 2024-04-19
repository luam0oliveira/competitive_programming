#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll digits(ll number)
{
    ll sum = 0;

    while (number >= 1)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

ll flores[1000005];
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n, k, fi, maior = 0;
    cin >> n >> k;

    for (ll i = 0; i < n; i++)
    {
        cin >> fi;
        flores[fi]++;

        if (fi > maior)
            maior = fi;
    }


    for (ll i = maior; i > 0;i--)
    {
        k -= flores[i];

        ll nn = digits(i);

        flores[i - nn] += flores[i];

        if (k <= 0)
        {
            cout << nn << endl;
            break;
        }
    }

    if (k > 0)
        cout << 0 << endl;

}
