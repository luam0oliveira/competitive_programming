#include <bits/stdc++.h>
#define ll int 
#define ZZZZ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

class SegTree{
private:
    int n;
    vector<ll> A, St, Lazy;

    int rl(int p) {return p<<1;}
    int rr(int p) {return (p<<1)+1;}

    
    ll conquer(ll a, ll b) {
        return a+b;
    }

    void build(int i, int l, int r) {
        if(l == r) {
            St[i] = A[l];
        } else {
            int mid = (l+r)/2;
            build(rl(i), l, mid);
            build(rr(i), mid+1, r);
            St[i] = conquer(St[rl(i)], St[rr(i)]);
        }
    }

    void propagate(int i, int l, int r) {
        if (Lazy[i] != -1) {
          St[i] += Lazy[i] * (r - l + 1);
          if (l != r) {
            if (Lazy[rl(i)] == -1) Lazy[rl(i)] = Lazy[i];
            else Lazy[rl(i)] += Lazy[i];

            if (Lazy[rr(i)] == -1) Lazy[rr(i)] = Lazy[i];
            else Lazy[rr(i)] += Lazy[i];
          }
          else { St[l] += Lazy[i]; }
          Lazy[i] = -1;
        }
    }

    ll RSQ(int i, int l, int r, int tl, int tr) {
        propagate(i, tl, tr);
        if (l > tr || r < tl) return 0;
        if ((l <= tl) && (r >= tr)) return St[i];
        int mid = (tl+tr)/2;
        return conquer(RSQ(rl(i), l , r, tl, mid), RSQ(rr(i), l, r, min(tr,mid+1), tr));
    }

    void update(int i, int l, int r, int tl, int tr, int x) {
        propagate(i, tl, tr);
        if (l > tr || r < tl) return;
        if ((l <= tl) && (r >= tr)) {
            Lazy[i] = x;
            propagate(i, tl, tr);
        } else {
            int mid = (tl + tr) / 2;
            update(rl(i), l, r, tl, mid, x);
            update(rr(i), l, r, min(mid+1, tr), tr, x);
            St[i] = St[rl(i)] + St[rr(i)];
        }
    }

public:
    SegTree(int sz): n(sz), St(4*sz), Lazy(4*sz, -1) {}
    SegTree(const vector<ll> &initial):SegTree(initial.size()) {
        A = initial;
        build(1, 0, n-1);
    }

    int solve(int i, int l, int r, int k) {
      // cout << l<<" -- "<<r<<" -- "<<St[i]<< " -- "<<k <<endl;
      if (l == r) {
        St[i]--;
        return r + 1;
      }
      int mid = (l+r)/2;
      int ans = 100;
      if (St[rl(i)] >= k) {
        ans = solve(rl(i), l, mid,k);
      } else {
        ans = solve(rr(i), min(mid+1, r), r, k - St[rl(i)]);
      }
      
      St[i] = St[rl(i)]+ St[rr(i)];
      return ans;
    }

    void update(int i, int j, int val) { update(1,i,j, 0,n-1, val);}
    ll RSQ(int i, int j) { return RSQ(1, i,j,0,n-1);}
};

int main() {
  ZZZZ
  int m;cin>>m;
  vector<int> vec(m,1);
  SegTree S1(vec);
  vector<pair<int,int>> query(m/2), ans(m/2);
  for(int i=0;i<m/2;i++) {
    cin>>query[i].first;
  }

  for(int i=0;i<m/2;i++) {
    cin>>query[i].second;
  }
  for(int i=0;i<m/2;i++) {
    ans[i].first = S1.solve(1, 0, m-1, query[i].first);
    ans[i].second = S1.solve(1, 0, m-1, query[i].second);
  }
  for(auto a: ans) cout <<a.first<<" ";
  cout<<endl;
  for(auto a: ans) cout <<a.second<<" ";
  cout<<endl;
}