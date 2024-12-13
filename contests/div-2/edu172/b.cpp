/**
 *     author: demot.r
 *     created: 2024-12-02 12:52:32
 *     source: 
 *     description: 
**/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int numbers[1001];

int main() {
    int t;cin>>t;
    while (t--) {
        memset(numbers, 0, sizeof(numbers));
        int n;cin>>n;
        int count1 = 0;
        int diff = 0;

        for(int i=0;i<n;i++) {
            int a;cin>>a;
            if (numbers[a] == 0) {
                count1++;
                diff++;
            }
            if (numbers[a] == 1) count1--;
            numbers[a]++;
        }

        cout << 2*((count1+1)/2) + (diff - count1)<<endl;
    }   
    return 0;
}