#include<bits/stdc++.h>
#define ll long long
#define MIN(a, b) (a < b) ? a : b
#define MAX(a, b) (a < b) ? b : a
#define EPS 1e-9
#define ZERO(a) ? (abs(a) < EPS) ? 1 : 0
    
using namespace std;
    
int main() {
    int q,v;cin>>q>>v;
    double p,n;
    double vp = v * 0.75, vn = v * 0.25;
    double total = 0;
    for(int i =0;i<q;i++){
        char type; int a;cin>>type>>a;
        if (type=='P')p+=a;
        else n+=a;
    }
    if (p/vp > n/vn){
        total+=n/vn;
        p-=total*vp;
        total+=(p/double(v));
    }else{
        total+=p/vp;
        n-=total*vn;
        total+=(n/double(v));
    }
    
    printf("%.10f\n", total);
}
