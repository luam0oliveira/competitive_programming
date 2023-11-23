#include <bits/stdc++.h>

using namespace std;

int toDec(char a)
{
    if (a - '0' < 10)
    {
        return (int)a - '0';
    }
    else
    {
        if (a == 'a' or a == 'A')
        {
            return 10;
        }
        else if (a == 'b' or a == 'B')
        {
            return 11;
        }
        else if (a == 'c' or a == 'C')
        {
            return 12;
        }
        else if (a == 'd' or a == 'D')
        {
            return 13;
        }
        else if (a == 'e' or a == 'E')
        {
            return 14;
        }
        else
        {
            return 15;
        }
    }
}

long int passToDecimal(string a, int tamanho)
{
    long int numFinal = 0;
    int atual;
    for (int i = 0; i < tamanho; i++)
    {
        atual = toDec(a[i]);
        numFinal += atual * pow(16, tamanho - 1 - i);
    }

    return numFinal;
}

char toHex(int a)
{
    if (a < 10)
    {
        return (char)(a + '0');
    }
    else
    {
        if (a == 10)
        {
            return 'A';
        }
        else if (a == 11)
        {
            return 'B';
        }
        else if (a == 12)
        {
            return 'C';
        }

        else if (a == 13)
        {
            return 'D';
        }
        else if (a == 14)
        {
            return 'E';
        }
        else if (a == 15)
        {
            return 'F';
        }
    }
    return '0';
}

string passToHexa(int a)
{
    string number = "0x";
    int power = 7;
    int base = 16;
    long int divisor = (long int)pow(base, power);
    int nb;
    while (power >= 0)
    {
        if (a / divisor >= 1)
        {
            nb = ((a - (a % divisor)) / divisor);
            number += toHex(nb);
            a = a % divisor;
        }
        else
        {
            if (number != "0x")
            {
                number += '0';
            }
        }
        power -= 1;
        divisor = pow(base, power);
    }
    return number;
}

int main()
{
    string input;
    while (true)
    {
        cin >> input;
        if (input == "-1")
        {
            return 0;
        }

        int tamn = input.size();
        bool hexa = false;
        if (tamn > 1)
        {
            if (input[1] == 'x')
            {
                hexa = true;
            }
        }

        if (hexa)
        {
            cout << passToDecimal(input.substr(2, tamn - 2), tamn - 2) << endl;
        }
        else
        {
            string nb = passToHexa(stoi(input));
            cout << nb << endl;
        }
    }
}
