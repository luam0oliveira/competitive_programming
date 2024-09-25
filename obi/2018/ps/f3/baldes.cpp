/**
 *     author: demot.r
 *     created: 2024-09-24 17:17:29
 *     source: https://olimpiada.ic.unicamp.br/pratique/ps/2018/f3/baldes/
 *     description: segment tree
**/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 1e5+1;

pair<int,int> nums[maxn];
int t[2][maxn];

void build(int v, int l, int r) {
    if (l == r) {
        // cout<<"AHSDUHASD "<<l<<endl;
        t[0][v] = l;
        t[1][v] = l;
        return;
    }

    int mid = l + (r-l)/2;

    build(2*v, l, mid);
    build(2*v+1,mid+1, r);
    

    cout <<nums[t[0][2*v]].first<<" "<<nums[t[0][2*v+1]].first<<endl;
    t[0][v] = nums[t[0][2*v]].first < nums[t[0][2*v+1]].first ? t[0][2*v] : t[0][2*v+1];
    t[1][v] = nums[t[1][2*v]].second > nums[t[1][2*v+1]].second ? t[1][2*v] : t[1][2*v+1];
}

pair<int,int> search(int v, int l, int r, int tl, int tr) {
    if (l <= tl && r >= tr) return {t[0][v], t[1][v]};
    if (l > tr || r < tl) return {-1,-1};

    int mid = tl + (tr - tl) / 2;
    
    pair<int,int> par = {-1,-1};

    pair<int,int> pl, pr;

    pl = search(v*2, l, r, tl, mid);
    pr = search(v*2+1, l,r, mid+1, tr);


    if (pl.first != -1) {
        par.first = pl.first;
    }

    if (pl.second != -1) {
        par.second = pl.second;
    }

    if (pr.first != -1 && (par.first == -1 || nums[pr.first].first < nums[par.first].first)){
        par.first = pr.first;
    }

    if (pr.second != -1 && (par.second == -1 || nums[pr.second].second > nums[par.second].second)){
        par.second = pr.second;
    }

    cout<<par.first<<" "<<par.second<<endl;

    return par;
}

int main(){
    int n, m;cin>>n>>m;
    for(int i =0;i<n;i++){
        int a;
        cin>>a;
        nums[i].first = nums[i].second = a;
    }
    build(1, 0, n-1);

    // for(int i = 0 ; i < n*4;i++){
    //     cout<<t[0][i] << " "<<t[1][i]<<endl;
    // }
    // cout<<"AGDYASGDYAS"<<endl;
    for(int i =0;i<m;i++){
        int op, l, r;cin>>op>>l>>r;
        if (op == 2){
            pair<int,int> par = search(1, l-1, r-1, 0, n-1);

            cout << par.first <<" - " << par.second<<endl;
        }
    }

    return 0;
}