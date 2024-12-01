/**
 *     author: demot.r
 *     created: 2024-11-30 11:38:05
 *     source: 
 *     description: 
**/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int gcd(int a, int b) {
    if (a < b) {
        return gcd(b,a);
    }
    while(b) {
        int aux = b;
        b = a%b;
        a = aux;
    }
    return a;
}

int main() {
    int t;cin>>t;
    while(t--){
        int a,b;cin>>a>>b;
        int prod = a * b;
        cout << prod / gcd(a,b)<<endl;
    }   
    return 0;
}