// https://br.spoj.com/problems/CAPITA13/
// geometria
// O codigo comentado foi de uma solucao que desenvolvi anteriormente e estava 
// completamente incorreta, pois so considerava lados inteiros

#include <bits/stdc++.h>
#define EPS 1e-9

using namespace std;

// int mdc(int a, int b){
//     if (a < b) return mdc(b,a);
//     while(b!=0){
//         int aux = b;
//         b = a % b;
//         a = aux;
//     }
//     return a;
// }

bool possivel(int a, int b, int c, int d){
    return fabs(a * d - b * c) <= EPS;

    // cout << ab << " "<<ac<< " "<<cd<<" "<<db<<endl;

    // return (ab+cd)*(db+ac) == a+b+c+d;
}

int main(){
    
    int a,b,c,d;cin>>a>>b>>c>>d;
    bool pos = possivel(a,b,c,d);
    if(!pos) pos = possivel(a,d,c,b);
    if(!pos) pos = possivel(c,b,a,d);
    if(!pos) pos = possivel(d,a,b,c);
    if(!pos) pos = possivel(c,d,a,b);
    if(!pos) pos = possivel(b,c,d,a);
    
    if (pos) cout <<"S\n";
    else cout<<"N\n";
    return 0;
}
