#include <bits/stdc++.h>
#define ll long long
using namespace std;



void fastIo(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector<pair<int,int>> vizinhos = {
    {1,0},
    {0,1},
    {-1,0},
    {0,-1},
    {0,0}
};

bool possivel(int x, int y, int l, int c, vector<vector<int>> &verificados){
    return !(x < 0 || x >= l || y >=c || y<0 || !verificados[x][y]);
}
bool possivel(int x, int y, int l, int c){
    return !(x < 0 || x >= l || y >=c || y<0);
}

bool verificaIgualdade(int x, int y, int l, int c, vector<vector<int>> &verificados,
 vector<vector<ll>>& finalizados,  vector<vector<ll>>& matriz){
    for (int k =0;k<4;k++){
        int nx = vizinhos[k].first + x;
        int ny = vizinhos[k].second + y;
        if (possivel(nx,ny,l,c,verificados) && matriz[nx][ny] > matriz[x][y])
            return false;
    }
    return true;
}

ll bfs(int x, int y, int l, int c, vector<vector<ll>>& matriz){
    vector<vector<int>> visitados(l, vector<int>(c));
    ll poderatual = -1;
    priority_queue<pair<ll,pair<int,int>>> pq;
    
    pq.push({-matriz[x][y],{x,y}});

    visitados[x][y] = 1;
    while(!pq.empty()){
        auto top = pq.top(); pq.pop();
        ll custo = top.first;
        int ni = top.second.first;
        int nj = top.second.second;

        if (poderatual < -custo && poderatual!=-1){
            break;
        }
        if (poderatual==-1){
            poderatual =-custo;
        }else{
            poderatual-=custo;
        }
        for(int i =0;i<(int)vizinhos.size();i++){
            int nx = ni + vizinhos[i].first;
            int ny = nj + vizinhos[i].second;
            if (possivel(nx,ny,l,c) && !visitados[nx][ny]){
                visitados[nx][ny] = 1;
                pq.push({-matriz[nx][ny], {nx,ny}});
            }
        }
    }

    return poderatual;
}

void dfs(int x, int y, int l, int c, int inicial, vector<vector<ll>>& matriz, vector<pair<int,int>>& iguais, vector<vector<int>>& visitados){
    visitados[x][y] = 1;
    if (iguais.size() >= 50000) return;
    
    for(int i = 0; i<4;i++){
        int nx = x + vizinhos[i].first;
        int ny = y + vizinhos[i].second;
        if(possivel(nx, ny, l, c) && !visitados[nx][ny] && inicial == matriz[nx][ny]){
            iguais.push_back({nx,ny});
            dfs(nx,ny,l,c,inicial,matriz,iguais,visitados);
        }
    }
}

int main(){
    fastIo();

    int l,c;cin>>l>>c;
    vector<vector<ll>> matriz(l, vector<ll>(c)), ff(l, vector<ll>(c));
    vector<vector<int>> verificados(l, vector<int>(c));

    for(int i = 0; i<l;i++){
        for(int j = 0; j<c;j++){
            cin>>matriz[i][j];
        }
    }


    for(int i = 0; i<l;i++){
        for(int j = 0; j<c;j++){
            if (!verificados[i][j]){
                vector<pair<int,int>> iguais;
                ff[i][j] = bfs(i,j,l,c,matriz);
                verificados[i][j] = 1;
                vector<vector<int>> visitados(l,vector<int>(c));
                dfs(i, j, l, c, matriz[i][j], matriz, iguais,visitados);
                for(int k = 0 ;k<(int)iguais.size();k++){
                    verificados[iguais[k].first][iguais[k].second] = 1;
                    ff[iguais[k].first][iguais[k].second] = ff[i][j];
                }
            }
        }
    }

    for(int i = 0; i<l;i++){
        cout<<ff[i][0];
        for(int j = 1; j<c;j++){
            cout<<" "<<ff[i][j];
        }
        cout<<endl;
    }


    
    return 0;
}