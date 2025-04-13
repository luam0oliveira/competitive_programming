#include<bits/stdc++.h>
#include<bits/extc++.h>
#define ll long long
#define ld double
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
const int maxn = 1e5;

pair<ld,int> pos[2*maxn+1];
ld source[maxn+1];
pair<ld,ld> All[maxn+1], Bll[maxn+1];

int main() {
    ZZZZ
    int n;cin>>n;
    ld A =0, B = 0;
    int j = 0;
    for(int i=0;i<n;++i) {
        int a,b,c,d;cin>>a>>b>>c>>d;
        A += a*b;
        B += c*d;
        All[i] = {a,b};
        Bll[i] = {c,d};
        source[i] = b+d; // how much they need to produce
        if (c > a) {
            pos[i] = {(ld)a/(ld)c, (i+1)};
        } else {
            pos[i] = {(ld)c/(ld)a, -(i+1)};
        }
    }

    sort(pos, pos+n);
    ld ans = 0;

    for(int i=0;i<n;++i) {
        int idx = pos[i].second;
        if (source[abs(idx)-1] > 0) {
            if (idx > 0) {
                idx--;
                auto ab = All[idx];
                ld a = source[idx];
                a = min(a, A/ab.first);
                source[idx]-=a;
                ans += a * ab.first;
                A-=a *ab.first;
                if (source[idx]) {
                    ab = Bll[idx];
                    a = source[idx];
                    a = min(a, B/(ab.first));
                    source[idx]-=a;
                    ans += a * ab.first;
                    B-=a*ab.first;
                }
            } else {
                idx=-idx - 1;
                auto ab = Bll[idx];
                ld a = source[idx];
                ld can = (B/ab.first);
                a = min(a, can);
                source[idx]-=a;
                ans += a * ab.first;
                B-=a * ab.first;
                if (source[idx]) {
                    ab = All[idx];
                    a = source[idx];
                    ld can = (A/(ab.first));
                    a = min(a, can);
                    source[idx]-=a;
                    ans += a * ab.first;
                    A-=a*ab.first;
                }
            }
        }
    }

    printf("%.15f\n", ans);
    return 0;
}