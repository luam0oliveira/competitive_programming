// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=288
// Grafos

#include<bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define QUAT(x) x*x;
using namespace std;

int n;
char matrix[30][30];
pi neigh[] = {
    {1,1},
    {-1,1},
    {1,-1},
    {-1,-1},
    {0,1},
    {1,0},
    {0,-1},
    {-1,0}
};

bool possible(int x, int y){
    return !(x < 0 || y < 0 || y >= n || x >= n || matrix[x][y] == '0');
}

void dfs(int x, int y){
    matrix[x][y] = '0';

    for(int i = 0; i < 8; i++){
        int nx = x + neigh[i].first;
        int ny = y + neigh[i].second;
        if (possible(nx, ny))
            dfs(nx,ny);
    }
}

int main(){
    int cases = 1;
    while(scanf("%d ", &n) == 1){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                scanf("%c ", &matrix[i][j]);
            }
        }

        int cont = 0;
        for (int i =0; i < n; i++){
            for (int j =0; j < n; j++){
                if (possible(i,j)){
                    cont++;
                    dfs(i,j);
                }
            }
        }

        printf("Image number %d contains %d war eagles.\n", cases++, cont);
    }
    return 0;
}
