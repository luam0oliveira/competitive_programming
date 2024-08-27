// https://codeforces.com/contest/677/problem/A
// ad-rock

#include<bits/stdc++.h>
#define ll long long
#define QUAT(x) x*x;
using namespace std;

int main(){
    int n,k;scanf("%d %d ", &n, &k);
    int total=0;
    for(int i=0;i<n;i++){
        int h;scanf("%d ", &h);
        if (h>k)total+=2;
        else total++;
    }    
    printf("%d\n",total);
}
