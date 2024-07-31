// https://olimpiada.ic.unicamp.br/pratique/p1/2009/f2/olimp/
// Ad-rock

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;scanf("%d %d ", &n, &m);
    vector<pair<int,pair<int,pair<int,int>>>> times(n);

    for (int i =0;i<n;i++){
        times[i] = {0,{0,{0,-i}}};
    }

    for(int i =0;i<m;i++){
        int o,p,b;scanf("%d %d %d ", &o, &p, &b);
        times[--o].first++;
        times[--p].second.first++;
        times[--b].second.second.first++;
    }

    sort(times.begin(), times.end());

    printf("%d", -times[n-1].second.second.second+1);
    for(int i = n-2;i>=0;i--){
        printf(" %d", -times[i].second.second.second+1);
    }
    printf("\n");
}
