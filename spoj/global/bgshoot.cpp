/**
 *     author: demot.r
 *     created: 2024-12-01 00:45:32
 *     source: lazy + compression 
 *     description: 
**/

#include<bits/stdc++.h>
#define ll long long
#define ALL(x) x.begin(), x.end()
using namespace std;

const int MAXN = 2e5;

int tree[4*MAXN];
vector<int> quant;

void build(int v, int l, int r) {
    if (l == r) {
        tree[v] = quant[l];
    } else {
        int mid = (l + r) / 2;
        build(v*2, l, mid);
        build(v*2+1, min(mid+1,r), r);
        tree[v] = max(tree[v*2+1], tree[v*2]);
    }
}

int searchhh(int v, int tl, int tr, int l, int r) {
    if (tl > r || l > tr) return 0;
    if (tl >= l && tr <= r) return tree[v];

    int mid = int(tl + tr)/2;
    return max(searchhh(v*2, tl, mid, l, r), searchhh(v*2+1, min(mid+1, tr), tr, l, r));
}

set<int> times;
unordered_map<int, int> compress;
vector<int> ff;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;cin>>n;
    vector<pair<int,int>> inp;
    for(int i=0;i<n;i++) {
        int l,r;cin>>l>>r;
        inp.push_back({l, r});
        times.insert(l);
        times.insert(r);
    }
    
    int q;cin>>q;
    vector<pair<int,int>> queries(q);
    for(int i=0;i<q;i++) {
        int l,r;cin>>l>>r;
        queries[i] = {l,r};
        times.insert(l);
        times.insert(r);
    }

    int i = 0;

    for(auto c: times) {
        compress[c] = i++;
    }

    quant.assign(times.size(),0);

    for(auto ip: inp) {
        quant[compress[ip.first]]++;
        quant[compress[ip.second]+1]--;
    }

    for(int i = 1; i < quant.size();i++) {
        quant[i]+=quant[i-1];
    }

    // for(auto c: times) {
    //     cout <<c<< " " << compress[c] <<" " << quant[compress[c]] << endl;
    // }
    
    build(1, 0, quant.size()-1);

    for(auto query: queries) {
        cout << searchhh(1, 0, quant.size()-1, compress[query.first], compress[query.second]) << endl;
    }
}

