// https://br.spoj.com/problems/RUMO9S/
// ad-rock

#include <bits/stdc++.h>

using namespace std;

int grau(string num)
{
    if (num.size() == 1 && num == "9")
        return 1;

    string newNum = "";
    int sum = 0;

    for (int i=0;i<num.size();i++)
        sum+= num[i] - '0';

    if (sum % 9 != 0)
        return 0;

    for(int i =5;i>=0;i--){
        int pot10 = pow(10,i);
        int ii = (sum - (sum % pot10));
        if (ii != 0){
            newNum+= (char) (ii/pot10 + '0');
        }
        sum -=ii;
    }
    
    int g = grau(newNum);
    return 1 + g;
}

int main() {
    while(1){
        string n;cin>>n;
        if (n=="0") break;
        int g = grau(n);
        if (g ==1)
            cout <<n<<" is a multiple of 9 and has 9-degree "<<g<<"."<<endl;
        else if (g != 0)
            cout <<n<<" is a multiple of 9 and has 9-degree "<<g-1<<"."<<endl;
        else
            cout<<n<<" is not a multiple of 9."<<endl;
    }
}