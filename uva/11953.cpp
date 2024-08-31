// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3104
// Grafos

#include<bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define QUAT(x) x*x;
using namespace std;

int n;
char matrix[101][101];

pi neigh[] = {
    {1,0},
    {0,1}
};

bool possible(int x, int y){
    return !(x < 0 || y < 0 || y >= n || x >= n || (matrix[x][y] != '@' && matrix[x][y] != 'x'));
}

// dir = 0: vertical, 1: horizontal
void dfs(int x, int y, int dir){
    matrix[x][y] = '@';
    int nx = x + neigh[dir].first;
    int ny = y + neigh[dir].second;

    if (possible(nx, ny)){
        dfs(nx,ny, dir);
    }
}

int main(){
    int t, cases = 1;scanf("%d ", &t);
    while(t--){
        scanf("%d ", &n);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                scanf("%c ", &matrix[i][j]);   
            }
        }

        int cont = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if (matrix[i][j] == 'x'){
                    if (possible(i+1, j)){
                        dfs(i, j, 0);
                    }else if(possible(i,j+1)){
                        dfs(i,j,1);
                    }
                    matrix[i][j] = '@';
                    cont++;
                }
            }
        }
        printf("Case %d: %d\n", cases++, cont);
    }
}
