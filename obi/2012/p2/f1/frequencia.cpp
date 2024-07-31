// https://olimpiada.ic.unicamp.br/pratique/p2/2012/f1/frequencia/
// Ad-rock

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;scanf("%d ", &n);
    unordered_set<int> alunos;
    for(int i =0;i<n;i++){
        int a;scanf("%d ", &a);
        alunos.insert(a);
    }
    cout<<alunos.size()<<endl;
}
