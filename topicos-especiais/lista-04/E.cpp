// https://vjudge.net/problem/UVA-11413/origin
// Divisao e conquista - Busca binaria pela resposta correta/minimizacao da lat
// eral esquerda

#include <bits/stdc++.h>

using namespace std;


vector<int> vessels;
int n,q,minimo;

bool possible(int attempt){
    int quantAt = 0;
    int cont = 0;
    if (attempt < minimo) return false;
    for(int i = 0;i<n;i++){
        if (quantAt + vessels[i] > attempt){
            cont++;
            quantAt=vessels[i];
        }else if (quantAt + vessels[i] == attempt){
            cont++;
            quantAt=0;
        }else{
            quantAt+=vessels[i];
        }

        if (q < cont) return false;
    }
    return (q == cont && quantAt == 0) || (q > cont);
}

int binary_search(int left, int right){
    while(!(possible(left) && !possible(left-1))){
        int mid = left + (right - left)/2;
        if (possible(mid)){
            right = mid-1;
        }else{
            left = mid+1;
        }
        // cout<<"MIN == "<<minimo<<endl;
    }
    // cout<<"ESquerdinha "<<left<<endl;
    return left;
}

int main(){
    while(cin>>n>>q){
        vessels.clear();
        minimo = 0;
        for(int i=0;i<n;i++){
            int a;cin>>a;
            minimo = max(minimo, a);
            vessels.push_back(a);
        }
        cout<<binary_search(minimo, 1e9)<<endl;
    }
}
