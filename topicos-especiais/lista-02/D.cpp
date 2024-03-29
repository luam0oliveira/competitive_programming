#include <iostream>
#include <queue>
using namespace std;

int main()
{   
    int num;
    while (true)
    {
        queue<int> q;
        int numeros[50], fora = 0, saindo;

        cin >> num;
        if (num == 0)
            return 0;
        for (int i = 1; i <= num;i++)
        {
            q.push(i);
        }

        while (q.size() != 1)
        {
            saindo = q.front();
            q.pop();
            q.push(q.front());
            q.pop();
            numeros[fora] = saindo;
            fora += 1;
        }

        cout << "Discarded cards:";
        if (fora >= 1)
            cout << " " << numeros[0];
        for (int i = 1; i < fora; i++)
        {
            cout << ", " << numeros[i];
        }

        cout << "\n";

        cout << "Remaining card: ";
        if (q.size() == 1)
           cout << q.front();
        cout << "\n";
    }

}
