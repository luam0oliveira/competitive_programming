// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=349
// Matematica
// verificar se sao coprimos - isso acontece porque actual % mod = 0 somente qu
// ando actual = step * mod

#include<bits/stdc++.h>
#define ll long long
#define QUAT(x) x*x;
using namespace std;

int mdc(int a, int b){
    if (b > a) return mdc(b, a);
    while(b!=0){
        int aux = b;
        b = a % b;
        a = aux;
    }
    return a;
}

int main(){
    int step, mod;
    while(scanf("%d %d ", &step, &mod) != -1){
        printf("%10d%10d", step, mod);
        if (mdc(step,mod)==1){
            printf("%4s%s\n","", "Good Choice");
        }else{
            printf("%4s%s\n","", "Bad Choice");
        }
        printf("\n");
    }
    return 0;
}
