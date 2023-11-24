#include <bits/stdc++.h>

using namespace std;

struct pais
{
    string nome;
    int ouro, prata, bronze;
};

bool forma(pais a, pais b)
{
    if (a.ouro != b.ouro)
    {
        return a.ouro > b.ouro;
    }
    else if (a.prata != b.prata)
    {
        return a.prata > b.prata;
    }
    else if (a.bronze != b.bronze)
    {
        return a.bronze > b.bronze;
    }
    return a.nome < b.nome;
}

int main()
{
    int paises;

    if (scanf("%d", &paises) != 1)
        return 0;

    pais lista[paises];

    for (int i = 0; i < paises; i++)
    {
        string nome;
        int ouro, prata, bronze;

        cin >> nome >> ouro >> prata >> bronze;

        pais atual = {
            nome, ouro, prata, bronze};
        lista[i] = atual;
    }

    sort(lista, lista + paises, forma);

    for (int i = 0; i < paises; i++)
    {
        cout << lista[i].nome << " " << lista[i].ouro << " " << lista[i].prata << " " << lista[i].bronze << endl;
    }

    return 0;
}
