// https://br.spoj.com/problems/RONTGEN/
// ad-rock

// rontgen sequence

#include <bits/stdc++.h>
using namespace std;

string genSequence(const string current) {
	string next = "";
	for (int i =0;i<current.size();i++){
		int count=1;
		while(i <current.size() && current[i] == current[i+1]){
			count++;
			i++;
		}
		next+=to_string(count)+current[i];
	}	
	return next;
}

int main() {
	int cases;cin>>cases;
	while(cases--){
		string current;
		int n;
		cin>>current>>n;
		for (int i = 0; i <= n; i++) {
			cout << current << endl;
			current = genSequence(current);
		}
		cout<<endl;
	}
	return 0;
}
