#include <iostream>
using namespace std;

int main()
{
    int candidatos;
    cin >> candidatos;

    string deus;
    int maiorPoder, maiorDeuses, maiorMortes;

    cin >> deus >> maiorPoder >> maiorDeuses >> maiorMortes;

    for (int i = 0; i <= candidatos; i++)
    {
        string nome;
        int poder, deuses, mortes;

        cin >> nome >> poder >> deuses >> mortes;

        if ((poder > maiorPoder) || (poder == maiorPoder && deuses > maiorDeuses) || (poder == maiorPoder && deuses == maiorDeuses && mortes < maiorMortes))
        {
            deus = nome;
            maiorPoder = poder;
            maiorDeuses = deuses;
            maiorMortes = mortes;
        }
        else if (poder == maiorPoder && deuses == maiorDeuses && mortes == maiorMortes)
        {
            bool novo = false;
            if (nome.length() <= deus.length())
            {
                for (int j = 0; j < nome.length(); j++)
                {
                    if (nome[j] > deus[j])
                    {
                        break;
                    }
                    else if (nome[j] < deus[j])
                    {
                        novo = true;
                    }
                }
            }
            else
            {
                for (int j = 0; j < deus.length(); j++)
                {
                    if (nome[j] > deus[j])
                    {
                        break;
                    }
                    else if (nome[j] < deus[j])
                    {
                        novo = true;
                    }
                }
            }
            if (novo)
            {
                deus = nome;
                maiorPoder = poder;
                maiorDeuses = deuses;
                maiorMortes = mortes;
            }
        }
    }
    cout << deus << "\n";

    return 0;
}
