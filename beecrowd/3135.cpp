#include <bits/stdc++.h>

using namespace std;

int main()
{
    string n[18][1000];
    int lastposition[18] = {0};

    int names;
    int maior = 0;

    if (scanf("%d", &names) != 1)
        return 0;

    string atual;
    for (int i = 0; i < names; i++)
    {
        cin >> atual;
        int length = atual.size();
        n[length - 2][lastposition[length - 2]] = atual;
        lastposition[length - 2] += 1;
        if (maior < lastposition[length - 2])
        {
            maior = lastposition[length - 2];
        }
    }

    bool first;
    for (int i = 0; i < maior; i++)
    {
        first = true;
        for (int j = 0; j < 18; j++)
        {

            if (n[j][i] != "\0")
            {
                if (first)
                {
                    cout << n[j][i];
                }
                else
                {
                    cout << ", " << n[j][i];
                }

                first = false;
            }
        }
        printf("\n");
    }
    return 0;
}
