#include<bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define QUAT(x) x*x;
using namespace std;

// 15

int main(){
    int t;cin>>t;
    while(t--){
        int tam;cin>>tam;
        string s;cin>>s;
        int sz = sqrt(tam);
        int pos = sz * sz == tam;

        for(int i =0;i<sz && pos;i++){
            for(int j =0;j<sz && pos;j++){
                int position = i*sz + j;
                if (i == 0 || i == sz-1 || j == 0 || j == sz-1){
                    pos = s[position] == '1';
                } else {
                    pos = s[position] == '0';
                }
            }
        }

        if (pos) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

    }
    return 0;
}
