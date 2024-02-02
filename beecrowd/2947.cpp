#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num_quest, num_gab, total = 0;

    string gab_desaf;

    cin >> num_quest;

    cin >> gab_desaf;

    cin >> num_gab;

    vector<string> gabs; 
    
    for (int i = 0; i < num_gab; i++)
    {
        string gab;
        cin >> gab;
        gabs.insert(gabs.end(),gab);
    }


    for (int i = 0; i < num_quest; i++)
    {
        int resp[26] = {0};

        int maior = 0;
        for (int j = 0; j < num_gab; j++)
        {
            if (gab_desaf[i] != gabs[j][i])
            {
                int letra = gabs[j][i] - 'A';
                resp[letra] += 1;
                if (maior < resp[letra])
                {
                    maior = resp[letra];
                }
            }
        }
        total += maior;
    }

    cout << total << endl;

    return 0;
}
