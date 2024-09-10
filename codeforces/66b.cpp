// https://codeforces.com/contest/66/problem/B
// ad-rock

#include<bits/stdc++.h>
#define ll long long
#define QUAT(x) x*x;
using namespace std;

const int MAXN = 1e3+1;
int arr[MAXN];
int main(){
    int n;cin>>n;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    int maxlen = 1;
    for(int i = 0; i < n;i++){
        int l = i,r = i;
        int minimum = arr[i];
        while(l > 0 && arr[l-1] <= minimum){
            minimum = arr[l-1];
            l--;
        }
        minimum = arr[i];
        while(r < n-1 && arr[r+1] <= minimum){
            minimum = arr[r+1];
            r++;
        }
        maxlen = max(r - l + 1, maxlen);
    }
    cout<<maxlen<<endl;
}
