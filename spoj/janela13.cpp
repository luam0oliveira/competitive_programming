// https://br.spoj.com/problems/JANELA13/
// ad-rock

#include <bits/stdc++.h>

using namespace std;

bool ocupado[600];

int main(){
    int a,b,c;cin>>a>>b>>c;
    for(int i =0;i<200;i++)
        ocupado[a+i] = true;

    for(int i =0;i<200;i++)
        ocupado[b+i] = true;

    for(int i =0;i<200;i++)
        ocupado[c+i] = true;
    int cont=600;
    for(int i=0;i<600;i++)
        if (ocupado[i]) cont--;
    cout<<cont*100<<endl;

}