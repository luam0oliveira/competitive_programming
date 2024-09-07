// https://codeforces.com/contest/43/problem/A
// ad-rock

#include<bits/stdc++.h>
#define ll long long
#define QUAT(x) x*x;
using namespace std;

map<string,int> score;

int main(){
    int n;cin>>n;
    int maior = 0;
    string mmaior = "0";
    for(int i = 0; i < n; i++) {
        string name; cin>>name;
        score[name]++;
        if (maior < score[name]){
            maior = score[name];
            mmaior = name;
        }
    }
    cout<<mmaior<<endl;
}
