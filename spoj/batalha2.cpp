// https://br.spoj.com/problems/BATALHA2/
// Flood-fill

#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> matrix;
vector<vector<bool>> visitados;

vector<pair<int,int>> vizinhos = {
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
};

void dfs(int x, int y, int n, int m, vector<pair<int,int>> &barco){
    visitados[x][y] = true;
    barco.push_back({x,y});

    for(pair<int,int> vizinho: vizinhos){
        int nx = vizinho.first + x, ny = vizinho.second + y;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || visitados[nx][ny] || matrix[nx][ny] != '#')
            continue;
        dfs(nx, ny, n, m, barco);
    }
}

int main(){
    int n,m,l,c,a,cont = 0;
    char character;
    cin>>n>>m;

    matrix.assign(n, vector<char>(m));
    visitados.assign(n, vector<bool>(m));

    for(int i =0;i<n;i++){
        for (int j =0;j<m;){
            cin>>character;
            if (character=='.' || character == '#')
                matrix[i][j++] = character;
        }
    }

    vector<vector<pair<int,int>>> barcos;

    for (int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            if (matrix[i][j] == '#' && !visitados[i][j]){
                vector<pair<int,int>> barco;
                dfs(i,j, n, m, barco);
                barcos.push_back(barco);
            }
        }
    }

    cin >> a;
    for (int i = 0;i<a;i++){
        cin>>l>>c;
        l--;c--;
        matrix[l][c] = '.';
    }

    for (int i =0;i<barcos.size();i++){
        int quantPontos = barcos[i].size();
        int contPont = 0;
        for(pair<int,int> ponto: barcos[i]){
            int x = ponto.first, y = ponto.second;
            if (matrix[x][y] == '.')
                contPont++; 
        }
        if (contPont==quantPontos) cont++;
    }
    


    cout<<cont<<endl;

}