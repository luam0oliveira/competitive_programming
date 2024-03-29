#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{   
    int n, c, max, ans;
    map<vector<int>, int> cc;
    while(true)
    {
        cc.clear();
        cin >> n;
        max = 0;

        if (n == 0)
            return 0;

        for (int i = 0; i < n; i++)
        {
            vector<int> num;
            for (int j = 0; j < 5; j++)
            {
                cin >> c;
                num.push_back(c);                
            }
            sort(num.begin(), num.end());
            
            if (cc[num])
                cc[num]++;
            else
                cc[num] = 1;
            if (max < cc[num])
                    max = cc[num];
        }
        
        ans = 0;
        
        for ( map<vector<int>, int>::iterator it = cc.begin(); it != cc.end(); it++)
        {
            if (it->second == max)
                ans += max;
        }
        
        cout << ans << endl;
    }

}
