#include<bits/stdc++.h>
#define ll long long
#define MIN(a, b) (a < b) ? a : b
#define MAX(a, b) (a < b) ? b : a
#define EPS 1e-9
#define ZERO(a) ? (abs(a) < EPS) ? 1 : 0
    
using namespace std;
    
int main() {
    int n;cin>>n;
    int total = 0;
    for(int i =0;i<n;i++){
        string line;cin>>line;
        int seguidos = 0;
        for(int j =0;j<n;j++){
            if (line[j]=='N'){
                seguidos+=1;
                if (seguidos%2==0) total++;
            }else seguidos=0;
        }
    }
    cout<<total<<endl;
}
