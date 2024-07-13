// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1891
// Backtracking puro (deve-se tomar cuidado para ordenar da forma correta os codigos encontrados)

#include <bits/stdc++.h>

using namespace std;

vector<string> geradas;
vector<pair<string,string>> codes;

void solve(string base, string gerada){
	if (geradas.size() == 100 )
		return;
		
	if (base.size()==0)
		return geradas.push_back(gerada);

	if (base[0] == '0' && base.size() == 1)
		return;

	if (base[0] == '0')
		return solve(base.substr(1), gerada);
	
	string umCarac;

	vector<pair<string,string>> encont;

	encont.push_back({"A", "0"});
	encont.push_back({"A", "0"});

	umCarac += base[0];
	int i = 0, ss = codes.size();

	for (;i<ss;i++)
		if (codes[i].second == umCarac) break;
	
	if (i!=ss){
		encont[0] = codes[i];
	}
	
	i = 0;
	if (base.size() > 1){
		umCarac +=base[1];
		for (;i<ss;i++)
		if (codes[i].second == umCarac) break;
	
		if (i!=ss)
			encont[1] = codes[i];
	}
	sort(encont.begin(),encont.end());
	for (i =0;i<2;i++)
		if (encont[i].first != "A") solve(base.substr(encont[i].second.size()), gerada + encont[i].first);
		
}

int main(){
	int cases = 1;
	while(1){
		int t; cin>>t;
		if (t==0) break;
		
		codes.clear();
		geradas.clear();

		string a, code;
		
		while(t--){
			cin>>a>>code;
			codes.push_back({a, code});
		}
		
		sort(codes.begin(), codes.end());
		
		string base;cin>>base;

		solve(base, "");
			
		printf("Case #%d\n", cases++);
		for(auto i=0;i<geradas.size();i++)
			cout<<geradas[i]<<endl;
		cout<<endl;
	}
}