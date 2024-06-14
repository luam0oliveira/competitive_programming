#include <bits/stdc++.h>

using namespace std;

int numNodes;

vector < vector < int >> nodes;
vector < int > visited(110, 0);

void dfs(int i) {
    visited[i] = true;
    int numN = nodes[i].size();
    for (int k = 0; k < numN; k++) {
        if (!visited[nodes[i][k]])
            dfs(nodes[i][k]);
    }
}

int verifica(int v) {
    for (int i = 1; i <= v; i++)
        if (!visited[i]) {
            return 1;
        }
    return 0;
}

int main() {
    string s;
    while (true) {
        getline(cin, s);
        stringstream in(s);
        in >> numNodes;

        if (!numNodes) break;

        nodes = vector<vector<int>> (numNodes + 1, vector < int > ());
        int ori, a;
        string s;
        while (true) {
            getline(cin,s);
            stringstream in(s);
            in >> ori;


            if (!ori) break;

            while (in >> a) {
                nodes[ori].push_back(a);
                nodes[a].push_back(ori);
            }
        }

        int cont = 0;

        for (int i = 1; i <= numNodes; i++) {
            visited.assign(numNodes+1,0);
            visited[i] = 1;
            if (i == numNodes)
                dfs(i - 1);
            else
                dfs(numNodes);
            cont += verifica(numNodes);
        }
        cout << cont << endl;
    }
    return 0;
}
