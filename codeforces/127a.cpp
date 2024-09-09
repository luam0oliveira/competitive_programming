// https://codeforces.com/contest/127/problem/A
// geometria

#include <bits/stdc++.h>

using namespace std;

struct point {
    int x,y;
};

// get the dist of seg
double dist(point &a, point&b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
int n;
point points[110];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;
    cin>>n>>k;

    for(int i = 0 ; i<n;i++){
        int x,y;cin>>x>>y;
        points[i].x = x;
        points[i].y = y;
    }

    double tD = 0;
    for(int i = 1; i < n;i++){
        tD+=dist(points[i], points[i-1]);
    }

    double speed = 50;
    cout<< fixed << setprecision(6)<<(tD*k)/speed<<endl;

    return 0;
}
