// https://olimpiada.ic.unicamp.br/pratique/p2/2013/f1/alvo/
// Ad-rock / Problema de implementação

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int c,t;scanf("%d %d ", &c, &t);
    vector<ll> raios;
    for(int i =0;i<c;i++){
        ll a;
        scanf("%lld ", &a);
        raios.push_back(a*a);
    }
    ll maior = raios[c-1];
    vector<ll>tiros;
    for(int i =0;i<t;i++){
        ll x,y;
        scanf("%lld %lld ", &x, &y);
        ll mult = x*x + y*y;
        if (mult > maior) continue;
        tiros.push_back(mult);
    }
    sort(tiros.begin(), tiros.end());
    ll pont =0;
    t = tiros.size();
    int j = c-1;
    for(int i=t-1; i>=0;i--){
        while (j>0 && tiros[i]<=raios[j-1]){
            j--;
        }
        pont+=c-j;
    }
    printf("%lld\n", pont);
}
