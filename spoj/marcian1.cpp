// https://br.spoj.com/problems/MARCIAN1/
// matematica

#include <bits/stdc++.h>

using namespace std;

int main(){
    int dim[3];
    int l,a,r,p;
    cin>>l>>a>>p>>r;
    r*=2;
    double d1 = sqrt(l*l + p*p);
    double d2 = sqrt(d1*d1 + a*a);

    if (d2 <= r)
        cout << "S" << endl;
    else
        cout << "N" << endl; 
}
