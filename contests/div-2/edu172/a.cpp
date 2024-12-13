#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--) {
        int n, k;cin>>n>>k;
        vector<int> chest;
        for(int i=0;i<n;i++) {
            int a;cin>>a;
            chest.push_back(a);
        }
        sort(chest.begin(), chest.end());
        
        int sum = 0;
        for(int i=n-1;i>=0;i--) {
            if (sum + chest[i] > k) break;
            sum+=chest[i];
        }
        cout<<k-sum<<endl;
    }

    return 0;
}