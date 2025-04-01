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

vector<int> get_pot(ll n) {
    vector<int> pot;
    for(ll i=2;i*i<=n;i++) {
        int count = 0;
        while(n%i == 0) {
            count++;
            n/=i;
        }
        if(count) pot.push_back(count);
    }

    if (n > 1) pot.push_back(1);
    return pot;
}

int main() {
    ll n = 1e12;
    cin>>n;
    auto pot = get_pot(n);
    if (pot.size() > 2) cout <<"N" <<endl;
    else if (pot.size() == 1 && (pot[0] % 2)) cout <<"Y" << endl;
    else if (pot.size() == 2 && pot[0] == 1 && pot[1] == 1) cout <<"Y" <<endl;
    else cout << "N" << endl;
    return 0;
}