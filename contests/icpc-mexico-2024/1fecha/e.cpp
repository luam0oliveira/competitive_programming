#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,k;cin>>a>>b>>k;
    vector<int> sequence;
    for(int i =1;i<=k;i++){
        sequence.push_back(a*i+b);
    }
    cout<<sequence[0];
    for(int i = 1;i<k;i++){
        cout<<" "<<sequence[i];
    }
    cout<<endl;
}