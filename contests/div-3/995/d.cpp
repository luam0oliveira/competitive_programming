#include<bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define INF 1e9
#define EPS 1e-9
#define ALL(X) X.begin(), X.end()
using namespace std;

vector<int> numeros;
int n,minn, maxx;
int possible(ll sum, ll left, ll right, int mostrar = false) {
    ll nn = sum - numeros[left] - numeros[right];
    if (nn >= minn && nn <= maxx) return 0;
    else if (nn >= minn) return -1;
    else return 1;
}


int main() {
    int t;cin>>t;
    while(t--) {
        cin>>n>>minn>>maxx;
        ll sum = 0;
        numeros.assign(n, 0);
        for(int i=0;i<n;i++) {
            cin>>numeros[i];
            sum+=numeros[i];
        }
        sort(numeros.begin(), numeros.end());
        ll res = 0;
        for(int i=0;i<n-1;i++) {
            int l = i+1;
            int r = n-1;
            int m = (l + r)/2;
            int rightmost = -1, leftmost = 1e9+10;
            while(l < r) {
                int ans = possible(sum, i, m);
                if (ans == 0) {
                    rightmost = max(rightmost, m);
                    l = m+1;
                } else if (ans == 1) {
                    r = m-1;
                } else {
                    l = m+1;
                }

                m = (l + r)/2;
                if (possible(sum, i, m) == 0) {
                    rightmost = max(rightmost, m);
                }
            }

            // cout<<rightmost<<endl;

            l = i+1;
            r = rightmost;
            m = (l + r)/2;

            while(l < r) {
                int ans = possible(sum, i, m);
                if (ans == 0) {
                    // cout <<"AHAHA"<<endl;
                    leftmost = max(leftmost, m);
                    r = m;
                } else if (ans == 1) {
                    r = m-1;
                } else {
                    l = m+1;
                }

                m = (l + r)/2;
                // cout <<"ZZZ"<< m<<" === "<<possible(sum, i, m)<<endl;
                if (possible(sum, i, m, 1) == 0) {
                    leftmost = min(leftmost, m);
                }
            }

            // cout << leftmost <<" - "<<rightmost<<endl;
            // cout << i<<endl;


            if (rightmost != -1) {
                res+=rightmost - min(leftmost, rightmost) + 1;
            } else if (i == n-2 && possible(sum, i, n-1) == 0 ) {
                res ++;
            } 
        }

        cout << res<<endl;;
    }   
    return 0;
}