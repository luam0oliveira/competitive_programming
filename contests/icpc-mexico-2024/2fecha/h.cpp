// https://codeforces.com/gym/105216/problem/H
// Etruscos (simulação)

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

int main() {
    int n,c,cc;cin>>n>>c>>cc;
    
    --c, --cc;
    vector<int> candidatos;
    for(int i = 0 ;i<n;i++){
        candidatos.push_back(i+1);
    }
    int pc = 0, pcc = n-1;
    vector<int>hired;
    while(candidatos.size() > 2){
        pc = mod(pc+c, candidatos.size());
        pcc = mod(pcc-cc, candidatos.size());
        
        if (pc==pcc){
            hired.push_back(candidatos[pc]);
            candidatos.erase(candidatos.begin() + pc);
            pc = mod(pc, candidatos.size());
            pcc = mod(pcc-1, candidatos.size());
        }else{
            if (pc > pcc){
                candidatos.erase(candidatos.begin() + pc);
                candidatos.erase(candidatos.begin()+pcc);
                pc = mod(pc-1, candidatos.size());
                pcc = mod(pcc-1, candidatos.size());
            }else{
                candidatos.erase(candidatos.begin()+pcc);
                candidatos.erase(candidatos.begin()+pc);
                pcc = mod(pcc-2, candidatos.size());
                pc = mod(pc, candidatos.size());
            }
        }
    }
    for(int i = 0 ;i<candidatos.size();i++){
        hired.push_back(candidatos[i]);
    }
    sort(hired.begin(), hired.end());
    cout<<hired[0];
    for(int i =1;i<hired.size();i++){
        cout<<" "<<hired[i];
    }
    cout<<endl;
}
