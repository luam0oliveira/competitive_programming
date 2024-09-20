/**
 *     author: demot.r
 *     created: 2024-09-20 07:09:01
 *     source: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=654
 *     description: Implementacao/ad-rock
**/
#include<bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define QUAT(x) x*x;
using namespace std;

int main(){
    int n;cin>>n;
    for(int z =0 ; z < n;z++) {
        string a, b, result; cin>>a>>b;

        if (a.size() < b.size()){
            swap(b,a);
        }
        int bsz = b.size();
        int add1 = false;
        for(int i = 0; i < a.size();i++) {
            if (bsz > i) {
                int aa, bb;
                aa = (a[i] - '0');
                bb = (b[i] - '0');
                result+='0'+(aa + bb + add1) % 10;
                add1 = (aa + bb + add1)/10;
            } else {
                result+= '0' + ((a[i] - '0') + add1) % 10;
                add1 = ((a[i] - '0') + add1) / 10;
            }
        }
        if (add1) result += '1';

        int zero = true;
        for(int i = 0; i < result.size();i++){
            if (result[i] != '0') zero = false;
            if (!zero) cout<<result[i];
        }
        cout<<endl;
    }    
    return 0;
}
