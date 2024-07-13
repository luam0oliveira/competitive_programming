#include <bits/stdc++.h>
#define TAMLETRAS 26

using namespace std;

vector<string> matrix;

bool check(int original[], int comp[]){
	
	for(int i =0;i<TAMLETRAS;i++)
		if (original[i] != comp[i])
			return false;
	return true;
}

int main(){
	int linhas,colunas;cin>>linhas>>colunas;
	matrix.assign(linhas, "");
	for(int i =0;i<linhas;i++){
		cin>>matrix[i];
	}
	int cont[linhas][colunas];
	memset(cont, 0, sizeof cont);
	int n;cin>>n;
	for(int i=0;i<n;i++){
		string pl;cin>>pl;
		int tam = pl.size();
		int letrasP[TAMLETRAS];
		memset(letrasP, 0, sizeof letrasP);
		for (int j=0;j<pl.size();j++) letrasP[pl[j]-'A']++;

		int visitados[linhas][colunas];
		memset(visitados, 0, sizeof visitados);
		for (int j=0;j<linhas;j++){
			for(int k=0;k<colunas;k++){
				// testa linha
				if (k + tam <= colunas){
					int letrasL[TAMLETRAS];memset(letrasL, 0, sizeof letrasL);
					for (int l=k;l<k+tam;l++) letrasL[matrix[j][l]-'A']++;
					if (check(letrasP, letrasL)){
						for (int l=k;l<k+tam;l++) visitados[j][l] = 1;
					}
				}

				// testa coluna
				if (j + tam <= linhas){
					int letrasL[TAMLETRAS];memset(letrasL, 0, sizeof letrasL);
					for (int l=j;l<j+tam;l++) letrasL[matrix[l][k]-'A']++;
					if (check(letrasP, letrasL)){
						
						for (int l=j;l<j+tam;l++) visitados[l][k] = 1;
					}
				}
				
				// testa diagonal principal
				if (k + tam <= colunas && j+tam <=linhas){
					int letrasL[TAMLETRAS];memset(letrasL, 0, sizeof letrasL);
					for (int l=0;l<tam;l++) letrasL[matrix[j+l][k+l]-'A']++;
					if (check(letrasP, letrasL)){
						for (int l=0;l<tam;l++) visitados[j+l][k+l] = 1;
					}
				}

				// testa diagonal secundaria
				if (k + tam <= colunas && j-tam+1 >= 0){
					int letrasL[TAMLETRAS];memset(letrasL, 0, sizeof letrasL);
					for (int l=0;l<tam;l++) letrasL[matrix[j-l][k+l]-'A']++;
					if (check(letrasP, letrasL)){
						for (int l=0;l<tam;l++) visitados[j-l][k+l] = 1;
					}
				}
			}
		}
		for (int j=0;j<linhas;j++)
			for(int k=0;k<colunas;k++){
				if (visitados[j][k] > 0)
					cont[j][k]++;
			}
	}

	int cc=0;
	for (int j=0;j<linhas;j++)
		for(int k=0;k<colunas;k++)
			if(cont[j][k]>1)cc++;

	cout<<cc<<endl;


}