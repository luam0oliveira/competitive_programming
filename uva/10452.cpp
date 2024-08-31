// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1393
// Grafos

#include<bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define QUAT(x) x*x;
using namespace std;

int n, m;
string word = "IEHOVA";
char matrix[30][30];
pair<pi, string> neigh[] = {
    {{-1,0}, "forth"},
    {{0,1}, "right"},
    {{0,-1}, "left"}
};

bool possible(int x, int y, int pos){
    return !(x < 0 || y < 0 || y >= m || x >= n || matrix[x][y] != word[pos]);
}

void dfs(int x, int y, int pos){
    if (pos == 6){
        for(int i = 0; i < 3; i++){
            int nx = x + neigh[i].first.first;
            int ny = y + neigh[i].first.second;
            string direction = neigh[i].second;
            if (!(nx < 0 || ny < 0 || ny >= m || nx >= n) && matrix[nx][ny] == '#'){
                cout<<direction;
            }
        }
        return;
    }

    for(int i = 0; i < 3; i++){
        int nx = x + neigh[i].first.first;
        int ny = y + neigh[i].first.second;
        string direction = neigh[i].second;
        if (possible(nx, ny, pos)){
            cout<<direction<<" ";
            dfs(nx,ny, pos+1);
        }
    }
}

int main(){
    int t;scanf("%d ", &t);
    while(t--){
        scanf("%d %d ", &n, &m);
        pi initialPos;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                scanf("%c ", &matrix[i][j]);   
                if (matrix[i][j] == '@'){
                    initialPos = {i,j};
                }
            }
        }
        dfs(initialPos.first, initialPos.second, 0);
        cout<<endl;
    }
}
