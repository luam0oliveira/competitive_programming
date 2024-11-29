// foi necessario ver o upsolving para terminar a questao

/**
 *     author: demot.r
 *     created: 2024-11-28 16:57:56
 *     source: 
 *     description: 
**/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int gcd(int a, int b) {
    if (a < b) return gcd(b, a);
    while (b != 0) {
        int aux = b;
        b = a % b;
        a = aux;
    }
    return a;
}

int sieve[100010];

vector<int> fact(int n) {
    vector<int> ret;
    for (int i=2;i<=n/i; i++) {
        if (n%i==0){
            ret.push_back(i);
            while(n%i==0) n/=i;
        }
    }
    if (n > 1) ret.push_back(n);
    return ret;
}


int main() {
    int n;cin>>n;
    vector<int> pares;
    
    ll prod = 1;
    ll usado = false;

    for(int i=0;i<n;i++) {
        int a,b;cin>>a>>b;
        int div = gcd(a,b);
        b/=div;
        if (b > 1) {
            usado = true;
            for(auto j:fact(b)) {
                sieve[j]=1;
            }
        }
    }
    if (usado) {
        for(int i=0;i<100010;i++) {
            if (sieve[i] == 1) {
                prod = (prod * i) % 998244353;
            }
        }
        cout<<prod<<endl;
    }else{
        cout<<2<<endl;
    }


    return 0;
}