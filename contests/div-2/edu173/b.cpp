#include<bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define INF 1e9
#define EPS 1e-9
#define ALL(X) X.begin(), X.end()
using namespace std;

int main() {
    int t;cin>>t;
    while(t--) {
        ll n, d;cin>>n>>d;
        
        int divi[10] = {0};
        divi[1] = 1;
        
        int is = (n >= 3);
        if (n < 3) {
            if (n == 1) {
                is = (d % 3) == 0;
            } else {
                is = ((10*d + d) % 3) == 0;
            }
        }

        if (is) divi[3] = 1;
        
        divi[5] = (d == 5);

        divi[7] = (n >= 3) || (d == 7);

        divi[9] = (n >= 6);
        if (n < 6) {
            int fac = 1;
            for(int i = 1;i <= n;i++) {
                fac *= i;
            }

            int num = fac * d;
            divi[9] = (num % 9) == 0;
        }


        cout << 1;
        for(int i=3;i<10;i+=2) {
            if (divi[i]) cout<<" "<< i;
        }
        cout<<endl;
    }

    return 0;
}