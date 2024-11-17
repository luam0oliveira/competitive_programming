// WRONG SOLUTION
// I just cannot solve at moment

#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> KMPSearch(string& pat, string& txt, vector<int> &lps)
{
    int M = pat.length();
    int N = txt.length();

    int i = 0; // index for txt
    int j = 0; // index for pat
    vector<int> result;
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            result.push_back(i-j+1);
            j = lps[j-1];
        }

        else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return result;
}


int main() {
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        int n;cin>>n;
        vector<int> kmp = {0,1,0,0};
        string pat = "1100";
        vector<int> result = KMPSearch(pat, s, kmp);
        for(int i=0;i<n;i++){
            int a,b;cin>>a>>b;
            s[a-1] =(char) '0'+  b;
            int en = false;
            for(int j=0;j<result.size();j++){
                int id = result[j]-1;
                // cout<<id<<endl;
                if (s[id]=='1' && s[id+1]=='1' && s[id+2]=='0' && s[id+3] == '0'){
                    cout<<"YES"<<endl;
                    en =true;
                    break;
                }else{
                    result.erase(result.begin()+j);
                    j--;
                }
            }
            if (!en){
                result = KMPSearch(pat,s,kmp);
                if (result.size() == 0){
                    cout<<"NO"<<endl;
                }else{
                    cout<<"YES"<<endl;
                }
            }
        }
    }    
    return 0;
}