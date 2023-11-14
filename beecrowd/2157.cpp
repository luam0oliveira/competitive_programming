#include <iostream>

using namespace std;

int main()
{
    int cases;
    cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        int init, end;

        cin >> init >> end;

        string inverso = "";

        for (int j = init; j <= end; j++)
        {
            cout << j;
            inverso += to_string(j);
        }

        for (int j = inverso.size() - 1; j >= 0; --j)
        {
            cout << inverso[j];
        }
        cout << endl;
    }

    return 0;
}
