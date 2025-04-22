#include<bits/stdc++.h>
#include<bits/extc++.h>
#define ll long long
#define ii pair<int,int>
#define INF 1e9
#define EPS 1e-9
#define ALL(X) X.begin(), X.end()
#define LSOne(S) (S & -(S))
#define ZZZZ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using namespace __gnu_pbds;
// Template to use pbds
template<class T>
using Tree = tree<T, null_type, less<T>,splay_tree_tag, tree_order_statistics_node_update>;
// Template to use pbds
typedef vector<ii> vii;

int mod(int a, int b) {
    return ((a % b) + b)% b;
}

int main() {
    string d; int n;cin>>d>>n;
    int actual;
    if (d == "Mon") actual = 0;
    else if (d == "Tue") actual = 1;
    else if (d == "Wed") actual = 2;
    else if (d == "Thu") actual = 3;
    else if (d == "Fri") actual = 4;
    else if (d == "Sat") actual = 5;
    else if (d == "Sun") actual = 6;
    int ans = 300;


    for(int i=0;i<n;i++) {
        int d;cin>>d;
        if (d == 0) {
            if (actual == 4) {
                ans = min(31, ans);
            } else if (actual == 3) {
                ans = min(32, ans);
            } else {
                ans = min(30, ans);
            }
            continue;
        } else if (d == 30) {
            if (actual == 5) {
                ans = min(2, ans);
            } else if (actual == 6) ans = min(1, ans);
            else {
                ans = min(0,ans);
            }
            continue;
        }
        int init = mod(actual - mod(d, 7), 7); // day of week of start
        if (init % 2) {
            if (init == 1 && d >= 30) init+=2, d-=30;
            if (init == 3 && d >= 30) {
                init = 0;
                d -= 32;
            }
        }

        if (init %2 == 0) {
            d%=91;
        }
        
        while(d > 0) {
            if (init!=4) {
                d-=30;
                init +=2;
            } else {
                d-=31;
                init=0;
            }
        }

        if (init == 5) ans = min(abs(d) + 2, ans);
        else if (init == 6) ans = min(abs(d)+1, ans);
        else ans = min(abs(d), ans);
    }
    cout<<ans<< endl;
    return 0;
}