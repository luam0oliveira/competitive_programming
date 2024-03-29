#include <iostream>
#include <set>

using namespace std;

int main()
{
    while (true)
    {
        int n, k, ki;
        long total = 0;
        multiset<int> b;
        multiset<int>::iterator ma, me;

        cin >> n;
        if (n == 0)
            return 0;

        for (int i = 0; i < n; i++)
        {
            cin >> k;

            for (int j = 0; j < k; j++)
            {
                cin >> ki;
                b.insert(ki);
            }
            me = b.begin();
            ma = --b.end();
            total += *(ma) - *(me);
            b.erase(ma);
            b.erase(me);
        }

        cout << total << endl;

    }
    return 0;
}
