// https://br.spoj.com/problems/SUBPRIME/
// Ad-rock

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    while(scanf("%d %d ", &n, &m) && !(n==0 && m == 0)){
        vector<int> bancos(n);
        for(int i =0;i<n;i++)
            scanf("%d ", &bancos[i]);
        for(int i =0;i<m;i++){
            int u,v,a; scanf("%d %d %d ", &u,&v,&a);
            bancos[--u]-=a;bancos[--v]+=a;
        }
        bool valido = true;
        for(int i =0;i<n;i++)
            if (bancos[i] < 0) valido = false;
        
        if(valido)printf("S\n");
        else printf("N\n");
    }
}