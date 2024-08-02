// https://br.spoj.com/problems/JANELA13/
// backtracking

#include <bits/stdc++.h>

using namespace std;

int matrix[7][8];
int casos;

vector<pair<int,int>> vizinhos = {
    {1,0}, {0,1}
};
map<pair<int,int>, int> codes;

void generateCodes(){
    int c = 1;
    for(int i =0;i<=6;i++)
        for(int j = i;j<=6;j++)
            codes[{i,j}] = c++;
}

bool impossivel(int x, int y, vector<vector<int>> &visitados){
    return x < 0 || x > 6 || y < 0 || y > 7 || visitados[x][y];
}

void printMatrix(vector<vector<int>> visitados){
    for(int i =0;i<7;i++){
        for(int j=0;j<8;j++)
            printf("%2d ", visitados[i][j]);
    
        cout<<endl;
    }
    cout << "======"<<endl;
}

void solve(int x, int y, vector<vector<int>> &visitados, vector<int> &utilizados, int cont){
    if (cont == 28){
        casos++;
        return;
    }

    if (!visitados[x][y]){
        int nx = x+1, ny = y;
        if (!impossivel(nx,ny, visitados)){
            int cod = codes[{min(matrix[x][y],matrix[nx][ny] ), max(matrix[x][y],matrix[nx][ny])}];
            if (!utilizados[cod-1]){
                utilizados[cod-1] = 1;
                visitados[x][y] = cod;
                visitados[nx][ny] = cod;
                int nextX, nextY;
                for (nextX = x;nextX<7;nextX++){
                    for(nextY = 0;nextY<8;nextY++)
                        if (!impossivel(nextX, nextY, visitados)) break;
                    if (!impossivel(nextX, nextY, visitados)) break;
                }
                solve(nextX, nextY, visitados,utilizados,cont+1);
                visitados[x][y] = 0;
                visitados[nx][ny] = 0;
                utilizados[cod-1] = 0;
            }
        }

        nx = x, ny = y+1;
        if (!impossivel(nx,ny, visitados)){
            int cod = codes[{min(matrix[x][y],matrix[nx][ny]), max(matrix[x][y],matrix[nx][ny] )}];
            if (!utilizados[cod-1]){
                utilizados[cod-1] = 1;
                visitados[x][y] = cod;
                visitados[nx][ny] = cod;

                int nextX, nextY;
                for (nextX = x;nextX<7;nextX++){
                    for(nextY = 0;nextY<8;nextY++)
                        if (!impossivel(nextX, nextY, visitados)) break;
                    if (!impossivel(nextX, nextY, visitados)) break;
                }
                solve(nextX, nextY, visitados,utilizados,cont+1);

                visitados[x][y] = 0;
                visitados[nx][ny] = 0;
                utilizados[cod-1] = 0;
            }
        }
    }
}


int main(){
    generateCodes();
    int t,cases=1;cin>>t;
    while(t--){
        casos=0;
        vector<vector<int>> visitados;
        vector<int> utilizados;
        visitados.assign(7, vector<int>(8, 0));
        utilizados.assign(28, 0);
        for(int i =0;i<7;i++)
            for(int j =0;j<8;j++)
                cin>>matrix[i][j];

        solve(0,0,visitados,utilizados,0);
        printf("Teste %d\n%d\n\n", cases++, casos);
    }

}