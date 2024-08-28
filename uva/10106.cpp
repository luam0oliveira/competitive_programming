// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1047
// Matematica

#include<bits/stdc++.h>
#define ll long long
#define QUAT(x) x*x;
using namespace std;

int main(){
    string a,b;
    while(cin>>a>>b){
        vector<int>resultado(600);
        int sa = a.size(), sb = b.size();
        for(int i=0;i < sa;i++){
            int numberA = a[sa-i-1] - '0';
            for(int j=0;j<sb;j++){
                int numberB = b[sb-j-1] - '0';
                int ff = numberA * numberB;
                resultado[j+i] += ff;
            }
        }
        for(int i =0;i<600;i++){
            int soma = resultado[i] / 10;
            resultado[i] = resultado[i] % 10;
            resultado[i+1] += soma;
        }
        int comeco = true;
        for(int i = 600-1;i>=0;i--){
            if (resultado[i] != 0 || !comeco){
                comeco = false;
                cout<<resultado[i];
            }
        }
        if (comeco) cout<<0;
        cout<<endl;
    }
    return 0;
}
