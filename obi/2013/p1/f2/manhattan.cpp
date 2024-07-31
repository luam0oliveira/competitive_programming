// https://olimpiada.ic.unicamp.br/pratique/p1/2013/f2/manhattan/
// Ad-rock

#include <bits/stdc++.h>

using namespace std;

int main(){
    int x1,x2,y1,y2; cin>>x1>>y1>>x2>>y2;
    cout<<max(x1,x2) - min(x1,x2) + max(y1,y2) - min(y1,y2)<<endl; 
}
