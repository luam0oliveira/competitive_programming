// https://codeforces.com/problemset/problem/231/A
// ad-rock

#include<bits/stdc++.h>
#define ll long long
#define QUAT(x) x*x;
using namespace std;


int main(){
    int p, cont=0;cin>>p;

    while(p--){
        int cc=0, a;
        for(int i =0;i<3;i++){
            scanf("%d ", &a);
            if (a)cc++;
        }
        if(cc>=2)cont++;
    }
    printf("%d\n",cont);
}
