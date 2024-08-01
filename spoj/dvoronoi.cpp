// https://br.spoj.com/problems/DVORONOI/
// matematica

#include <bits/stdc++.h>

using namespace std;

struct point{
    int x,y,z;
};

point toVec(point &p0, point &p1){
    return {p1.x - p0.x, p1.y - p0.y, p1.z - p0.z};
}

double det3(point &p1,point &p2,point &p3){
    return p1.x * p2.y * p3.z + p1.y * p2.z * p3.x + p1.z * p2.x * p3.y - (p1.z * p2.y * p3.x + p1.y * p2.x * p3.z + p1.x * p2.z * p3.y);
}


int main(){
    int t; cin>>t;
    while(t--){
        vector<point> pontos(4);
        vector<point> vec(3);
        for(int i=0; i<4;i++)
            cin>>pontos[i].x>>pontos[i].y>>pontos[i].z;
        for(int i=0; i<3;i++)
            vec[i] = toVec(pontos[0], pontos[i+1]);
        
        printf("%.6f\n",abs(det3(vec[0],vec[1],vec[2]))/6);  
    }
}
