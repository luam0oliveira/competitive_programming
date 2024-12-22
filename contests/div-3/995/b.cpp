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
        int a,b,c,n;
        cin >> n>>a>>b>>c;
        int thr = a+b+c;

        int days = 3*(n / thr);
        int aa = thr*(days/3)+a;
        int bb = aa+b;
        int cc = bb+c;



        if (thr * (days/3) >= n) {
            cout << days<<endl;
        } else if (aa >= n) {
            cout << days+1<<endl;
        } else if (bb >= n) {
            cout << days+2<<endl;
        } else {
            cout<<days+3<<endl;
        }
    }
    return 0;
}