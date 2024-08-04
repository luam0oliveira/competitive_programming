#include<bits/stdc++.h>
#define ll long long
#define MIN(a, b) (a < b) ? a : b
#define MAX(a, b) (a < b) ? b : a
#define EPS 1e-9
#define ZERO(a) ? (abs(a) < EPS) ? 1 : 0
    
using namespace std;
    
int main() {
    int n,m;cin>>n>>m;
    vector<int> E(n);
    priority_queue<pair<int,int>>pq;
    for(int i = 0;i<n;i++){
        int a;cin >>a;
        pq.push({a,i});
    }
    while(m--){
        int a; cin >> a;
        while(pq.top().first >= a){
            pair<int,int> nv = pq.top(); pq.pop();
            nv.first = nv.first%a;
            pq.push(nv);
        }
    }
    while(!pq.empty()){
        pair<int,int> top = pq.top(); pq.pop();
        E[top.second] = top.first;
    }
    cout<<E[0];
    for(int i =1;i<E.size();i++){
        cout <<" "<<E[i];
    }
    cout<<endl;
}
