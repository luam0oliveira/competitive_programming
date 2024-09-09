// https://codeforces.com/contest/80/problem/A
// ad-rock

#include <bits/stdc++.h>

using namespace std;

int primes[51];

void gen_primes(){
    // int MAXN = 50;
    for (int i = 2; i <= 50;i++){
        if (primes[i]) {
            for (int j = i+i;j <= 50; j+=i){
                primes[j] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(primes, 1, 51 * sizeof(int));
    gen_primes();
    int n,m;cin>>n>>m;
    int pos = false;
    for(int i = n+1; i <=50;i++){
        if (primes[i]){
            pos = i == m;
            break;
        }
    }
    if (pos) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    

    return 0;
}
