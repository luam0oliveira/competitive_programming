// https://codeforces.com/gym/104505/problem/B
// ad-rock

#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int n;cin>>n;
    vector<ll> posImpares;
    // cout<<posImpares.max_size()<<endl;
    int impares =0;
    for(int i =0;i<n;i++){
        int a;cin>>a;
        if(a%2==1){
            posImpares.push_back(i);
            impares++;
        };
    }
    int e,d;cin>>e>>d;
    if(impares%2) cout<<-1<<endl;
    else{
        ll s1 = 0, s2=0;
        posImpares.push_back(posImpares[0]);
        for(int i=0;i<impares;i+=2){
            ll diffEsq = min(n - max(posImpares[i+1],posImpares[i] ) +  min(posImpares[i+1],posImpares[i] ), abs(posImpares[i+1] - posImpares[i]))* min(e,d);
            s1+=diffEsq;
        }
        for(int i=1;i<=impares;i+=2){
            if (i+1 >= posImpares.size()) break;
            ll diffDir, diffEsq, DdiffEsq, DdiffDir;
            diffEsq = min(n - max(posImpares[i+1],posImpares[i] ) +  min(posImpares[i+1],posImpares[i] ), abs(posImpares[i+1] - posImpares[i]))* min(e,d);
            s2+=diffEsq;
        }
        cout<<min(s1,s2)<<endl;
    }
}