// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1183 
// geometria

#include <bits/stdc++.h>

using namespace std;

struct point {
    double x,y;

    bool operator<(point &o){
        if (o.x == x) return y < o.y;
        return x < o.x;
    }
    bool operator==(point &o){
        return o.x == x && o.y == y;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    point points[4];
    while(cin>>points[0].x>>points[0].y>>points[1].x>>points[1].y>>points[2].x>>points[2].y>>points[3].x>>points[3].y){
        sort(points, points + 4);
        point ans = {0,0};

        for(int i = 1 ; i < 4;i++){
            if (points[i] == points[i-1]) {
                swap(points[i], points[3]);
                points[i-1].x *=-1; 
                points[i-1].y *=-1; 
            }
        }

        for(int i =0;i<3;i++){
            ans.x+=points[i].x;
            ans.y+=points[i].y;
        }
        cout<<fixed<<setprecision(3)<<ans.x<<" "<<ans.y<<endl;
    }
    return 0;
}
