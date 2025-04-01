#include<bits/stdc++.h>
#include<bits/extc++.h>
#define ll long long
#define ii pair<int,int>
#define INF 1e9
#define EPS 1e-9
#define ALL(X) X.begin(), X.end()
#define LSOne(S) (S & -(S))
#define ZZZZ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
using namespace __gnu_pbds;
// Template to use pbds
template<class T>
using Tree = tree<T, null_type, less<T>,splay_tree_tag, tree_order_statistics_node_update>;
// Template to use pbds
typedef vector<ii> vii;

int is_vowel(char c) {
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y';
}

int main() {
    int n;cin>>n;
    string ff;
    vector<string> strss;
    for(int i=0;i<n;i++) {
        string s;cin>>s;
        strss.push_back(s);
    }
    int quant = 0;
    int pos = true;
    for(int i=0;i<n-1;i++) {
        ff+=strss[i][0];
        if (is_vowel(strss[i][0]) || is_vowel(strss[i+1][0]) ||
         (i == n-2 && quant == 0) || (quant==0 && i < n-2 && is_vowel(strss[i+2][0]))) {
            quant = 0;
            continue;
        }
        quant++;        
        if ((quant == 1 && strss[i+1].size() > 1 && is_vowel(strss[i+1][1]))){
            continue;
        }
        if (strss[i].size() == 1) continue;
        ff+=strss[i][1];
        if (is_vowel(strss[i][1])) {
            quant = 0;
            continue;
        }

        quant++;

        if (strss[i].size() == 2) continue;
        if (is_vowel(strss[i][2])) quant = 0;
        ff+=strss[i][2];
    }
    ff += strss[n-1][0];
    quant = 0;
    for(auto c:ff) {
        if (is_vowel(c)) quant = 0;
        else quant++;
        if (quant == 3) pos =false;
    }
    if (pos) cout << ff.size() << endl;
    else cout<< "*"<<endl;

    return 0;
}