// https://br.spoj.com/problems/TROCCARD/
// ad-rock

#include <bits/stdc++.h>

using namespace std;

int main(){
    while(1){
        int numa, numb;cin>>numa>>numb;
        if(numa==0 && numb==0)break;
        set<int> a;
        set<int> b;
        for(int i=0;i<numa;i++){
            int ent;cin>>ent;
            a.insert(ent);
        }
        for(int i=0;i<numb;i++){
            int ent;cin>>ent;
            b.insert(ent);
        }

        int cont = 0;
        int minn = max(numa, numb);
        for(auto el:b)
            if (a.find(el) == a.end())cont++;
        minn = min(cont,minn);
        cont=0;
        for(auto el:a)
            if (b.find(el) == b.end())cont++;
        minn = min(cont,minn);
        cout<<minn<<endl;
        
    }
}