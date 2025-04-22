#include <bits/stdc++.h>
using namespace std;

// Se ordenar os pontos e depois junta-los num vetor seguindo uma ordem como baixo, direta, cima, esquerda
// voce pode verificar se ha alguma inversao e forma gulosa utilizando uma pilha
// Essa ideia foi de um dos meus amigos do time, minha implementação inicial era muito mais complicada e
// provavelmente teria muitos bugs

int w,h;
int extreme(int a, int b) {
    return a == w || a == 0 || b == 0 || b == h; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>w>>h;
    int n;cin>>n;
    vector<vector<pair<int,int>>> paredes(4);
    for(int i=0;i<n;i++) {
        int a,b,c,d;cin>>a>>b>>c>>d;
        if (extreme(a,b) && extreme(c,d)) {
            if (a == 0) {
                paredes[0].push_back({-b,i});
            } else if (a == w) {
                paredes[2].push_back({b,i});
            } else if (b == 0) {
                paredes[1].push_back({a,i});
            } else {
                paredes[3].push_back({-a,i});
            }

            if (c == 0) {
                paredes[0].push_back({-d,i});
            } else if (c == w) {
                paredes[2].push_back({d,i});
            } else if (d == 0) {
                paredes[1].push_back({c,i});
            } else {
                paredes[3].push_back({-c,i});
            }
        }
    }

    sort(paredes[0].begin(), paredes[0].end());
    sort(paredes[1].begin(), paredes[1].end());
    sort(paredes[2].begin(), paredes[2].end());
    sort(paredes[3].begin(), paredes[3].end());

    stack<int> st;

    unordered_map<int,int> used;
    int ans = 1;
    for(int i=0;i<4 && ans;i++) {
        for(auto p: paredes[i]) {
            int point = p.second;

            if (used[point] == 0) {
                st.push(point);
                used[point] = 1;
            } else{
                if (st.top() != point) {
                    ans = 0;
                    break;
                } else {
                    st.pop();
                }
            }
        }
    }

    if (ans) cout <<"Y\n";
    else cout <<"N\n";

} 