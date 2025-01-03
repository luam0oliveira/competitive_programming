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

const int MAXN = 1e5;

int T[2][MAXN*4];
int values[2][MAXN];

void buildMax(int v, int l, int r) {
    if (l == r) {
        T[0][v] = l;
    } else {
        int mid = (l + r)/2;
        buildMax(v*2, l, mid);
        buildMax(v*2+1,min(mid+1,r), r);
        int left = values[0][T[0][v*2]], right = values[0][T[0][v*2 + 1]];
        if (left > right) {
            T[0][v] = T[0][v*2];
        } else {
            T[0][v] = T[0][v*2+1];
        }
    }
}

void buildMin(int v, int l, int r) {
    if (l == r) {
        T[1][v] = l;
    } else {
        int mid = (l + r)/2;
        buildMin(v*2, l, mid);
        buildMin(v*2+1,min(mid+1,r), r);
        int left = values[0][T[1][v*2]], right = values[0][T[1][v*2 + 1]];
        if (left < right) {
            T[1][v] = T[1][v*2];
        } else {
            T[1][v] = T[1][v*2+1];
        }
    }
}

int queryMax(int v, int l, int r, int tl, int tr) {
    if (tl > r || tr < l) return -1;
    if (tl >= l && tr <= r) return T[0][v];
    int mid = (tl + tr)/2;
    int left = queryMax(v*2, l, r, tl, mid), right = queryMax(v*2+1,l,r, min(mid+1,tr),tr);
    if (left == -1) return right;
    if (right == -1) return left;
    if (values[0][left] > values[0][right]) return left;
    return right;
}

int queryMin(int v, int l, int r, int tl, int tr) {
    if (tl > r || tr < l) return -1;
    if (tl >= l && tr <= r) return T[1][v];
    int mid = (tl + tr)/2;
    int left = queryMin(v*2, l, r, tl, mid), right = queryMin(v*2+1,l,r, min(mid+1,tr),tr);
    if (left == -1) return right;
    if (right == -1) return left;
    if (values[1][left] > values[1][right]) return right;
    return left;
}

void updateMax(int v, int idx, int tl, int tr) {
    if (tl > idx || tr < idx) return;
    if (tl == tr && tl == idx) return;
    int mid = (tl + tr)/2;
    if (idx > mid) {
        updateMax(v*2+1, idx, min(mid+1, tr),tr);
    } else {
        updateMax(v*2, idx, tl, mid);
    }
    int left = values[0][T[0][v*2]], right = values[0][T[0][v*2+1]];

    if (left > right) {
        T[0][v] = T[0][v*2]; 
    } else {
        T[0][v] = T[0][v*2+1];
    }
}

void updateMin(int v, int idx, int tl, int tr) {
    if (tl > idx || tr < idx) return;
    if (tl == tr && tl == idx) return;
    int mid = (tl + tr)/2;
    if (idx > mid) {
        updateMin(v*2+1, idx, min(mid+1, tr),tr);
    } else {
        updateMin(v*2, idx, tl, mid);
    }
    int left = values[1][T[1][v*2]], right = values[1][T[1][v*2+1]];
    if (left < right) {
        T[1][v] = T[1][v*2]; 
    } else {
        T[1][v] = T[1][v*2+1];
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++) {
        int a;cin>>a;
        values[0][i] = values[1][i] = a; 
    }

    buildMax(1, 0, n-1);
    buildMin(1, 0, n-1);


    for(int i=0;i<m;i++) {
        int op, a,b;cin>>op>>a>>b;
        if (op == 1) {
            b--;
            if (a > values[0][b]) {
                values[0][b] = a;
                updateMax(1, b, 0, n-1);
            } else if (a < values[1][b]) {
                values[1][b] = a;
                updateMin(1, b, 0, n-1);
            }
        } else {
            a--;b--;
            int menor = queryMin(1, a,b,0,n-1), maior = queryMax(1, a,b,0,n-1);
            if (menor == maior) {
                int nMaior = -1, nMenor = 1e9;
                if (a != maior) {
                    nMaior = max(values[0][queryMax(1, a, max(maior-1, a), 0, n-1)], nMaior);
                    nMenor = min(values[1][queryMin(1, a, max(a,menor-1), 0, n-1)], nMenor);

                }
                if (b != maior) {
                    nMaior = max(values[0][queryMax(1, min(maior+1,b), b, 0, n-1)], nMaior);
                    nMenor = min(values[1][queryMin(1, menor+1, b, 0, n-1)], nMenor);
                }
                int ans = max(nMaior - values[1][menor], values[0][maior] - nMenor);
                cout <<ans<<"\n";
            } else {
                cout << values[0][maior] - values[1][menor]<<"\n";
            }
        }
    }
    return 0;
}