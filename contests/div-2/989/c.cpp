/**
 *     author: demot.r
 *     created: 2024-11-30 12:23:46
 *     source: 
 *     description: 
**/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,m;
int matrix[1000][1000];
bitset<1000> visitados[1000];

// baixo = 1, esquerda = 2, cima = 3, direita = 4, indefinido = 0, -1 = fora;


pair<int,pair<int,int>> vizinhos[4] = {
    {3,{1,0}},
    {1,{-1,0}},
    {2,{0,1}},
    {4,{0,-1}}
};

// verifica se a posicao eh valida
bool valid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(int i, int j, int p = 0) {
    queue<pair<int,int>> q;
    q.push({i,j});
    visitados[i].set(j);
    matrix[i][j] = -1;

    while(!q.empty()) {
        auto pos = q.front();
        q.pop();        

        for(int i=0;i<4;i++) {
            int ni, nj;
            ni = pos.first + vizinhos[i].second.first;
            nj = pos.second + vizinhos[i].second.second;
            // if (p && ni == 0 && nj == 1) {
            //     cout << pos.first <<" "<<pos.second<<endl;
            //     cout << vizinhos[i].first<< " "<<matrix[ni][nj]<<endl;
            // }
            if (valid(ni, nj) && matrix[ni][nj] == vizinhos[i].first && !visitados[ni][nj] ) {

                visitados[ni].set(nj);
                matrix[ni][nj] = -1;
                q.push({ni,nj});
            }
        }
    } 
}

int main() {
    int t;cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<n;i++) {
            visitados[i].reset();
        }

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                char a; cin>>a;
                int value;
                if (a == '?') {
                    value = 0;
                } else if (a == 'U') {
                    value = 3;
                } else if (a == 'R') {
                    value = 4;
                } else if (a == 'L') {
                    value = 2;
                } else {
                    value = 1;
                }
                matrix[i][j] = value;
            }
        }

        // for(int i =0;i<n;i++){
        //     for(int j =0;j<m;j++){
        //         cout<<matrix[i][j];
        //     }
        //     cout<<endl;
        // }
        
        // baixo = 1, esquerda = 2, cima = 3, direita = 4, indefinido = 0, -1 = fora;

        for(int i=0;i<n;i++) {
            if (matrix[i][0] == 2) {
                bfs(i,0);
            }
        }

        for(int i=0;i<n;i++) {
            if (matrix[i][m-1] == 4) {
                bfs(i,m-1);
            }
        }

        for(int i=0;i<m;i++) {
            if (matrix[n-1][i] == 1) {
                bfs(n-1,i, 1);
            }
        }

        for(int i=0;i<m;i++) {
            if (matrix[0][i] == 3) {
                bfs(0,i);
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if (matrix[i][j] == 0) {
                    int pos = 0;
                    for(int l=0;l<4;l++) {
                        int ni, nj;
                        ni = i + vizinhos[l].second.first;
                        nj = j + vizinhos[l].second.second;

                        if (valid(ni, nj) && matrix[ni][nj] != -1) {
                            pos = true;
                            break;
                        }
                    }
                    if (!pos) matrix[i][j] = -1;
                }
            }
        }

        int count = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if (matrix[i][j] != -1) {
                    count++;
                }
            }
        }

        


        cout<<count<<endl;

        
    }    
    return 0;
}