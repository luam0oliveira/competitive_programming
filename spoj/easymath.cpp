// https://www.spoj.com/problems/EASYMATH/
// Matematica
// Inclusao e exclusao - tem caso especial no caso de n for divisivel pelo mmc
// porque ai ela poderia excluir aquele numero e a resposta ser errada por 1.

#include<bits/stdc++.h>
#define ll long long
#define QUAT(x) x*x;
using namespace std;


// retorna o mdc
ll gcd(ll a, ll b){
    if (a < b) return gcd(b,a);
    while(b !=0){
        ll aux= b;
        b = a%b;
        a = aux;
    }
    return a;
}

// retorna o mmc
ll lcm(ll a, ll b){
    return (a*b)/gcd(a,b);
}

int main(){
    int t;scanf("%d ", &t);
    while(t--){
        int n,m,a,d;scanf("%d %d %d %d ", &n, &m, &a, &d);
        ll cont = 0;
        n--;
        vector<int> divisores;
        for(int i=0;i<=4;i++){
            divisores.push_back(a+i*d);
        }

        for(int i=0;i<(int)divisores.size();i++){
            ll mmc = divisores[i];
            cont += m/mmc - n /mmc;
            cout<<"uu = "<<m/mmc - n /mmc<<endl;
        }
        for(int i=0;i<(int)divisores.size();i++){
            for(int j=i+1;j<(int)divisores.size();j++){
                ll mmc = lcm(divisores[i],divisores[j]);
                cont -= m/mmc - n /mmc;
            }
        }

        for(int i=0;i<(int)divisores.size();i++){
            for(int j=i+1;j<(int)divisores.size();j++){
                for(int k=j+1;k<(int)divisores.size();k++){
                    ll mmc = lcm(lcm(divisores[i],divisores[j]), divisores[k]);
                    cont += m/mmc - n /mmc;
                }
            }
        }

        for(int i=0;i<(int)divisores.size();i++){
            for(int j=i+1;j<(int)divisores.size();j++){
                for(int k=j+1;k<(int)divisores.size();k++){
                    for(int l=k+1;l<(int)divisores.size();l++){
                        ll mmc = lcm(lcm(lcm(divisores[i],divisores[j]), divisores[k]),divisores[l]);
                        cont -= m/mmc - n /mmc;
                    }
                }
            }
        }
        ll mmc = lcm(lcm(lcm(lcm(divisores[0],divisores[1]), divisores[2]),divisores[3]), divisores[4]);
        cont += m/mmc - n /mmc;
        cout<<m-n - cont<<endl;
    }
    return 0;
}
