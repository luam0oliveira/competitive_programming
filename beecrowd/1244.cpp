#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int k;

    cin >> k;

    for (int i = 0; i < k; i++)
    {
        string frase;
        vector<string> palavras;

        std::getline(std::cin >> ws, frase, '\n');

        int l = 0;

        string palavra = "";
        while (frase[l] != '\0')
        {
            if (frase[l] != ' ')
            {
                palavra += frase[l];
            }
            else
            {
                palavras.push_back(palavra);
                palavra = "";
            }
            l += 1;
        }

        palavras.push_back(palavra);

        bool change = true;
        while (change)
        {
            change = false;

            for (int j = 0; j < palavras.size() - 1; j++)
            {
                if (palavras[j].size() < palavras[j + 1].size())
                {
                    change = true;
                    string aux = palavras[j + 1];
                    palavras[j + 1] = palavras[j];
                    palavras[j] = aux;
                }
            }
        }

        cout << palavras[0];
        for (int j = 1; j < palavras.size(); j++)
        {
            cout << " " << palavras[j];
        }
        cout << endl;
    }

    return 0;
}