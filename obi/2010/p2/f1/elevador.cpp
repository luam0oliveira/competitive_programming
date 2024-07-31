// https://olimpiada.ic.unicamp.br/pratique/p2/2010/f1/elevador/
// Ad-rock

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, cap;scanf("%d %d ", &n, &cap);
    int s,e;
    int quant = 0;
    bool valido = true;
    for(int i=0;i<n;i++){
        scanf("%d %d ", &s, &e);
        quant-=s;
        quant+=e;
        if (quant>cap) valido = false;
    }
    if (valido) printf("N\n"); else printf("S\n");
}
