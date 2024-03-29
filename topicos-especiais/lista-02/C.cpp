#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    int a, n, total;
    while (true)
    {
        priority_queue<int, vector<int>, greater<int>> q;
        cin >> n;
        total = 0;
        if (n == 0) return 0;
        
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            q.push(a);
        }
        
        
        while (q.size() != 1)
        {
            a = q.top();
            q.pop();
            a += q.top();
            q.pop();
            total += a;
            q.push(a);
        }
        
        cout << total << endl;
        
    }
    
    return 0;
}
