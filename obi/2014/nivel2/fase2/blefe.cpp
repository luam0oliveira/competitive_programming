// https://judge.beecrowd.com/pt/problems/view/2461
// Ad-rock/STL

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m,a;cin >> n >> m;
	unordered_set<int> conjuntoA,conjuntoB;
	for (int i = 0; i < n; i++) {
		cin >> a;
		conjuntoA.insert(a);
	}

	vector<int> jogadasB(m);
	for (int i = 0; i < m; i++) {
		cin >> jogadasB[i];
	}
	bool certo = true;
	for (int i = 0; i < m && certo; i++) {
		certo=false;
		a = jogadasB[i];

		certo = conjuntoA.find(a) != conjuntoA.end();

		if (!certo){
			for (auto it = conjuntoB.begin();it!=conjuntoB.end() && !certo;it++)
				certo = conjuntoB.find(a - *it) != conjuntoB.end();
		}

		if (certo)
			conjuntoB.insert(a);
	}

	if (certo) cout<<"sim"<<endl;
	else cout<<a<<endl;
	return 0;
}
