#include <iostream>

using namespace std;

const int MODULE = 2147483647;
const long long BASE = 3;

int power(long long x, int y)
{
    long long int result = 1;

    while (y)
    {
        if (y % 2 == 1)
        {
            result = (result * x) % MODULE;
        }

        x = (x * x) % MODULE;
        y >>= 1;
    }
    return result;
}

int main()
{
    int number;
    cin >> number;

    cout << power(BASE, number) << endl;
    return 0;
}