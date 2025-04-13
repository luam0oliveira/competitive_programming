#include<bits/stdc++.h>
// #include<bits/extc++.h>
#define ll long long
#define ii pair<int,int>
#define INF 1e9
#define EPS 1e-9
#define ALL(X) X.begin(), X.end()
#define LSOne(S) (S & -(S))
#define ZZZZ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
// using namespace __gnu_pbds;
// Template to use pbds
// template<class T>
// using Tree = tree<T, null_type, less<T>,splay_tree_tag, tree_order_statistics_node_update>;
// Template to use pbds
typedef vector<ii> vii;

int main() {
    ZZZZ
    int n,k;cin>>n>>k;
    map<ll, int> mp;
    vector<ll> mm(k+1,0);

    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<std::mt19937::result_type> dist(1,4000000000);

    ll sum = 0;
    for(int i=1;i<k;i++) {
        sum += mm[i] = dist(rng);
    }

    mm[k] = -sum;
    sum = 0;
    mp[0] = -1;
    int ans = 0;
    for(int i=0;i<n;i++) {
        int a;cin>>a;
        sum += mm[a];
        auto it = mp.find(sum);
        if (it == mp.end()) mp[sum] = i;

        ans = max(ans, i - mp[sum]);
    }

    cout << ans << endl;
    



    return 0;
}