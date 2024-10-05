/**
 *     author: demot.r
 *     created: 2024-10-05 15:03:03
 *     source: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2041
 *     description: o numero de malas final eh exatamente o maior 
 *                  numero de reperticoes de um numero (greedy)
**/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n;
    int cases = 1;
    while(true){
        cin>>n;
        if (!n) break;
        if (cases != 1)
            cout<<endl;
        vector<int> malas(n);
        vector<vector<int>> lista;
        for(int i =0; i < n;i++) {
            cin>>malas[i];
        }
        sort(malas.begin(), malas.end());

        int count = 1;
        int maior = 1;
        for(int i = 0; i< n-1;i++){
            if(malas[i] == malas[i+1]){
                count++;
            }else{
                count = 1;
            }
            maior = max(maior, count);
        }
        

        lista.assign(maior, {});
        int j = 0;
        for(int i = 0; i < n;i++){
            lista[j].push_back(malas[i]);
            j = (j + 1) % maior;
        }
        cout << lista.size()<<endl;

        for(int i = 0; i < (int) lista.size(); i++){
            cout<<lista[i][0];
            for(j = 1 ; j < (int) lista[i].size();j++){
                cout<<" "<<lista[i][j];
            }
            cout<<endl;
        }
        cases++;
    }

    return 0;
}