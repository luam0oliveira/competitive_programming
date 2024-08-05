// https://br.spoj.com/problems/PLAGIO/
// KMP

#include <bits/stdc++.h>
#define MAXX 1e8
#define ll long long

using namespace std;

int parseNota(string& nota){
    int ff = -1;
    if (nota=="A") ff = 0;
    else if (nota=="Bb" || nota=="A#") ff = 1;
    else if (nota=="B" || nota=="Cb") ff = 2;
    else if (nota=="C" || nota=="B#") ff = 3;
    else if (nota=="C#" || nota=="Db") ff = 4;
    else if (nota=="D") ff = 5;
    else if (nota=="Eb" || nota=="D#") ff = 6;
    else if (nota=="E" || nota=="Fb") ff = 7;
    else if (nota=="F" || nota=="E#") ff = 8;
    else if (nota=="Gb" || nota=="F#") ff = 9;
    else if (nota=="G") ff = 10;
    else ff = 11;
    return ff;
}

vector<int> generateLPS(vector<int>& arr){
    vector<int> lps(arr.size());
    lps[0] = 0;

    int len = 0;
    int i = 1;
    int sz = arr.size();
    while(i<sz){
        if (arr[i] == arr[len]){
            lps[i++] = ++len;
        }else{
            if (len!=0){
                len = lps[len - 1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int kmp(vector<int>& lps, vector<int>& original, vector<int>& comp){
    int i =0;
    int j =0;
    int N = original.size(), M = comp.size();

    while(i < original.size()){
        if (original[i] == comp[j]){
            i++;j++;
            if (j == comp.size()){
                j =lps[j-1];
                return 1;
            }
        } else {
            if (j!=0){
                j = lps[j-1];
            }else{
                i++;
            }
        }
    }
    return 0;
}




int main(){
    int m,t;
    while (cin>>m>>t && !(m==0 && t == 0)){
        string nota;
        vector<int> original(m), comparacao(t);
        for(int i =0;i<m;i++){
            cin>>nota;original[i] = parseNota(nota);
        }
        for(int i=0;i<t;i++){
            cin>>nota;comparacao[i] = parseNota(nota);
        }
        vector<int> lps = generateLPS(comparacao);
        bool encontrado = false;
        for (int i =0;i<12 && !encontrado;i++){
            for(int j = 0;j<comparacao.size();j++){
                comparacao[j] = (comparacao[j]+1)%12;
            }
            encontrado = kmp(lps, original, comparacao);
        }

        if (encontrado) cout<<"S";
        else cout<<"N";
        cout<<endl;
    }
}
