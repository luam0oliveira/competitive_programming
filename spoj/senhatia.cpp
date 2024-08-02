// https://br.spoj.com/problems/SENHATIA/
// ad-rock

#include <bits/stdc++.h>

using namespace std;

bool verifica(int n,int m, int a, int k, string senha){
    if (senha.size() < n) return false;
    int req[3] = {0,0,0};

    for(int i=0;i<senha.size();i++){
        if(senha[i] - 'A' >=0 && senha[i] - 'A' <=25) req[1]++;
        else if(senha[i] - 'a' >=0 && senha[i] - 'a' <=25) req[0]++;
        else if(senha[i] - '0' >=0 && senha[i] - '0'<=10)req[2]++;
    }

    return req[0] >=m && req[1]>=a && req[2]>=k;
}

int main(){
    int N, M, A, K ;cin>>N>>M>>A>>K;
    string senha;cin>>senha;

    if (!verifica(N,M,A,K,senha)) cout<<"Ufa :)"<<endl; else cout<<"Ok =/"<<endl;
}