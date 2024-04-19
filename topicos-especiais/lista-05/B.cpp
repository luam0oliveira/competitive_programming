#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, d, r, v, sum;

    while(true)
    {
        cin >> n >> d >> r;
        sum = 0;
        if (n == 0 && n == d && n == r) break;

        multiset<int> manha, tarde;

        for (int i = 0; i < n;i++)
        {
            cin >> v;
            manha.insert(v);
        }
        for (int i = 0; i < n;i++)
        {
            cin >> v;
            tarde.insert(v);
        }

        for(auto it = manha.rbegin(); it != manha.rend(); it++)
        {
            int hor = *it;
            auto lb = tarde.lower_bound(d - *it);
            auto antlb = tarde.lower_bound(d - *it);

            if (lb == tarde.end())
            {
                lb--;
                antlb--;
                antlb--;
            }
            if (antlb == tarde.begin())
            {
                // cout << *antlb << " "<<*lb  << endl;
                antlb++;
            }

            if (antlb == tarde.end());
                antlb--;
            if (*antlb + hor - d >= *lb + hor - d)
            {
                hor += *lb; 
                tarde.erase(lb);
            }
            else
            {
                hor += *antlb;
                tarde.erase(antlb);
            }

            if (hor > d)
                sum += (hor - d)*r;
        }

        cout << sum << endl;

    }

    return 0;
}
