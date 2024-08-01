// https://br.spoj.com/problems/DECADARI/
// ad-rock

#include <bits/stdc++.h>

using namespace std;

int getNumber(char character){
	return character - '0';
}

const double conv = 0.864;

int toDecimal(string traditional){
	int hh=getNumber(traditional[0])*10+getNumber(traditional[1]);
	int mm=getNumber(traditional[2])*10+getNumber(traditional[3]);
	int ss=getNumber(traditional[4])*10+getNumber(traditional[5]);
	int cc=getNumber(traditional[6])*10+getNumber(traditional[7]);
	int totalInCC = cc+ss*100+mm*6000+hh*360000;
	// cout << totalInCC<<endl;

	int decimal = totalInCC / conv;

	return decimal;
}

int main() {
	
	string traditional, decimal;
	while(cin>>traditional){
		printf("%07d\n", toDecimal(traditional));
	}

}