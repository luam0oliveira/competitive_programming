#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int a;cin>>a;
        int ant = a;
        int s = true;
        for(int i=0;i<n-1;i++){
            cin>>a;
            if (abs(ant - a) != 5 && abs(ant - a) != 7) {
                s = false;
            }
            ant = a;
        }
        if (s) cout << "YES"<<endl;
        else cout<<"NO"<<endl;
    }    
    return 0;
}