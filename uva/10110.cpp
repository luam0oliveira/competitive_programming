// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1051
// Matematica
// contar o numero de fatores do numero n, e se for impar, retornar yes. porem 
// nao eh possivel fazer a contagem partindo de 1 e indo ate sqrt(n), porque i
// eh muito custoso. entao a ideia eh verificar se o numero eh um quadrado per
// feito, assim ela teria varios pares de fatores diferentes que formaria ela 
// n, e um par de numeros iguais que sao iguais.   

#include<bits/stdc++.h>
#define ll long long
#define QUAT(x) x*x;
using namespace std;

int main(){
    while(true){
        unsigned int n;cin>>n;
        if (n==(unsigned int) 0) break;
        int sq = sqrt(n);
        if (sq * sq != n)cout<<"no"<<endl;
        else cout<<"yes"<<endl;
    }
    return 0;
}
