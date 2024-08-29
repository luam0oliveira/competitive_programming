// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2172
// Matematica 

#include<bits/stdc++.h>
#define ll long long
#define QUAT(x) x*x;
using namespace std;

int main(){
    while(true){
        int n,m,c;scanf("%d %d %d ", &n, &m, &c);
        if (n == 0 && m == 0 && c ==0) break;
        n-=7;m-=7;
        if (c==1) cout << ((n+1)/2) * ((m+1)/2) + ((n)/2) * ((m)/2) <<endl;
        else cout<< ((n+1)/2) * ((m)/2) + ((n)/2) * ((m+1)/2)<<endl;
    }
    return 0;
}
