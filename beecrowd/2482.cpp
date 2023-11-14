#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<string, string> dict = {};

    int dict_length;

    cin >> dict_length;

    for (int i = 0; i < dict_length; i++)
    {
        string idioma, palavra;

        cin >> idioma;

        std::getline(std::cin >> std::ws, palavra);

        pair<string, string> par = {idioma, palavra};

        dict.insert(par);
    }

    int child;

    cin >> child;

    for (int i = 0; i < child; i++)
    {
        string nome;
        string idioma;

        std::getline(std::cin >> std::ws, nome);
        cin >> idioma;

        cout << nome << "\n";
        cout << dict[idioma] << "\n\n";
    }
    return 0;
}
