#include <iostream>

using namespace std;
const int MOD = 1300031;

// From Geeksforgeeks
int power(long long x, unsigned int y) 
{ 
    int res = 1;     // Initialize result 
 
    x = x % MOD; // Update x if it is more than or 
                // equal to p
  
    if (x == 0) return 0; // In case x is divisible by MOD;
 
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % MOD; 
 
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % MOD; 
    } 
    return res; 
} 

int multMod(int init, int fim )
{
    long long result = 1;

    for (int i = init; i <= fim; i++)
    {
        result = (result*i) % MOD;
    }

    return (int) result % MOD;
}

int main()
{
    int cases, m, n, ans, ls, l;
    cin >> cases;

    while (cases--)
    {
        cin >> n >> m;

        ls = n - m * 2;
        l = m + ls;
        ans = (multMod(l - m + 1, l) * power(2,m)) % MOD;
        cout << ans << endl;
    }
}