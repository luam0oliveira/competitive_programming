#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool check(string s1, unsigned x)
{
    unsigned i = 0;
    unsigned resto = 0;
    while (s1[i])
    {
        if (s1[i] == '1')
        {
            resto = (resto * 2 + 1) % x;
        }

        if (s1[i] == '0')
        {
            resto = (resto * 2) % x;
        }

        i++;
    }

    if (resto % x == 0)
        return true;
    else
        return false;
}

int main()
{
    string str;
    int m;

    cin >> str >> m;

    vector<int> t_divisors;

    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        if (check(str, num))
        {
            t_divisors.push_back(num);
        }
    }

    sort(t_divisors.begin(), t_divisors.end());

    int len = t_divisors.size();

    if (len == 0)
    {
        cout << "Nenhum" << endl;
    }
    else
    {
        bool first = true;
        for (int i = 0; i < t_divisors.size(); i++)
        {
            if (first)
            {
                first = false;
                cout << t_divisors[i];
            }
            else
            {
                cout << " " << t_divisors[i];
            }
        }
        cout << endl;
    }

    return 0;
}