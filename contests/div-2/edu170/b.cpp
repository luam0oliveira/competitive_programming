/**
 *     author: demot.r
 *     created: 2024-10-14 11:46:57
 *     source: https://codeforces.com/contest/2025/problem/B
 *     description: memo
**/

#include<bits/stdc++.h>
#define ll long long
const int MOD = 1e9+7;
using namespace std;
    // int C[10][10];
    // int N = 10;
    // for (int n = 0; n < N; n++) { // loop over n from 0 to N-1 (inclusive)
    //     C[n][0] = 1;
    //     C[n][n] = 1;
    //     for (int k = 1; k < n; k++) // loop over k from 1 to n-1 (inclusive)
    //         C[n][k] = C[n][k - 1] + C[n - 1][k - 1];
    // }
    // for (int n = 0; n < N; n++) { // loop over n from 0 to N-1 (inclusive)
    //     for (int k = 0; k <= n; k++) // loop over k from 1 to n-1 (inclusive)
    //         cout << C[n][k] << " ";
    //     cout<<endl;
    // }

int main() {
    int t;
    cin>>t;
    ll pot[100000+10];
    pot[0] = 1;
    for(int i = 1; i < 100000+10;i++){
        pot[i] = (pot[i-1] * 2) % MOD;
    }
    pair<int,int> pares[100000];
    for(int i = 0; i < t;i++){
        cin >> pares[i].first;
    }

    for(int i = 0; i < t;i++){
        cin >> pares[i].second;
    }

    for(int i = 0; i < t;i++){
        if (pares[i].first == pares[i].second){
            cout<<1<<endl;
        }else{
            cout << pot[pares[i].second] << endl;
        }
    }



    return 0;
}
