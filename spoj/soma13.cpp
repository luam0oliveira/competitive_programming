// https://br.spoj.com/problems/SOMA13/
// ad-rock

#include <bits/stdc++.h>

using namespace std;

int mdc(int a, int b){
    if (a<b)
        return mdc(b,a);
    int r = a%b;
    while(b!=0){
        r = a;
        a = b;
        b = r%b;
    }
    return a;
}

// (ad + cb)/db

int main(){
    int a,b,c,d;cin>>a>>b>>c>>d;

    int mdcbd = mdc(b,d);
    int mmcbd = b*d/mdcbd;
    int q = mmcbd;
    int n = a*(mmcbd/b) + c*(mmcbd/d);
    if(mdc(q,n) != 1){
        int div = mdc(q,n);
        q/=div;
        n/=div;
    }
    cout<<n<<" "<<q<<endl;


}