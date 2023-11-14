#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int pessoas, litros, ml, total = 0;

    if (scanf("%d %d %d", &pessoas, &litros, &ml))
        ;

    while (pessoas * ml > total)
    {
        total += litros * 1000;
    }

    cout << total / 1000 << endl;
}

int main()
{
    solve();
    return 0;
}