#include <iostream>

using namespace std;

int main()
{
    int cartas[5];
    int carta;
    bool c = true, d = true;

    for (int i = 0; i < 5; i++)
    {
        cin >> carta;
        cartas[i] = carta;
    }

    for (int i = 0; i < 4; i++)
    {
        if (cartas[i] < cartas[i + 1])
        {
            d = false;
        }
        if (cartas[i] > cartas[i + 1])
        {
            c = false;
        }
    }

    if (d)
        cout << "D";
    else if (c)
        cout << "C";
    else
        cout << "N";
    cout << endl;

    return 0;
}
