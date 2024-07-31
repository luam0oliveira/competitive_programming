// https://olimpiada.ic.unicamp.br/pratique/pj/2015/f1/premio/
// Ad-rock

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;cin>>n;
    int a, sum;
    int i, dia= -1;
    for(i=0;i<n && sum <1e6;i++){
        cin>>a;
        sum+=a;
    }
    cout<<i<<endl;
}