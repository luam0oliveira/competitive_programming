// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=305
// ad-rock

#include<bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define QUAT(x) x*x;
using namespace std;

ll fatores[101];
bitset<101> primos;
int listOfPrimes[101];
int cont = 0;
void sieve(){
    primos.set();
    for(int i = 2; i <= 100;i++){
        if (!primos.test(i)) continue;

        for(int j = i+i; j <= 100; j+=i){
            primos.reset(j);
        }
        listOfPrimes[cont++] = i;
    }
}

int main(){
    sieve();
    int n,m;
    while(cin>>n>>m && !(n == 0 && m == 0)){
        memset(fatores, 0, sizeof(fatores));
        for (int i = 2; i <= n; i++){
            int value = i;
            int idxAtual = 0;
            int prime = listOfPrimes[idxAtual];
            while(value > 1){
                if (value % prime){
                    prime = listOfPrimes[++idxAtual];
                } else {
                    value /= prime;
                    fatores[prime]++;
                }
            }
        }

        for (int i = 2; i <= m; i++){
            int value = i;
            int idxAtual = 0;
            int prime = listOfPrimes[idxAtual];
            while(value > 1){
                if (value % prime){
                    prime = listOfPrimes[++idxAtual];
                } else {
                    value /=prime;
                    fatores[prime]--;
                }
            }
        }

        for (int i = 2; i <= (n-m); i++){
            int value = i;
            int idxAtual = 0;
            int prime = listOfPrimes[idxAtual];
            while(value > 1){
                if (value % prime){
                    prime = listOfPrimes[++idxAtual];
                } else {
                    value /=prime;
                    fatores[prime]--;
                }
            }
        }

        ll ans = 1;

        for(int i = 1; i <= 100; i++){
            // cout<<fatores[]
            ans *= pow(i, fatores[i]);
        }

        printf("%d things taken %d at a time is %lld exactly.\n", n, m, ans);

    }

    return 0;
}
