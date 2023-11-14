#include <iostream>
#include <cmath>

using namespace std;

double solve(int garrafasCheias, int necessarias)
{
    return (garrafasCheias / necessarias) + garrafasCheias % necessarias;
}

int main()
{
    int cases;

    cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        int cheias, nec;

        cin >> cheias >> nec;

        cout << solve(cheias, nec) << endl;
    }

    return 0;
}
