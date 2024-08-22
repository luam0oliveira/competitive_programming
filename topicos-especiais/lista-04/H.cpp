// https://vjudge.net/problem/UVA-11413/origin
// Ad-rock

#include <bits/stdc++.h>

using namespace std;

int matriz[200][200];
string rs, mm;

// -1: tipo 0; 1: tipo 1; 0: divide 
int verificaTipo(int xi, int xf, int yi, int yf){
    // 0: zero, 1: um
    int cond[2] = {1,1};
    for(int i = xi; i<xf;i++){
        if (!cond[0] && !cond[1]) break; 
        for(int j=yi;j<yf;j++){
            // cout<<i <<" "<<j<<" "<<matriz[i][j]<<endl;
            if (matriz[i][j]) cond[0] = 0;
            else cond[1] = 0;
        }
    }

    if (cond[0]) return -1;
    else if (cond[1]) return 1;
    return 0;
}

// Corrigir
void divide(int xi, int xf, int yi, int yf){
    int variacaoX = xf-xi;
    int variacaoY = yf-yi;

    int tipo = verificaTipo(xi, xf, yi, yf);

    if (variacaoX <= 2 && variacaoY <= 2){
        if (!tipo){
            rs+='D';
            for(int i = xi;i<xf;i++){
                for(int j=yi;j<yf;j++){
                    rs+=to_string(matriz[i][j]);
                }
            }

        }
        else {
            rs += tipo == 1 ? '1':'0';
        }
        return;
    }

    if (!tipo){
        rs+='D';
        int metadeX = xi+(variacaoX+1)/2;
        int metadeY = yi+(variacaoY+1)/2;
        // Esquerda Superior
        divide(xi,metadeX, yi, metadeY);
        // Direita Superior
        divide(xi,metadeX, metadeY, yf);
        // Esquerda Inferior
        divide(metadeX,xf, yi, metadeY);
        // Direita Inferior
        divide(metadeX,xf, metadeY, yf);
    }else if (tipo == 1)
        rs+='1';
    else
        rs+='0';
}

// void codifica(int pos,int xi, int xf, int yi, int yf){
//     int variacaoX = xf-xi;
//     int variacaoY = yf-yi;

//     if (mm[pos] == 'D'){

//     }
//     if (variacaoX <= 2 && variacaoY <= 2){
//         if (!tipo){
//             rs+='D';
//             for(int i = xi;i<xf;i++){
//                 for(int j=yi;j<yf;j++){
//                     rs+=to_string(matriz[i][j]);
//                 }
//             }

//         }
//         else {
//             rs += tipo == 1 ? '1':'0';
//         }
//         return;
//     }

//     if (!tipo){
//         rs+='D';
//         int metadeX = xi+(variacaoX+1)/2;
//         int metadeY = yi+(variacaoY+1)/2;
//         // Esquerda Superior
//         divide(xi,metadeX, yi, metadeY);
//         // Direita Superior
//         divide(xi,metadeX, metadeY, yf);
//         // Esquerda Inferior
//         divide(metadeX,xf, yi, metadeY);
//         // Direita Inferior
//         divide(metadeX,xf, metadeY, yf);
//     }else if (tipo == 1)
//         rs+='1';
//     else
//         rs+='0';
// }

int main(){
    char op;
    while(cin>>op && op!='#'){
        rs = "";
        int n,m;cin>>n>>m;
        cin>>mm;

    
        if (op == 'B'){
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    matriz[i][j] = mm[m*i + j] == '1';
            divide(0,n,0,m);
            int cont = 0;
            for(int i = 0;i<rs.size();i++){
                cout<<rs[i];
                cont++;
                if (cont%50==0) cout<<endl;
            }
            cout<<endl;
        }else{

        }
    }


}
