#include<bits/stdc++.h>
using namespace std;
// #define ll long lo

bool possivel(const vector<int> &ciclos, int dia, int necessario){
    long long sum = 0;
    for (int i =0;i<ciclos.size();i++){
        sum+=dia/ciclos[i];
        // cout<<dia/ciclos[i]<<endl;
    }
    // cout<<"dia= "<<dia<<" "<<sum<<endl;
    return necessario<= sum;

}

int binary_search(vector<int> &ciclos, int necessario){
    int left=1;
    int right = 2e9;
    int mid = left+(right -left)/2;

    while(!(possivel(ciclos, left, necessario) && !possivel(ciclos, left-1, necessario))){
        mid = left+(right -left)/2;
        if (possivel(ciclos,mid, necessario))
            right = mid-1;
        else left = mid + 1;
        // cout<<left<<endl;
    }
    return left;
}



int main(){
    int n,m;cin>>n>>m;
    vector<int> ciclos;
    for(int i =0;i<n;i++){
        int a;cin>>a;
        ciclos.push_back(a);
    }
    // cout<<min*(possivel(ciclos,100000000, m)<<endl;
    cout<<min(binary_search(ciclos, m), (int)1e8)<<endl;
}