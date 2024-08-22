// https://codeforces.com/gym/105164/problem/A
// Ad-rock

#include<bits/stdc++.h>
#define ll long long
#define MIN(a, b) (a < b) ? a : b
#define MAX(a, b) (a < b) ? b : a
#define EPS 1e-9
#define ZERO(a) ? (abs(a) < EPS) ? 1 : 0
    
using namespace std;

int mod(int a, int b){
    return (a%b + b)%b;
}

void fastIO(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
}

const int MAXN = 1e4 + 1;
int n;
int arr[MAXN];
int dp[MAXN][MAXN];
const int MARK = -1;

int dpp(int l, int r){
    if (l==r){
        return dp[l][r] = 1e7;
    }
    if (dp[l][r]!=MARK) return dp[l][r];
    return dp[l][r] = min({dpp(l+1,r), dpp(l, r-1), abs(arr[l] - arr[r])});
}

int main() {
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    for(int i =0;i<MAXN;i++)
        for(int j =0;j<MAXN;j++)
            dp[i][j]=MARK;
    

    dpp(0, n-1);

    int q;cin>>q;
    for(int i =0;i<q;i++){
        int l,r;cin>>l>>r;
        l--;r--;
        cout<<dp[l][r]<<endl;
    }

    return 0;
}
