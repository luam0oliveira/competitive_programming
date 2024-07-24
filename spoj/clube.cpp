// https://br.spoj.com/problems/CLUBE/
// Ad-rock

#include <bits/stdc++.h>

using namespace std;

int main() {
	int m,n, a;
	while (cin>>m>>n && m != 0 && n != 0){
		n *= 100;
		m *= 100;
		int largura, numTabuas; cin>>largura>>numTabuas;
		vector<int> tabuas(numTabuas);
		for(int i =0;i<numTabuas;i++){
			cin >> a;
			tabuas[i] = a*100;
		} 
		sort(tabuas.begin(), tabuas.end());

		bool valido = false;
		int minimo=-1;
		for (int z = 0;z<2;z++){
			if(m % largura == 0){
				vector<int> utilizadas;
				int necessarios = m / largura;
				int quant = 0;
				unordered_multiset<int> tt;
				for(int i =numTabuas-1;i>=0 && quant < necessarios;i--){
					if (tabuas[i] == n){
						quant++;
						utilizadas.push_back(tabuas[i]);
					}
					else if(tabuas[i] < n){
						auto ff = tt.find(tabuas[i]);
						if (ff != tt.end()){
							utilizadas.push_back(*ff);
							utilizadas.push_back(tabuas[i]);
							quant++;
							tt.erase(ff);
						}else{
							tt.insert(n-tabuas[i]);
						}
					}
				}
				if (necessarios == quant){
					valido = true;
					if (minimo == -1)
						minimo = utilizadas.size();
					minimo = min((int)utilizadas.size(), minimo);
				}
				int aux = m;
				m = n;
				n = aux;
			}
		}
		if (valido) cout <<minimo<<endl;
		else cout<<"impossivel"<<endl;
	}	
}

