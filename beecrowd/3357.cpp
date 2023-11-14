#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int pessoasRoda;
    double total, pessoa;

    vector<string> pessoas = {};
    if (scanf("%d %lf %lf", &pessoasRoda, &total, &pessoa) == 0)
        ;

    for (int i = 0; i < pessoasRoda; i++)
    {
        string nome;
        cin >> nome;

        pessoas.push_back(nome);
    }

    int passadas = (int)(total / pessoa);
    int posicao = passadas % pessoasRoda;
    if (passadas * pessoa == total)
    {
        posicao -= 1;
        if (posicao == -1)
            posicao += pessoasRoda;
        passadas -= 1;
    }

    printf("%s %.1f\n", pessoas[posicao].c_str(), total - (passadas * pessoa));
}

int main()
{
    solve();
    return 0;
}