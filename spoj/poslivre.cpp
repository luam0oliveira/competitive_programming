// https://br.spoj.com/problems/POSLIVRE/
// ad-rock

#include <bits/stdc++.h>

using namespace std;

int matrix[501][501];

void swap(int &x1, int &x2){
    int temp = x1;
    x1 = x2;
    x2 = temp;
};

int main(){
    // int first = 1;
    while(1){
        int w,h,n; cin>>w>>h>>n;
        if (w== 0 && h == 0 && 0==n ) break;
        // if (!first)
        //     cout<<endl;
        // first = 0;
        for (int j=1;j<=w;j++)
            for(int k=1;k<=h;k++)
                matrix[j][k]=0;

        for(int i=0;i<n;i++){
            int x1,x2,y1,y2;cin>>x1>>y1>>x2>>y2;
            if (x1 > x2) swap(x1,x2);
            if (y1 > y2) swap(y1,y2);
            for (int j=x1;j<=x2;j++)
                for(int k=y1;k<=y2;k++)
                    matrix[j][k]++;
        }
        int cont=0;
        for (int j=1;j<=w;j++)
            for(int k=1;k<=h;k++)
                if (matrix[j][k] == 0)
                    cont++;
        if (cont ==0)
            printf("There is no empty spots.\n");
        else if (cont == 1)
            printf("There is one empty spot.\n");
        else
            printf("There are %d empty spots.\n", cont);
    }
}
