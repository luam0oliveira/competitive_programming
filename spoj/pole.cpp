#include<bits/stdc++.h>
using namespace std;


struct point{
    int x,y, altura, same;
};
// as vector
int cross(point a, point b){
    return a.x * b.y - b.x*a.y;
}

point toVec(point& a, point& b){
    return {a.x - b.x, a.y - b.y, a.altura};
}

double derivada (double x, double y){
    if (x == 0)
        return -100000;
    return (y/x);
}

int quadrante(point & p){
    if (p.x >= 0 && p.y > 0) return 1;
    else if (p.x < 0 && p.y >= 0) return 2;
    else if (p.x <= 0 && p.y < 0) return 3;
    else return 4;
}

int main(){
    int n, cases = 1;
    while(cin>>n && n!=0){
        
        vector<vector<pair<double,point>>> points(4);
        for(int i =0;i<n;i++){
            point a;
            cin >>a.x>>a.y>>a.altura;
            points[quadrante(a)-1].push_back({derivada(a.x,a.y), a});
        }

        vector<point> naoVisto;
        sort(points[0].begin(),points[0].end(),[] (pair<double,point> a, pair<double,point> b){
            if (a.first == b.first) return (a.second.x < b.second.x) || (a.second.x == b.second.x && a.second.y < b.second.y);
            return a.first < b.first;
        });
        sort(points[1].begin(),points[1].end(),[] (pair<double,point> a, pair<double,point> b){
            if (a.first == b.first) return (a.second.x > b.second.x) || (a.second.x == b.second.x && a.second.y < b.second.y);
            return a.first < b.first;
        });
        sort(points[2].begin(),points[2].end(),[] (pair<double,point> a, pair<double,point> b){
            if (a.first == b.first) return (a.second.x > b.second.x) || (a.second.x == b.second.x && a.second.y > b.second.y);
            return a.first < b.first;
        });
        sort(points[3].begin(),points[3].end(),[] (pair<double,point> a, pair<double,point> b){
            if (a.first == b.first) return (a.second.x < b.second.x) || (a.second.x == b.second.x && a.second.y > b.second.y);
            return a.first < b.first;
        });
        for (int i =0;i<4;i++){
            int alturaMin = 0;
            if (points[i].size()) alturaMin = points[i][0].second.altura;
            for(int j=0; j < (int)points[i].size()-1;j++){
                if (points[i][j].first == points[i][j+1].first){
                    if (points[i][j+1].second.altura <= alturaMin)
                        naoVisto.push_back(points[i][j+1].second);
                    alturaMin = max(alturaMin, points[i][j+1].second.altura);
                }else{
                    alturaMin = points[i][j+1].second.altura;
                }
            }
        }


        sort(naoVisto.begin(), naoVisto.end(), [] (point& a, point& b){
            return a.x < b.x || (a.x == b.x && a.y < b.y);
        });
        cout<<"Data set "<<cases++<<":"<<endl;

        if (naoVisto.size() == 0)
            cout<<"All the lights are visible."<<endl;
        else{
            cout<<"Some lights are not visible:"<<endl;
            for( int i =0;i<naoVisto.size()-1;i++)
                cout<<"x = "<< naoVisto[i].x <<", y = " << naoVisto[i].y<<";"<<endl;
            cout<<"x = "<< naoVisto[naoVisto.size()-1].x <<", y = " << naoVisto[naoVisto.size()-1].y<<"."<<endl;
        }

        
    }

}