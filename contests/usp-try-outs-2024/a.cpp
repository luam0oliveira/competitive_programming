// https://codeforces.com/gym/105297/problem/A
// ad-rock

#include<bits/stdc++.h>
#define ll long long
#define MIN(a, b) (a < b) ? a : b
#define MAX(a, b) (a < b) ? b : a
#define EPS 1e-9
#define ZERO(a) ? (abs(a) < EPS) ? 1 : 0
    
using namespace std;
    
struct song{
    ll id,inicio, duracao, tipo;

    bool operator< ( song o) const {
        return inicio<o.inicio;
    }
};

int main(){
    int n;cin>>n;
    vector<song> songs;
    queue<song> atocar;
    for(int i = 0;i<n;i++){
        int op;
        song s;cin>>s.inicio>>s.duracao>>op;
        s.id = i+1;
        s.tipo = op;
        songs.push_back(s);
    }
    sort(songs.begin(), songs.end());

    vector<int> infelizes;
    int tempoAtual = 1;
    song atual = {-1, 0, 0, -1};

    int i=0;
    while(i != n){
        song a = songs[i];
        // cout<<a.id<<endl;
        
        if (atual.tipo == -1){
            atual = a;
            i++;
            continue;
        }

        if (atual.duracao + atual.inicio > a.inicio){
            if (a.tipo == 1){
                infelizes.push_back(atual.id);
                atual = a;
            }
            else{
                atocar.push(a);
            }
            i++;
        }else{
            while(!atocar.empty() && atual.duracao + atual.inicio <= a.inicio){
                atocar.front().inicio = max(atual.inicio + atual.duracao, atocar.front().inicio);
                atual = atocar.front(); atocar.pop();
            }
            if (atual.duracao + atual.inicio <= a.inicio){
                atual = a; i++;
            }else{
                if (a.tipo){
                    infelizes.push_back(atual.id);
                    atual = a;
                }else{
                    a.inicio = max(atual.inicio + atual.duracao, a.inicio);
                    atocar.push(a);
                }
                i++;
            }

        }
    }


    // while(i != n){
    //     song a = songs[i];
    //     // cout<<a.id<<endl;
        
    //     if (atual.tipo == -1){
    //         atual = a;
    //         i++;
    //         continue;
    //     }

    //     if (a.tipo == 1){
    //         if (!atocar.empty() && atual.duracao + atual.inicio < a.inicio){
    //             // cout<<"AHAHA"<<endl;
    //             atocar.front().inicio = max(atual.inicio + atual.duracao, atocar.front().inicio);
    //             atual = atocar.front(); atocar.pop();
    //             continue;
    //         }
    //         if (atual.inicio + atual.duracao > a.inicio)
    //             infelizes.push_back(atual.id);
    //         atual = songs[i++];
    //         continue;
    //     }

    //     atocar.front().inicio = max(atual.inicio + atual.duracao, atocar.front().inicio);
    //     atocar.push(a);
    //     i++;
    // }



    cout<<infelizes.size()<<endl;
    if(infelizes.size()) cout<<infelizes[0];
    for(int i = 1 ;i<infelizes.size();i++){
        cout<<" "<<infelizes[i];
    }
    if(infelizes.size())cout<<endl;
}