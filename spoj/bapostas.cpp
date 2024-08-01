// https://br.spoj.com/problems/BAPOSTAS/
// ad-rock

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,a, maxx, acum;
    while(cin>>n && n!=0){
        acum = 0;
        maxx= 0;
        for (int i = 0;i<n;i++){
            cin>>a;
            acum+=a;
            if (acum < 0 )
                acum = 0;

            maxx = max(acum, maxx);
        }
        if(maxx >0)
            printf("The maximum winning streak is %d.\n", maxx);
        else
            printf("Losing streak.\n");
    }
    return 0;
}
