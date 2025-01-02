#include<bits/stdc++.h>
#include<bits/extc++.h>
#define ll long long
#define ii pair<int,int>
#define INF 1e9
#define EPS 1e-9
#define ALL(X) X.begin(), X.end()
#define LSOne(S) (S & -(S))
using namespace std;
using namespace __gnu_pbds;
// Template to use pbds
template<class T>
using Tree = tree<T, null_type, less<T>,splay_tree_tag, tree_order_statistics_node_update>;
// Template to use pbds
typedef vector<ii> vii;
typedef vector<ll> vll;

vll rq;

ll find(int i) {
    ll sum = 0;
    for(;i>0;i-=LSOne(i)) sum+= rq[i];
    return sum;
}

void build(vll& base){
    for(int i = 1; i <=base.size();i++) {
        rq[i] += base[i-1];
        if (i + LSOne(i) < rq.size()) rq[i+LSOne(i)] += rq[i];        
    }
}

ll query(int i, int j) {
    return find(j) - find(i-1);
}

void update(int i, int x) {
    for(;i<rq.size();i+=LSOne(i)) rq[i] += x;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int cases=1;
    while(1){
        int n;cin>>n;
        if(!n) break;
        if (cases!=1) cout<<endl;
        rq.assign(n+1,0);
        vll base(n);
        for(int i=0;i<n;i++) cin>>base[i];
        build(base);
        cout<<"Case "<<cases++<<":\n";
        while(1) {
            string op;cin>>op;
            if(op =="END") break;
            int a,b;cin>>a>>b;
            if (op=="S"){
                update(a, b - query(a,a));
            } else {
                cout <<query(a,b)<<endl;
            }
        }

    }
    return 0;
}