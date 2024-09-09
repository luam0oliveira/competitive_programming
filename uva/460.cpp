// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=401
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;cin>>t;
    while(t--){
        point ai, af; cin>>ai.x>>ai.y>>af.x>>af.y;
        point bi, bf; cin>>bi.x>>bi.y>>bf.x>>bf.y;

        point inti, intf;
        inti.x = max(ai.x, bi.x); 
        intf.x = min(af.x, bf.x); 
        inti.y = max(ai.y, bi.y); 
        intf.y = min(af.y, bf.y);
        
        if (
                inti.x >= ai.x && inti.x <= af.x && inti.x >= bi.x && inti.x <= bf.x &&
                inti.y >= ai.y && inti.y <= af.y && inti.y >= bi.y && inti.y <= bf.y &&
                intf.x >= ai.x && intf.x <= af.x && intf.x >= bi.x && intf.x <= bf.x &&
                intf.y >= ai.y && intf.y <= af.y && intf.y >= bi.y && intf.y <= bf.y &&
                ai.x != bf.x && af.x != bi.x && ai.y != bf.y && af.y != bi.y
            
        ) cout << inti.x <<" "<<inti.y<<" "<<intf.x<<" "<<intf.y<<endl;
        else cout<<"No Overlap"<<endl;
        if (t) cout<<endl;
    }
    return 0;
}
