/**
 *     author: demot.r
 *     created: 2024-11-30 13:27:47
 *     source: 
 *     description: 
**/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int t;cin>>t;
    while(t--) {
        int n;cin>>n;

        vector<int> ff, pilares[3];
        vector<pair<int,int>> moves;
        for(int i=0;i<n;i++) {
            int a;cin>>a;
            pilares[a].push_back(i);
            ff.push_back(a);
        }
        
        sort(pilares[0].begin(), pilares[0].end());
        sort(pilares[1].begin(), pilares[1].end(), greater<int>());
        sort(pilares[2].begin(), pilares[2].end());

        while(pilares[0][pilares[0].size()-1] > pilares[1][pilares[1].size() - 1]) {
            moves.push_back({pilares[0][pilares[0].size()-1], pilares[1][pilares[1].size() - 1]});
            ff[pilares[0][pilares[0].size()-1]] = 1;
            ff[pilares[1][pilares[1].size()-1]] = 0;
            pilares[0].pop_back();
            pilares[1].pop_back();
        }
        pilares[0].clear();
        pilares[1].clear();
        for(int i=0;i<n;i++) {
            
        }
        


    }


    return 0;
}