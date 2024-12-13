#include <bits/stdc++.h>
#define ll long long
const int maxn = 3e5;

using namespace std;

struct Node{
    ll l, r;
    ll opt, actual;
    ll lazy;
};

int values[maxn];
Node tree[4*maxn];

void build(int v, int l, int r) {
    tree[v].l = l;
    tree[v].r = r;
    tree[v].lazy = 0;
    if (l == r) {
        tree[v].opt = tree[v].actual = values[l];
    }else{
        int mid = (l + r) /2;
        
        build(v*2, l, min(mid,r));
        build(v*2+1, min(mid + 1,r), r);

        tree[v].actual = tree[v].opt = tree[v*2].actual + tree[v*2+1].actual;
    }
}

void ap(int v, ll x) {
    tree[v].lazy += x;
    tree[v].actual += x * (tree[v].r - tree[v].l + 1);
    tree[v].opt = max (tree[v].actual, tree[v].opt);
}

void push_down(int v) {
    ap(v*2,tree[v].lazy);
    ap(v*2+1,tree[v].lazy);
    tree[v].lazy = 0;
}


ll find(int v, int l, int r) {
    if (tree[v].l > r || tree[v].r < l) return 0;
    if (tree[v].l >= l && tree[v].r <= r) return tree[v].actual;    
    push_down(v);
    return find(v*2, l, r) + find(v*2+1, l, r);
}

void update(int v, int l, int r, ll x) {
    if (tree[v].l > r || tree[v].r < l) return;
    if (tree[v].l >= l && tree[v].r <= r) {
        ap(v, x);
    } else{
        push_down(v);
        update(v*2, l, r, x);
        update(v*2+1, l, r, x);
        tree[v].actual = tree[v*2].actual + tree[v*2+1].actual;
        tree[v].opt = max(tree[v].actual, tree[v].opt);
    }
}


int main() {
    int n, m;cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>values[i];
    }
    
    build(1, 0, n-1);

    
    for(int i =0;i<m;i++) {
        int op, l,r; cin>>op>>l>>r;
        l--;
        r--;
        if (op == 1) {
            ll x;cin>>x;
            update(1, l, r, x);            
        } else {
            cout << find(1, l, r)<<endl;
        }
    }

    for(int j =0;j<n;j++) {
        // cout<< find(1, j, j)<<endl;
    }


}