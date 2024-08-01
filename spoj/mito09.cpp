// https://br.spoj.com/problems/MITO09/
// ad-rock

#include <bits/stdc++.h>

using namespace std;

int mapa[501][501];

int main()
{
    int n, x, y;
    int cont = 0;

    cin >> n;

    while (n--)
    {
        cin >> x >> y;
        if (mapa[x][y])
            cont++;
        mapa[x][y]++;
    }
    cout << (int)(cont > 0)<<endl;


}
