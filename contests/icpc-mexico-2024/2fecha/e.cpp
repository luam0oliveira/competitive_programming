// https://codeforces.com/gym/105216/problem/E
// Grafos + guloso

#include<bits/stdc++.h>
#define ll long long
#define MIN(a, b) (a < b) ? a : b
#define MAX(a, b) (a < b) ? b : a
#define EPS 1e-9
#define ZERO(a) ? (abs(a) < EPS) ? 1 : 0
    
using namespace std;


int mod(int a, int b){
    return (a%b + b)%b;
}

const int ln = 1e5 + 1;
const int lln = 1e6 + 1;
pair<int,int> vertices[ln];
pair<int,int>rel [lln];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;cin>>n;
    for(int i = 0;i<n;i++){
        cin>>vertices[i].first;
        vertices[i].second = i;
    }
    sort(vertices, vertices + n);
    int pos = true;
    int cont = 0;
    for(int i = 0;i<n;i++){
        int ai = vertices[i].first-1;
        if (ai > i){
            pos = false;
            break;
        }
        int k = min(i, ai);
        for(int j = 0;j<k;j++){
            if (vertices[j].first > ai){
                pos = false;
                break;
            }
            rel[cont++] = {vertices[i].second+1, vertices[j].second+1};
        }
    }
    if (!pos){
        cout<<-1<<endl;
    }else{
        cout<<cont<<endl;
        for(int i =0;i<cont;i++){
            cout<<rel[i].first<<" "<<rel[i].second<<endl;
        }
    }   
}
