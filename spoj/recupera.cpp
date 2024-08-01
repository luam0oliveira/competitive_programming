// https://br.spoj.com/problems/RECUPERA/
// ad-rock

#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, cases=1;
    while (cin >> n){
        int acumula=0;
        int index = -1000;
        int a;
        for (int i=0;i<n;i++){
            scanf("%d ",&a)==1;
            if (acumula==a && index == -1000)
                index = a;
            acumula+=a;
        }
        cout<<"Instancia "<<cases++<<endl;
        if (index!=-1000)
            cout<<index<<endl;
        else
            cout<<"nao achei"<<endl;
        cout<<endl;
    }
}
