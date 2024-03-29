#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int num;
vector<int> divisores;

bool is_permutation(string n)
{
    int vet[10] = {0,0,0,0,0,0,0,0,0,0};
    
    
    for (int i = 0; i < n.size(); i++)
    {
        int nnn = n[i] - '0';
        vet[nnn] ++;
        if(vet[nnn] > 1)
            return false;
    }
    
    return true;
}

bool is_permutation(string n1, string n2)
{
    int vet[10] = {0,0,0,0,0,0,0,0,0,0};
    
    if (n1.size() < 5)
        n1 = "0" + n1;
    
    if (n2.size() < 5)
        n2 = "0" + n2;
    
    string n = n1 + n2;
    for (int i = 0; i < 10; i++)
    {
        int nnn = n[i] - '0';
        vet[nnn] ++;
        if(vet[nnn] > 1)
            return false;
    }
    
    return true;
}


int main()
{
    int n;
    bool has, first = true;
    while(true)
    {
        cin >> n;
        
        has = false;
        
        if (n == 0) break;
        
        if (!first)
            cout << endl;
        
        
        for (int i = 1234; i < 50000 && i * n < 100000; i++)
        {
            if (is_permutation(to_string(i)) && is_permutation(to_string(i * n),to_string(i) ))
            {
                printf("%05d / %05d = %d\n", i * n, i, n);
                has = true;
            }
        }
        
        if (!has)
            cout << "There are no solutions for " << n << "." << endl;
        first = false;
    }
    
    return 0;
}
