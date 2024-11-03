/**
 *     author: demot.r
 *     created: 2024-11-03 00:03:58
 *     source: 
 *     description: 
**/

#include<bits/stdc++.h>
#define ll long long
#define EPS 1e-8
using namespace std;

double calcY (int a, int b, int c, double x) {
    return (a * x + c)*1.0/-b*1.0;
}

double totalDist(vector<pair<int,int>>&casas, double x, double y) {
    double total = 0;
    for (auto c:casas){
        total += sqrt((c.first - x) * (c.first - x) + (c.second - y) * (c.second - y)); 
    }
    return total;
}


int main() {
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<pair<int,int>> casas(n);
        int a,b,c;cin>>a>>b>>c;
        for (int i=0;i<n;i++) {
            cin>>casas[i].first>>casas[i].second;
        }

        double inicio = -5000, fim = 5000;
        double minimo = 1e16;

        while(inicio <= fim) {
            double m1 = inicio + (fim - inicio) / 3;
            double m2 = fim - (fim - inicio) / 3;

            double r1 = totalDist(casas, m1, calcY(a,b,c,m1));
            double r2 = totalDist(casas, m2, calcY(a,b,c,m2));
            minimo = min({r1,r2,minimo});
            if (r1 > r2) { 
                inicio = m1+EPS;
            } else {
                fim = m2-EPS;
            }
        }
        printf("%.6f\n", minimo);
        // cout<<minimo<<endl;


    }    
    return 0;
}