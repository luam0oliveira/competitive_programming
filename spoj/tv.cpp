// https://br.spoj.com/problems/TV/
// Ad-rock

#include <bits/stdc++.h>

using namespace std;

vector<int> pai;
vector<int> amm;

int mod(int n, int MOD){
    return ((n%MOD) + MOD) % MOD;
}


int main(){
    int n, m, cases=1;

    while(cin>>n>>m && n!=0 && m!=0){
        int mm[n][m];
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++)
                cin >>mm[i][j];
        }
        int a=1,b=1;
        int distX=0, distY=0;
        while(cin>>a>>b && (a!=0 || b!=0)){
            distY+=b;
            distX-=a;
        }
        cout<<"Teste "<<cases++<<endl;
        for(int i = 0; i<n;i++){
            int ny = mod(distY+i, n);
            for(int j=0;j<m;j++){
                int nx = mod(distX+j, m);
                if (j>0) cout <<" ";
                cout<<mm[ny][nx];
            }
            cout<<endl;
        }
        cout<<endl;

    }

}