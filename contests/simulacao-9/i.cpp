/**
 *     author: demot.r
 *     created: 2024-11-27 22:11:56
 *     source: 
 *     description: 
**/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n;cin>>n;
    int toadd;
    vector<int> partidas;
    while(n > 0) {
        int a;
        if (n >= 15) {
            toadd = n/15;
            a = 1;
            n-=toadd*15;
        } else if (n >= 12) {
            toadd = n/12;
            a = 2;
            n-=toadd*12;
        } else if (n >= 10) {
            toadd = n/10;
            a = 3;
            n-=toadd*10;
        } else {
            toadd = 1;
            a = 2 + (11 - n);
            n = 0;
        }

        for (int i=0;i<toadd;i++) {
            partidas.push_back(a);
        }
    }
    cout<<partidas.size()<<endl;
    cout << partidas[0];
    for(int i=1;i<(int) partidas.size();i++) {
        cout <<" "<<partidas[i];
    }
    cout<<endl;
    return 0;
}