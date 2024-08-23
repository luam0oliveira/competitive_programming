// https://vjudge.net/problem/UVA-11413/origin
// Ad-rock

#include <bits/stdc++.h>

using namespace std;

int matriz[200][200];
string rs, mm;
int aler;

// -1: tipo 0; 1: tipo 1; 0: divide 
int verificaTipo(int xi, int xf, int yi, int yf){
    // 0: zero, 1: um
    int cond[2] = {1,1};
    for(int i = xi; i<=xf;i++){
        if (!cond[0] && !cond[1]) break; 
        for(int j=yi;j<=yf;j++){
            if (matriz[i][j]) cond[0] = 0;
            else cond[1] = 0;
        }
    }

    if (cond[0]) return -1;
    else if (cond[1]) return 1;
    return 0;
}

void divide(int xi, int xf, int yi, int yf){
    if (xi > xf || yi > yf) return;
    int tipo = verificaTipo(xi, xf, yi, yf);
    if (tipo!=0){
        rs += tipo == 1 ? '1':'0';
        return;
    }
    rs+='D';
    if (xf-xi+1 <= 2 && yf-yi + 1 <= 2){
        for(int i = xi; i<=xf;i++)
            for(int j = yi;j<=yf;j++)
                rs+= to_string(matriz[i][j]);
        return;
    }
    int xFim = (xf-xi)/2;
    int yFim = (yf-yi)/2;
    divide(xi, xi + xFim, yi, yi + yFim);
    divide(xi, xi + xFim, yi + yFim + 1, yf);
    divide(xi + xFim+1, xf, yi, yi + yFim);
    divide(xi + xFim+1, xf, yi + yFim + 1, yf);
}

void unify(int xi, int xf, int yi, int yf){
    if (xi > xf || yi > yf) return;
    if(mm[aler] == 'D'){
        aler++;
        int xFim = (xf-xi)/2;
        int yFim = (yf-yi)/2;
        if (xf-xi+1 <= 2 && yf-yi + 1 <= 2){
            for(int i=xi;i<=xf;i++)
                for(int j=yi;j<=yf;j++)
                    unify(i, i,j, j);
        }else{
            unify(xi, xi + xFim, yi, yi + yFim);
            unify(xi, xi + xFim, yi + yFim + 1, yf);
            unify(xi+xFim+1, xf, yi, yi + yFim);
            unify(xi+xFim+1, xf, yi + yFim + 1, yf);
        }
        return;
    }
    for(int i=xi;i<=xf;i++)
        for(int j=yi;j<=yf;j++)
            matriz[i][j] = mm[aler]=='1';
        
    aler++;
}

int main(){
    string op;
    while(cin>>op && op!="#"){
        rs = "";
        aler=0;
        int n,m;cin>>n>>m;

        if (op == "B"){
            string ff;
            int cont=0;
            while(n*m != cont){
                cin>>mm;
                ff+=mm;
                cont+=mm.size();
            }

            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    matriz[i][j] = ff[m*i + j] == '1';
            divide(0,n-1,0,m-1);
            cont = 0;
            printf("D%4d%4d\n", n,m);
            for(int i = 0;i<rs.size();i++){
                cout<<rs[i];
                cont++;
                if (cont%50==0) cout<<endl;
            }
            if (cont%50) cout<<endl;
        }else{
            cin>>mm;
            unify( 0, n-1, 0, m-1);
            int cont=0;
            printf("B%4d%4d\n", n,m);
            for(int i = 0;i<n;i++){
                for(int j=0;j<m;j++){
                    cout<<matriz[i][j];
                    cont++;
                    if (cont%50==0) cout<<endl;
                }
            }
            if (cont%50) cout<<endl;
        }
    }
}
