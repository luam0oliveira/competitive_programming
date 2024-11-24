/**
 *     author: demot.r
 *     created: 2024-11-23 13:38:24
 *     source: 
 *     description: 
**/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 2e5;

struct Lazy {
    int type = 0;
    ll val = 0;
};

struct Node {
    int l, r;
    ll sum;
    Lazy lazy;
};

Node tree[maxn*4];
int values[maxn];

void build(int v, int l, int r) {
    tree[v].l = l;
    tree[v].r = r;
    tree[v].lazy = {0,0};

    if (l == r) {
        tree[v].sum = values[l]; 
    } else {
        int mid = (l + r) / 2;

        build(v*2, l, min(mid, r));
        build(v*2 + 1, min(mid+1,r), r);
        tree[v].sum = tree[v*2].sum + tree[v*2+1].sum;
    }
}



void ap(int v, const Lazy &l) {
    if (l.type == 1) {
        tree[v].sum = l.val * (tree[v].r - tree[v].l + 1);
        tree[v].lazy = l;
    } else if (l.type == 2) {
        if (tree[v].lazy.type == 1) {
            tree[v].lazy = Lazy{1, tree[v].lazy.val + l.val};
        } else {
            tree[v].lazy = Lazy{2, tree[v].lazy.val + l.val};
        }

        tree[v].sum += l.val * (tree[v].r - tree[v].l + 1);
    }
}

void push_down(int v) {
    ap(2*v, tree[v].lazy);
    ap(2*v+1, tree[v].lazy);
    tree[v].lazy = Lazy();
}

void update(int v, int l, int r, ll x, int op) {
    if (r < tree[v].l || tree[v].r < l) {
        return;
    }

    if (tree[v].l >= l && r >= tree[v].r) {
        Lazy l = {op, x};
        ap(v, l);
    } else {
        push_down(v);
        update(v*2, l, r, x, op);
        update(v*2+1, l, r, x, op);
        tree[v].sum = tree[v*2].sum + tree[v*2+1].sum;
    }

}


ll query(int v, int l, int r) {
    // propagate(v);

    if (r < tree[v].l || tree[v].r < l) {
        return 0;
    }


    if (tree[v].l >= l && r >= tree[v].r) {
        return tree[v].sum;
    }

    push_down(v);
    ll s1 = query(v*2, l, r);
    ll s2 = query(v*2+1, l, r);

    return  s1 + s2;
}

int main() {
    int n, m;cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>values[i];
    }
    build(1, 0, n-1);

    for(int i=0;i<m;i++){
        int op, l, r;
        cin>>op>>l>>r;
        if (op == 3) {
            // break;
            cout<<query(1,l-1, r-1)<<endl;
        } else {
            int x;cin>>x;
            update(1, l-1, r-1, x, op%2 + 1);
        }
        // if (i == 3) break;
    }
    return 0;
}