// https://codeforces.com/gym/105164/problem/G
// Ad-rock

#include<bits/stdc++.h>
#define ll long long
#define MIN(a, b) (a < b) ? a : b
#define MAX(a, b) (a < b) ? b : a
#define EPS 1e-9
#define ZERO(a) ? (abs(a) < EPS) ? 1 : 0
    
using namespace std;

int mod(int a, int b){
    return (a%b + b)%b;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;cin>>n;
    vector<int>lista(n+1);
    for(int i = 1;i<=n;i++){
        cin>>lista[i];
    }
    sort(lista.begin(), lista.end());
    int jogada= 0;
    for(int i = 1;i<n;i++){
        if (lista[i] == lista[i-1]) continue;
        if (lista[i] - lista[i-1] == 1) jogada++;
        else break;
    }
    if (jogada%2) cout<<"Bobius"<<endl;
    else cout<<"Alicius"<<endl;
    return 0;
}
