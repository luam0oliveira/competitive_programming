// https://judge.beecrowd.com/pt/problems/view/2131
// Grafos - colocaracao(bicoloracao)

#include <bits/stdc++.h>

using namespace std;

vector<int> nos;
vector<vector<int>> rel;

bool dfs(int u, int cor){
	nos[u] = cor;
	bool pos = true;
	for(int i = 0; i<rel[u].size() && pos;i++){
		int no = rel[u][i];
		if (nos[no] == cor)
			pos = false;
		else if (nos[no] == 0)
			pos = dfs(no, cor*-1);
	}
	return pos;
}

int main(){
	int n,m, cases=1;
	while(cin>>n>>m){
		nos.assign(n, 0);
		rel.assign(n, {});
		for(int i =0;i<m;i++){
			int u,v;cin>>u>>v;
			u--;v--;
			rel[u].push_back(v);
			rel[v].push_back(u);
		}

		bool pos = true;
		for (int i =0;i<m && pos;i++){
			if (nos[i]==0)
				pos = dfs(i, 1);
		}

		printf("Instancia %d\n", cases++);
		if (pos) cout<<"sim";
		else cout<<"nao";
		cout<<endl<<endl;
	}
	
	return 0;

}