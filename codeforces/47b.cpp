/**
 *     author: demot.r
 *     created: 2024-10-15 22:26:10
 *     source: https://codeforces.com/contest/47/problem/B
 *     description: graphs
**/

#include<bits/stdc++.h>
#define ll long long
using namespace std;


vector<int> rel[3];
int visited[3];

int dfs(int u) {
    visited[u] = true;

    for(int i = 0; i < (int) rel[u].size(); i++) {
        if (visited[rel[u][i]]) {
            return false;
        }
        if (!dfs(rel[u][i])){
            return false;
        }
    }

    visited[u] = false;

    return true;
}

int main() {
    string s;
    while(cin >> s) {
        int u, v, op;
        u = s[0] - 'A';
        v = s[2] - 'A';
        op = s[1] == '>';

        if (op) {
            rel[v].push_back(u);
        }else {
            rel[u].push_back(v);
        }
    }
    int contZero = 0;
    int u = -1;
    for(int i = 0; i < 3; i++) {
        if (rel[i].size() == 0){
            contZero++;
        }
    }

    int valid = contZero == 1;

    for(int i = 0; i < 3;i++){
        memset(visited, 0, 3);
        if (!visited[i]){
            valid = dfs(i) && valid;
        }
    }

    if (valid) {
        vector<pair<int,char>> ord;
        for(int i = 0; i < 3;i++) {
            ord.push_back({rel[i].size(), 'A' + i});
        }
        sort(ord.begin(), ord.end());
        for(int i = 2; i >= 0;i--) {
            cout<<ord[i].second;
        }
        cout<<endl;
    }else{
        cout<<"Impossible"<<endl;
    }

    return 0;
}
