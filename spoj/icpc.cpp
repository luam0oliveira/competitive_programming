// https://br.spoj.com/problems/ICPC/
// Geometria 

#include<bits/stdc++.h>
#define EPS 1e-6
using namespace std;

struct point{
    double x,y;
};

struct circle{
    point p;
    double c;
};

double dist(point a, point b){
    return sqrt(pow(a.y-b.y,2) + pow(a.x-b.x,2));
}

circle controyCircle2p(point& a, point& b){
    double diameter = dist(a,b);
    circle cc = {{(a.x+b.x)/2.0, (a.y+b.y)/2.0},diameter/2.0};
    return cc;
}

bool inCircle(point a, circle c){
    return dist(c.p, a) <= c.c; 
}

bool validCircle(circle &cc, vector<point> R){
    for(point p: R)
        if (!inCircle(p,cc)) return false;
    return true;
}

point get_circle_center(double bx, double by,
                        double cx, double cy)
{
    double B = bx * bx + by * by;
    double C = cx * cx + cy * cy;
    double D = bx * cy - by * cx;
    return { (cy * B - by * C) / (2 * D),
             (bx * C - cx * B) / (2 * D) };
}

circle circle_from(const point& A, const point& B,
                   const point& C)
{
    point I = get_circle_center(B.x - A.x, B.y - A.y,
                                C.x - A.x, C.y - A.y);
 
    I.x += A.x;
    I.y += A.y;
    return { I, dist(I, A) };
}



circle HHBase(vector<point> R){
    if (R.empty()) {
        return { { 0, 0 }, 0 };
    }
    else if (R.size() == 1) {
        return { R[0], 0 };
    }
    else if (R.size() == 2) {
        return controyCircle2p(R[0], R[1]);
    }

    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
 
            circle c = controyCircle2p(R[i], R[j]);
            if (validCircle(c, R))
                return c;
        }
    }
    return circle_from(R[0], R[1], R[2]);
}

circle HH(vector<point> &P, vector<point> R, int n){
    if (n==0 || R.size()==3)
        return HHBase(R);

    int idx = rand() % n;

    point p = P[idx];

    swap(P[idx], P[n-1]);

    circle c = HH(P, R, n-1);

    if (inCircle(p, c))
        return c;
    R.push_back(p);

    return HH(P, R, n-1);
}



int main(){
    int n, cases= 1;
    vector<point> P;
    while(cin>>n && n!=0){
        P.clear();
        for (int i=0;i<n;i++){
            double x,y;cin>>x>>y;
            P.push_back({x,y});
        }
        shuffle(P.begin(), P.end(), default_random_engine{});
        circle mec = HH(P, {}, P.size());

        printf("Instancia %d\n%.2f %.2f %.2f\n\n",cases++, mec.p.x, mec.p.y, mec.c);

    } 
}