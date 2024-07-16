// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1891
// Backtracking, mas é mais importante uma certa visão do problema para conseguir concluir

#include <bits/stdc++.h>

using namespace std;

vector<long long int> terms;

map<long long int, set<int>> jausados;

void genFibbo(long long n){
	long long a = 2, b = 3, aux = b;
	terms.push_back(a);
	terms.push_back(b);
	while (b < n){
		aux = b;
		b = a+aux;
		a = aux;
		terms.push_back(b);
	}
}

string sequence(int n){
	string seq;

	for (int i =0;i<n;i++)seq+='A';
	return seq+='B';
}

bool solve(long long int n, vector<string>& forma){
	if (n == 1)
		return true;
	
	for(int i=terms.size()-1;i>=0;i--){
		if (n % terms[i] == 0){
			if (jausados[n].find(i)!=jausados[n].end()) continue;
			jausados[n].insert(i);
			forma.push_back(sequence(i+1));
			if (solve(n / terms[i], forma)) return true;
			forma.pop_back();
		}
	}

	return false;
}

int main(){
	genFibbo(1000000000000000);
	long long int a;cin>>a;
	vector<string> seq;
	bool ok = solve(a, seq);
	sort(seq.begin(),seq.end());
	if (!ok) cout<<"IMPOSSIBLE";
	else for(int i =0;i<seq.size();i++) cout<<seq[i];
	cout<<endl;
}