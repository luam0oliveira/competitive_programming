#include <iostream>
#include <vector>

using namespace std;

int get_position(char letter)
{
    if (letter == 'P')
        return 0;
    else if (letter == 'M')
        return 1;
    return 2;
}

int main()
{
    int n, x;

    int sizes[3] = {};

    cin >> n >> x;

    char sequence[n + 1];

    vector<int> muralhas = {x};

    if (scanf("%s", sequence) != 1)
        return 1;

    if (scanf("%d %d %d", &sizes[0], &sizes[1], &sizes[2]) != 3)
    {
        return 1;
    };

    int inicio[] = {0, 0, 0};

    for (int i = 0; i < n; i++)
    {
        int pos = get_position(sequence[i]);
        int tamanho = sizes[get_position(sequence[i])];

        for (int j = inicio[pos]; j < muralhas.size(); j++)
        {

            if (muralhas[j] >= tamanho)
            {
                muralhas[j] -= tamanho;
                break;
            }
            else if (j == muralhas.size() - 1)
            {
                inicio[pos] = j + 1;
                muralhas.push_back(x - tamanho);
                break;
            }
        }
    }

    cout << muralhas.size() << endl;

    return 0;
}