#include <bits/stdc++.h>

using namespace std;



int n, fields[100];


int main()
{
    int cases, cont, actual = 1;
    char c;
    
    cin >> cases;
    
    while (cases--)
    {
        cin >> n;
        cont = 0;
        // 0 eh infertil e 1 fertil
        for(int i =0; i < n;i++)
        {
            cin >> c;
            
            if (c == '.')
                fields[i] = 1;
            else
                fields[i] = 0;
        }
        
        for (int i = 0; i < n;)
        {
            int j = i;
            bool ativo = false;
            if (fields[i] == 1)
            {
                for (; i + 3 != j && j < n; j++)
                {
                    if (fields[j] == 1)
                    {
                        ativo = true;
                    }
                }
                i = j; 
                if (ativo)
                    cont++;
            }
            else{
                i++;
            }
        }
        cout << "Case "<<actual <<": "<< cont << endl;
        actual++;
    }

    return 0;
}
