#include <bits/stdc++.h>

using namespace std;

int main()
{
    while (true)
    {
        int a, d;

        cin >> a >> d;

        if (a == 0 && d == 0)
        {
            return 0;
        }

        int ataq[a], defe[d];
        int pos;
        for (int i = 0; i < a; i++)
        {
            cin >> pos;
            ataq[i] = pos;
        }

        for (int i = 0; i < d; i++)
        {
            cin >> pos;
            defe[i] = pos;
        }
        sort(ataq, ataq + a);
        sort(defe, defe + d);

        bool impedido = false;
        if (defe[1] > ataq[0])
        {
            impedido = true;
        }

        if (impedido)
        {
            cout << "Y" << endl;
        }
        else
        {
            cout << "N" << endl;
        }
    }
}
