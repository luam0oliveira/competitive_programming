// https://olimpiada.ic.unicamp.br/pratique/p2/2008/f1/obi/
// Ad-rock

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,minimo;scanf("%d %d ", &n, &minimo);
    int cont=0;
    for(int i =0;i<n;i++){
        int a, sum=0;
        cin>>a;
        sum+=a;
        cin>>a;
        sum+=a;
        if (sum >= minimo) cont++;
    }
    cout<<cont<<endl;
}
