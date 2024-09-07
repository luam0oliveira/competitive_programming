// https://codeforces.com/contest/208/problem/A
// ad-rock

#include<bits/stdc++.h>
#define ll long long
#define QUAT(x) x*x;
using namespace std;


string substr(string s, int idx, int len) {
    string ss;
    for(int i = 0; i < 3 && idx + i < len;i++){
        ss += s[idx+i];
    }
    return ss;
}

int main(){
    string s; cin>>s;
    int ssz = s.size();
    string f;
    for (int i = 0; i < ssz;){
        if (substr(s,i,ssz) == "WUB") i+=3;
        else{
            while (substr(s,i,ssz) != "WUB" && i < ssz)
                f+=s[i++];
            f+=" ";
        }
    }
    for(int i = 0; i<(int)f.size()-1;i++)
        cout<<f[i];
    cout<<endl;
}
