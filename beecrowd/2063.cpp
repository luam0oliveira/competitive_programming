#include <iostream>

using namespace std;

int mdc(int a, int b)
{
    int aux;
    while (b != 0)
    {
        aux = b;
        b = a % b;
        a = aux;
    }
    return a;
}

int mmc(int a, int b, int mdc)
{
    return a * (b / mdc);
}

int contVezes(int posicoes[], int pos)
{
    int posAtual = posicoes[pos];
    int timee = 1;
    while (posAtual != pos)
    {
        posAtual = posicoes[posAtual];
        timee += 1;
    }

    return timee;
}

int main()
{

    int numPosicoes;

    cin >> numPosicoes;

    int posicoes[numPosicoes], tempos[numPosicoes];

    int timer;
    int posicao;
    for (int i = 0; i < numPosicoes; i++)
    {
        cin >> posicao;
        posicoes[i] = posicao - 1;
    }

    for (int i = 0; i < numPosicoes; i++)
    {
        tempos[i] = contVezes(posicoes, i);
    }

    timer = tempos[0];
    int maior, menor;

    for (int i = 1; i < numPosicoes; i++)
    {
        maior = max(tempos[i], timer);
        menor = min(tempos[i], timer);
        timer = mmc(maior, menor, mdc(maior, menor));
    }

    cout << timer << endl;

    return 0;
}
