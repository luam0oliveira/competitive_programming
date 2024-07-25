// https://br.spoj.com/problems/FLIPERAM/
// Ad-rock

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m,a;cin>>n>>m;
    vector<int> points;
    while(n--){
        cin>>a;
        points.push_back(a);
    }

    sort(points.begin(), points.end());
    for(int i =0;i<m;i++){
        cout<<points[points.size()-1-i]<<endl;
    }

}