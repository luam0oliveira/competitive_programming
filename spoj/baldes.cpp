// https://br.spoj.com/problems/BALDES/
// Ad-rock/Estrutura de dados

#include <bits/stdc++.h>

using namespace std;

int merge(int inicio, int meio, int fim, vector<int> &nums){
	int tamParteEsq = meio - inicio + 1;
	int tamParteDir = fim - meio;
	int inversoes = 0;
	vector<int> arrayEsq = vector<int>(tamParteEsq), arrayDir = vector<int>(tamParteDir);
	
	for (int i=0;i<tamParteEsq;i++) arrayEsq[i] = nums[i+inicio]; 
	for (int i=0;i<tamParteDir;i++) arrayDir[i] = nums[i+meio+1];

	int i =0, j=0, k=inicio;

	while(tamParteEsq > i && tamParteDir > j){
		if (arrayEsq[i] <= arrayDir[j]) nums[k++] = arrayEsq[i++];
		else {
			nums[k++] = arrayDir[j++];
			inversoes += tamParteEsq-i;
			// inversoes = inversoes + meio - (inicio+i);
		}
	}

	while(tamParteEsq > i){
		nums[k++] = arrayEsq[i++];
		// inversoes += tamParteEsq-i + tamParteDir;
	}

	while(tamParteDir > j){
		nums[k++] = arrayDir[j++];
	}
	return inversoes;
}

int merge_sort(int inicio, int fim, vector<int> &nums){
	if (inicio >= fim) return 0;
	int inversoes = 0;
	int meio = inicio + (fim - inicio)/2;
	inversoes += merge_sort(inicio, meio, nums);
	inversoes += merge_sort(meio+1, fim, nums);
	inversoes += merge(inicio, meio, fim, nums);
	return inversoes;
}




int main() {
	// vector<int> aaa = {3,1,3,3};

	// int inversoes = merge_sort(0, aaa.size()-1, aaa);
	// cout << inversoes<<endl;
	// for (int i=0;i<aaa.size();i++){
	// 	cout<<aaa[i]<<endl;
	// }
	int n;
	while(cin>>n && n!=0){
		vector<int> num(n);
		for(int i=0;i<n;i++){
			cin>>num[i];
		}
		int inv1=0;
		// for (int i =0;i<n;i++)
		// 	for(int j=i;j<n;j++)
		// 		if (num[i] >num[j])inv1++;
		int inv = merge_sort(0, n-1, num);
		// cout<<inv1<<endl;
		// cout<<inv<<endl;
		if (inv%2==0)cout<<"Carlos"<<endl;
		else cout<<"Marcelo"<<endl;
	}
}

