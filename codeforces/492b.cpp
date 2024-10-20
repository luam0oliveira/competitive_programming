/**
 *     author: demot.r
 *     created: 2024-10-19 19:29:34
 *     source: https://codeforces.com/contest/492/problem/B
 *     description: ad-rock
**/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n,l;cin>>n>>l;
    vector<int> lights(n);
    int diff = 0;
    cin>>lights[0];
    for(int i = 1;i<n;i++) {
        cin>>lights[i];
    }
    sort(lights.begin(), lights.end());
    for (int i = 1; i<n;i++){
        diff = max(diff, lights[i] - lights[i-1]);
    }
    if (lights[0] != 0) {
        diff = max(diff, (lights[0])*2);
    }

    if (lights[n-1] != l) {
        diff = max(diff, (l - lights[n-1])*2);
    }

    printf("%.10f\n", ((double) diff) / 2.0);
    return 0;
}