// https://br.spoj.com/problems/PAS11/
// Ad-rock

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> sequencia(n);
    for(int i =0 ;i<n;i++)
        cin>>sequencia[i];
    int razao=0, cont=1;
    bool nova=true;
    for(int i=0;i<n-1;i++){
        if (nova){
            razao =sequencia[i] - sequencia[i+1];
            nova = false;
        }
        if (sequencia[i] - sequencia[i+1] != razao){
            cont++;
            nova=true;
        }
    }
    cout<<cont<<endl;
}