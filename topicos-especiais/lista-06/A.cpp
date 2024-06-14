#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    int n, value;
    ll sum, maior;

    while (true)
    {
        cin >> n;

        if (n == 0) break;

        sum = 0, maior = 0;

        for(int i = 0; i < n; i++)
        {
            cin >> value;
            if (value + sum > 0)
                sum += value;
            else
            {
                sum = 0;
            }
            maior= max(maior, sum);
        }

        if (sum == 0)
            cout << "Losing streak."<<endl;
        else
            cout << "The maximum winning streak is "<<maior<< "." << endl; 
    }

    return 0;
}
