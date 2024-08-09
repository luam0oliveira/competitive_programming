// https://br.spoj.com/problems/BICHO/
// Ad-rock
// Refiz essa porque tinha feito no semestre passado e tinha demorado muito (a
// abordagem foi burra) e agora tentei implementar de uma maneira mais correta 
// e de forma mais rapida

#include <bits/stdc++.h>
#define EPS 1e-8
using namespace std;

int mod(int a, int b){
    return ((a % b) + b) % b;
}

bool mesmoGrupo(int a, int b){
    a= mod(a-1,100);b=mod(b-1,100);
    if(a/4 == b/4)
        return true;
    return false;
}

int main(){
    double v;
    int n,m;
    while(scanf("%lf %d %d ", &v, &n, &m) && !(v<=EPS && n==0 && m==0)){
        double recebe = 0;
        if (n%10000 == m%10000)
            recebe = v*3000;
        else if(n%1000 == m%1000)
            recebe = v*500;
        else if (n%100 == m%100)
            recebe = v*50;
        else if (mesmoGrupo(n%100, m%100))
            recebe = v*16;
        printf("%.2f\n", recebe);       
    }
}