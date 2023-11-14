#include <iostream>
#include <vector>

using namespace std;

vector<long long int> sequence = {
    0, 1, 1, 1, 2, 2, 4, 8, 12, 96, 108, 10368, 10476, 108615168,
    108625644, 11798392572168192, 11798392680793836};

int main()
{
    int number;

    while (scanf("%d", &number) != EOF)
    {
        cout << sequence[number - 1] << endl;
    }
    return 0;
}