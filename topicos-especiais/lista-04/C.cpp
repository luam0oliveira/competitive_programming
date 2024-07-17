// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3344
// Divisão e conquista (uso de binary search para verificar cada linha(log n < n))
// O codigo pode ser melhorado utilizando binary search nas diagonais

#include <bits/stdc++.h>

using namespace std;

int linhas,colunas;

vector<vector<int>> matrix;
vector<int> inicioLinha;

void bsLinha(int i, int inicio, int fim){
	int left = 0, right = colunas-1, mid = left + (right - left)/2;

	// encontrar posMinima
	while (left <= right){
		if (matrix[i][mid] < inicio)
			left = mid + 1;
		else if (matrix[i][mid] > fim){
			right = mid - 1;
		}
		else{
			if ((mid-1 >= 0 && matrix[i][mid-1] < inicio) || mid == 0 ){
				inicioLinha[i] = mid;
				return;
			}
			right = mid - 1;
		}
		mid = left + (right - left)/2;
	}
	inicioLinha[i] = -1;
}

int buscaDiagonal(int i, int fim){
	int left = inicioLinha[i], right = min(colunas-1-left, linhas-1-i); 
	for (int j= right; j>0;j--){
		if (matrix[i+j][left+j]<=fim)
			return j;
	}
	return 0;
}

// int bsDiagonal(int i, int fim){
// 	int left = inicioLinha[i], right = min(colunas-1, linhas-1), mid = (right - left)/2;
// 	int direitamax = left+1;
// 	// encontrar posMinima
// 	while (left <= right){
// 		// cout<<right<<endl;
// 		if ((i+mid > linhas-1 || left+mid > colunas-1) || matrix[i+mid][left+mid] > fim)
// 			right = right - mid -1;
// 		else{
// 			if ((left+mid+1 < colunas && mid+i+1 < linhas && matrix[mid+i+1][left+mid+1] > fim) || left+mid == colunas-1 || mid+i == linhas==-1){
// 				return right;
// 			}
// 			// cout <<mid<<endl;
// 			left = left + mid + 1;
// 		}
// 		// cout<<mid<<endl;
// 		mid = (right - left)/2;
// 	}
// 	return 0;
// }


int main (){
	while(true){
		cin>>linhas>>colunas;
		if(linhas == 0 && colunas == 0)
			break;
		
		matrix.assign(linhas, vector<int>(colunas,0));
		inicioLinha.assign(linhas, -1);

		for(int i =0;i<linhas;i++)
			for(int j=0;j<colunas;j++)
				cin>>matrix[i][j];
		
		int t; cin>>t;
		int inicio,fim;
		while(t--){
			cin>>inicio>>fim;
			int maxx = 0;
			for(int i =0;i<linhas;i++)
				bsLinha(i, inicio, fim);
			for(int i =0;i<linhas;i++)
				if (inicioLinha[i]!=-1)
					// maxx = max(maxx, bsDiagonal(i, fim) - inicioLinha[i]);
					maxx = max(maxx, buscaDiagonal(i, fim)+1);
			cout<<maxx<<endl;
			// cout<<"============"<<endl;
		}
		cout<<"-"<<endl;

	}
}