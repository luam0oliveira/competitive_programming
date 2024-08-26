// https://codeforces.com/gym/104505/problem/E
// Divisao e conquista

#include<bits/stdc++.h>
#define ll long long
#define QUAT(x) x*x;
using namespace std;
const int MAXN = 1e5+1;
ll yi=1,zi=1,xi=1, n;

ll dminima=1e18;
struct point{
    ll x,y,z;
    int p;
};
point pontos[MAXN];
point ff {1,1,1,0};
ll calcDist(ll x, ll y, ll z){
    return (x-xi)*(x-xi) + (z-zi)*(z-zi) + (y-yi)*(y-yi);
}


ll calculaTotalDist(){
    ll d = 0;
    for(int i = 0;i<n;i++){
        d += calcDist(pontos[i].x, pontos[i].y, pontos[i].z)*pontos[i].p;
    }
    return d;
}

void ternary(ll &value, int f){
    int l=1, r = 2*1e5;
    int m1 = l + (r-l)/3;
    int m2 = r - (r-l)/3;
    while(l<=r){
        m1 = l + (r-l)/3;
        m2 = r - (r-l)/3;
        value = m1;
        ll d1 = calculaTotalDist();
        value = m2;
        ll d2 = calculaTotalDist();

        // cout<<d2<<" "<<d1<<endl;
        if (d1 == d2){
            l = m1+1;
            r = m2-1;
            value = m1;
        }else if (d1 > d2){
            l = m1+1;
            value = m2;
        }else{
            r = m2-1;
            value = m1;
        }
        
    }
}
int main(){
    cin>>n;
   for(int i = 0;i<n;i++){
    cin>>pontos[i].x>>pontos[i].y>>pontos[i].z>>pontos[i].p; 
    // cout<<pontos[i].p<<endl;
   }
   ternary(xi, 0);
   ternary(yi, 0);
   ternary(zi, 0);

   cout<<xi<<" "<<yi<<" "<<zi<<endl;
}