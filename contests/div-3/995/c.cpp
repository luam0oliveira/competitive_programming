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
        int n,m,k;cin>>n>>m>>k;
        vector<int> list(m);
        vector<int> know(k);
        for(int i = 0;i<m;i++) {
            cin >> list[i];
        }

        int nao = n;
        for(int i = 0;i<k;i++) {
            cin >> know[i];
            // if (i+1 != know[i] && nao == -1) nao = i+1;
        }
        
        if (n == k) {
            for(int i = 0;i<m;i++) {
                cout<<1;
            }
            cout<<endl;
        }else if (n-k > 1){
            for(int i = 0;i<m;i++) {
                cout<<0;
            }
            cout<<endl;
        } else {
            for(int i=0;i<k;i++) {
                if (know[i] -1 != i) {
                    nao = i+1;
                    break;
                }
            }

            for(int i=0;i<m;i++) {
                cout << (nao==list[i]);
            }
            cout<<endl;
        }
    }   
    return 0;
}