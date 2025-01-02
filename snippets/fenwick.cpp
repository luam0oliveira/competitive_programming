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
typedef vector<int> vi;
typedef vector<ll> vll;

// 1 index based (classic PURQ)
class BIT {
    private:
        vll rq;
        int maxSize;
    public:
        BIT (int size = 1) {
            maxSize = size+1;
            rq.assign(maxSize, 0);
        }

        void build(vll& base) {
            for(int i=1;i<=base.size();i++) {
                rq[i] += base[i-1];
                if (i + LSOne(i) < maxSize) rq[i + LSOne(i)] += rq[i]; 
            }
        }


        ll find(int i) {
            ll sum = 0;
            for(;i > 0;i-=LSOne(i)) sum += rq[i];
            return sum;
        }

        ll find(int i, int j) {return find(j) - find(i - 1);}

        void update(int i, ll x) {for(;i < maxSize;i+=LSOne(i)) rq[i]+=x;}

        // I think we can search first to nodes with base2-index
        ll select(ll k) {
            int lo = 1, hi = rq.size()-1; 
            
            for(int i =0;i<30;i++) {
                int mid = (lo + hi)/2;
                (find(mid) < k) ? lo = mid: hi = mid;   
            }
            return hi;
        }
        
        // from chatgpt (I dont know exactly whats the chatgpts source)
        ll select_m(ll k) {
            int bit = 1;
            while (bit <= maxSize) bit<<=1;
            bit>>=1;

            int index = 0;
            ll current_sum = 0;

            while(bit > 0) {
                int next_index = index + bit;
                cout << current_sum<< " - " << next_index <<" - " << rq[next_index]<<endl;
                if (next_index < maxSize && current_sum+rq[next_index] < k) {
                    current_sum+=rq[next_index];
                    index = next_index;
                }
                bit>>=1;
            }

            return index+1;
        }
};

class BITRUPQ {
    private:
        BIT ft;
    public:
        BITRUPQ(int size = 1e6) {
            ft = BIT(size);
        }

        void range_update(int i, int j, ll x) {
            ft.update(i, x);
            ft.update(j+1, -x);
        }

        ll point_query(int i) {return ft.find(i);}
};

class BITRURQ {
    private:
        BIT rq;
        BITRUPQ ru;
    public:
        BITRURQ(int size = 1e6) {
            ru = BITRUPQ(size);
            rq = BIT(size);
        }

        void update(int i, int j, ll x) {
            ru.range_update(i, j, x);
            rq.update(i, x * (i-1));
            rq.update(j+1, x*(-j));
        }

        ll query(int i) {return ru.point_query(i) * i - rq.find(i);}

        ll query_range(int i, int j) {return query(j) - query(i-1);}
};

vll rq;
vll ru;
// get sum in the range [1,j]
ll find(int i, vll& ft) {
    ll sum = 0;
    for(;i;i-=LSOne(i)) sum+=ft[i];
    return sum;
}

// get sum in the range [i,j]
ll find(int i, int j, vll& ft) {
    return find(j, ft) - find(i-1, ft);
}

void update(int i, ll x, vll& ft) {
    for(;i<ft.size();i+=LSOne(i)) 
        ft[i]+=x;
}

void range_update(int i, int j, ll x, vll& ft) {
    update(i, x, ft);
    update(j+1, -x, ft);
}

// // 1-based
ll query(int i, int j, vll&ru, vll&rq) {
    ll ans = find(j, ru) * j - find(j, rq) - (find(i-1, ru) * (i-1) - find(i-1, rq));
    return ans;
}

int main() {
    int n,m;cin>>n>>m;
    vll base(n);
    BIT bit(n);
    // BITRURQ bit(n);
    // ru.assign(n+1, 0);
    // rq.assign(n+1,0);

    for(ll i=0;i<n;i++) {
        ll a;cin>>a;
        base[i] = a;
        // ll idx = i+1;
        // bit.update(idx, idx,a);
        // range_update(idx,idx,a, ru);
        // update(idx, i * (a), rq);
        // update(idx+1, idx*(-a), rq);   
    }

    bit.build(base);

    // cout<<"AHHAH"<<bit.find(3)<<endl;
    
    for(int i=0;i<m;i++) {
        int op; cin>>op;
        cout<<bit.select_m(op)<<endl;
        // ll a,b;cin>>a>>b;
        // if (op == 1) {

            // bit.update(a, a, b - bit.query_range(a,a));
            // ll toUpdate = b - find(a, ru);
            // range_update(a, a, toUpdate, ru);
            // update(a, toUpdate*(a-1), rq);
            // update(a+1, toUpdate*(-a), rq);
        // } else if (op == 2){
            // cout << bit.query_range(a,b)<<endl;
            // cout<<query(a,b, ru, rq)<<endl;
        // }
    }
    
    return 0;
}