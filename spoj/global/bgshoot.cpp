/**
 *     author: demot.r
 *     created: 2024-12-01 00:45:32
 *     source: lazy + compression 
 *     description: 
**/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxN = 3e5;

vector<int> points;
vector<pair<int,int>> valuePoints;

struct Node {
    int l, r, max, before;
};

Node tree[maxN*4];

void build(int v, int l, int r) {
    tree[v].l = l;
    tree[v].r = r;
    if (l == r) {
        tree[v].max = valuePoints[l].first;
        tree[v].before = valuePoints[l].second;
    } else {
        int middle = (l + r) / 2;
        build(v*2, l, min(middle, r));
        build(v*2 + 1, min(middle + 1, r), r);
        tree[v].max = max(tree[v*2].max, tree[v*2+1].max);
    }
}

int find(int v, int l, int r) {
    int left = points[tree[v].l], right = points[tree[v].r];
    if (left > r || right < l) return -1;

    if (left >= l && right <= r) return tree[v].max;

    int mm = max(find(v*2, l, r), find(v*2+1, l, r));

    if (tree[v].r - tree[v].l == 1 && mm == -1) {
        return tree[v*2+1].before;
    }
    return mm;
}

// entrada = first > 0, saida = first < 0
unordered_map<int, pair<int,int>> input;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;cin>>n;
    vector<int> filter;
    for(int i=0;i<n;i++) {
        int a,b;cin>>a>>b;
        input[a].first++;
        input[b].second++;
        filter.push_back(a);
        filter.push_back(b);
    }

    sort(filter.begin(), filter.end());

    for(int i=1;i<filter.size();i++) {
        if (filter[i] != filter[i-1]) {
            points.push_back(filter[i-1]);
        }
    }

    if (filter[filter.size()-2] != filter[filter.size()-1]) points.push_back(filter[filter.size()-1]);

    
    valuePoints.push_back({input[points[0]].first, 0});
    for(int i=1;i<points.size();i++){
        int value = input[points[i]].first - input[points[i-1]].second + valuePoints[i-1].first; 
        valuePoints.push_back({value, value - input[points[i]].first});
    }


    build(1, 0, points.size()-1);

    int m;cin>>m;
    for(int i=0;i<m;i++){
        int l,r;cin>>l>>r;
        cout << max(0, find(1, l, r))<<endl;
    }

    return 0;
}