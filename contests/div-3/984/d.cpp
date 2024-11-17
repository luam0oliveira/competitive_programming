// WRONG SOLUTION
// I red the question wrong, so make the solution wrong too


#include<bits/stdc++.h>
#define ll long long
using namespace std;

char matrix[1000][1000];
int n,m;

bool pos(int i, int j) {
    return i >= 0 && i <n && j >= 0 && j <m;
}

pair<int,int> directions[4] = {
    {0,1},
    {1,0},
    {0,-1},
    {-1,0}
};

int testa(int i, int j, int z, int x, int y, int c) {
    string s;
    for(int l = 0; l < x;l++) {
        i+=directions[z%4].first;
        j+=directions[z%4].second;
        if (!pos(i,j)) return false;
        s+=matrix[i][j];
        // celulas.push_back(directions[z%4]);
    }
    for(int l = 0; l < y;l++) {
        i+=directions[(z+1)%4].first;
        j+=directions[(z+1)%4].second;
        if (!pos(i,j)) return false;
        s+=matrix[i][j];
    }
    for(int l = 0; l < c;l++) {
        i+=directions[(z+2)%4].first;
        j+=directions[(z+2)%4].second;
        if (!pos(i,j)) return false;
        s+=matrix[i][j];
    }



    return s == "543";
}


int main() {
    int t;cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>matrix[i][j];
        
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (matrix[i][j] == '1') {
                    for(int z = 0; z < 4;z++){
                        for(int x = 1; x <=3;x++){
                            for(int y = 0; y <=3-x;y++){
                                for(int c = 0; c <= 3-y-x;c++) {
                                    count+=testa(i,j,z,x,y,c);
                                }
                            }    
                        }

                    }
                }
            }
        }

        

        cout<<count<<endl;
        // cout<<"======"<<endl;
    

    }    
    return 0;
}