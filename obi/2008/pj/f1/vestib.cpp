// https://olimpiada.ic.unicamp.br/pratique/pj/2008/f1/vestib/
// Ad-rock

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;cin>>n;
    string a,b;cin>>a>>b;
    int cont = 0;
    for (int i = 0;i<n;i++){
        if (a[i]==b[i])cont++;
    }
    cout<<cont<<endl;
    return 0;
}