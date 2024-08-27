// https://codeforces.com/problemset/problem/160/A
// ad-rock

#include<bits/stdc++.h>
#define ll long long
#define QUAT(x) x*x;
using namespace std;

const int MAXN = 1e2+1;
int coins[MAXN], sums[MAXN];
int main(){
    int c;scanf("%d ", &c);
    
    for(int i=0;i<c;i++){
        scanf("%d ", &coins[i]);
    }
    sort(coins, coins + c);
    for(int i=0;i<c;i++){
        sums[i+1] = sums[i]+coins[i];
    }
    int i;
    for(i=c;i>=0;i--){
        if (sums[c] - sums[i] > sums[i]) break;
    }
    printf("%d\n", c-i);
}
