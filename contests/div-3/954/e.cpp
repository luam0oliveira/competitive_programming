#include <bits/stdc++.h>
#define ll long long

using namespace std;

int solve() {
    int n, d; cin>>n>>d;
    map<int, vector<int>> aux;
    for(int i = 0; i < n;i++) {
        int a;cin>>a;
        aux[a%d].push_back(a);
    }
        
    int solitarios = 0;
    ll sum = 0;
    for(auto it = aux.begin(); it != aux.end(); it++) {
        auto v = it->second;
        solitarios += v.size() & 1;
        if (solitarios > 1) return -1;
        sort(v.begin(), v.end());
        if (v.size() > 1) {
            if (v.size() & 1) {
                vector<int> a1;
                vector<int> a2;
                ll ss = 0;
                for(int i = 1; i < (int)v.size();i+=2) {
                    a1.push_back(v[i] - v[i-1]);
                }
                for(int i = 2; i < (int) v.size();i+=2) {
                    a2.push_back(v[i] - v[i-1]);
                    ss += a2[i/2-1];
                }
                ll minn = ss;
                for(int i = 2; i < (int)v.size(); i+=2) {
                    ss+=a1[(i/2)-1] - a2[(i/2)-1];
                    minn = min(ss, minn);
                }
                sum+=minn;
            } else {
                for(int i = 0; i < (int) v.size();i+=2) {
                    sum += v[i+1] - v[i];
                }
            }
        }
    }
    
    return sum/d;
}

int main(){
    int t;cin>>t;
    while(t--){
        cout << solve()<<endl;
    }
    return 0;
}
