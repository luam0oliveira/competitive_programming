#include <iostream>
#include <sstream>
#include <vector>
#include <array>

using namespace std;

int possibilities[65];
int queen_positision[9];
vector<array<int, 9>> solucoes;
int rows[9];

void reset()
{
    for (int i = 1; i < 9; i++)
    {
        rows[i] = 0;  
    }
}

bool isOk(int linha, int coluna)
{
    for (int i = 1; i < 9; i++)
    {
        // OK 
        if (linha == rows[i])
        {
            return false;
        }

        for (int j = 1; j < 8; j++)
        {
            if ((rows[i] + j == linha || rows[i] - j == linha) && i+j == coluna)
                return false; 
        }
    }
    return true;
}

bool solve(int num_rainhas, array<int, 9> actual)
{
    if(num_rainhas == 9)
    {
        solucoes.push_back(actual);
        return true;
    }

    for (int i = 1; i < 9; i++)
    {
        if (isOk(i,num_rainhas))
        {
            rows[num_rainhas] = i;
            actual[num_rainhas] = i;
            
            solve(num_rainhas+1, actual);

            actual[num_rainhas] = 0;
            rows[num_rainhas] = 0;
        }
    }

    return false;
}

void generate_solutions()
{
    for (int i = 1; i < 9; i++)
    {   
        reset();
        array<int,9> actual = {0,i,0,0,0,0,0,0,0};
        rows[1] = i;
        solve(2,actual);
    }
}


int main()
{
    generate_solutions();

    int ca = 1;
    string line;
    while (getline(cin, line))
    {
        stringstream in(line);


        int min = 8;
        for(int i = 1; i <= 8; i++)
        {
            in >> queen_positision[i];
        }

        for (auto it = solucoes.begin(); it != solucoes.end();it++)
        {
            array<int, 9> solucao = *it;
            int sum = 0;
            for (int i = 1; i < 9; i++)
            {
                if (solucao[i] != queen_positision[i])
                {
                    sum++;
                }
            }
            if (sum < min)
                min = sum;
        }

        printf("Case %d: %d\n", ca, min);
        ca++;
    }
    return 0;
}
