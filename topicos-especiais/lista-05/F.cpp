#include <bits/stdc++.h>

using namespace std;


int digits(int number)
{
    int sum = 0;

    while (number > 0)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int main()
{
    int b,s, a, cases = 1;
    int menor;
    while (true)
    {
        cin >> b >> s;
        menor = INT_MAX;

        if (b == s && s == 0) break;

        for (int i = 0 ; i < b;i++)
        {
            cin >> a;
            menor = min(menor,a);
        }

        for (int i = 0 ; i < s;i++)
        {
            cin >> a;
        }

        if (b > s)
        {
            cout << "Case " <<cases<<": "<<b-s << " "<<menor<<endl;
        }
        else
        {
            cout <<"Case " <<cases<<": 0"<<endl;
        }
        cases++;
    }
}
