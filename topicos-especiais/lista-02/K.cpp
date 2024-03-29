#include <iostream>
#include <set>

using namespace std;
int main()
{
    int n, m, a, cont = 1;
    set<int>::iterator it, itc;
    
    while (true)
    {
        cin >> n;
        if (n == 0) return 0;
        
        set<int> sums;
        int nums[n];
        
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            nums[i] = a;
            
            for (int j = 0; j < i; j++)
            {
                sums.insert(nums[i] + nums[j]);
            }
        }
        
        cin >> m;
        cout << "Case " << cont << ":\n";
        for (int i = 0; i < m; i++)
        {
            cin >> a;
            
            it = sums.lower_bound(a);
            if (it != sums.begin())
            {
                itc = --sums.lower_bound(a);
                if (abs(*(itc) - a) < abs(*(it) - a))
                    it = itc;
                    
            }
            
            cout << "Closest sum to " << a << " is " << *it << ".\n";
        }
    
        cont ++;
    }

    return 0;
}
