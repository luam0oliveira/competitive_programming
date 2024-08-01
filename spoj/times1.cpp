// https://br.spoj.com/problems/TIMES1/
// ad-rock - simulacao

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, string> jogador;

int main()
{
	int n, tt, maxjogadores;

	cin >> n >> tt;

	maxjogadores = n/tt;

	vector<int> quantT(tt);
	vector<vector<string> > times(tt);
	vector<jogador> jogadores(n);

	for (int i =0; i< n;i++){
		cin >> jogadores[i].second >> jogadores[i].first;
	}

	sort(jogadores.begin(), jogadores.end());

	int cont = 0;
	while(!jogadores.empty()){
		times[cont].push_back(jogadores.back().second);
		jogadores.pop_back();
		cont = (cont+1) % tt;
	}

	for (int i = 0; i < tt;i++){
		sort(times[i].begin(), times[i].end());
		cout<<"Time "<<i+1<<endl;
		for (int j = 0 ; j < times[i].size();j++)
		{
			cout <<times[i][j]<<endl;
		}
		if (i != tt-1)
			cout << endl;
	}
}
