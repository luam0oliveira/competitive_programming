#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

int main()
{
    int testes;
    string fora;
    cin >> testes;

    // cout.precision(4);

    getline(cin, fora);
    getline(cin, fora);
    for (int x = 0; x < testes; x++)
    {
        map<string, int> total;
        int cont = 0;
        string especie = " ";
        // getline(cin,especie);
        // cout << especie << endl;
        while (especie.size() != 0)
        {
            getline(cin, especie);
            // cout << especie << endl;

            if (especie.size() != 0)
            {
                if (total.find(especie) == total.end())
                {
                    pair<string, int> par(especie, 1);
                    total.insert(par);
                }
                else
                {
                    total[especie] += 1;
                }
                cont += 1;
            }
        }

        for (map<string, int>::iterator it = total.begin(); it != total.end(); ++it)
        {
            double porcent = (it->second * 1.0 / cont) * 100.0;
            cout << it->first << " " << fixed << setprecision(4) << std::setprecision(4) << porcent << endl;
        }
        if (testes != x + 1)
            cout << endl;
    }
    return 0;
}