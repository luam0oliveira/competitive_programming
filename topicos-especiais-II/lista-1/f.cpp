#include<bits/stdc++.h>
// #include<bits/extc++.h>
#define ll long long
#define ii pair<int,int>
#define INF 1e9
#define EPS 1e-9
#define ALL(X) X.begin(), X.end()
#define LSOne(S) (S & -(S))
#define ZZZZ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
// using namespace __gnu_pbds;
// // Template to use pbds
// template<class T>
// using Tree = tree<T, null_type, less<T>,splay_tree_tag, tree_order_statistics_node_update>;
// Template to use pbds
typedef vector<ii> vii;

int gcd(int a, int b) {
    if (b > a) return gcd(b,a);
    while(b) {
        int aux = b;
        b = a%b;
        a = aux;
    }
    return a;
}

int main() {
    ZZZZ
    int n;cin>>n;
    int sum = 0, gA = 0, zero = 0;
    unordered_map<int,int> quant;
    
    for(int i=0;i<n;i++) {
        int a,b;cin>>a>>b;
        sum+=a;
        quant[a]++;
        if (!a) zero = 1;

        if (!gA) {
            gA = b;
        } 
        gA = gcd(gA, b);
    }


    vector<vector<int>> dp(quant.size()+1, vector<int>(sum+1));
    for(int i=1;i<=sum;i++) dp[0][i] = -1;
    dp[0][0] = 0;
    auto it = quant.begin();
    for(int i=1;i<=quant.size();i++, it++) {
        int b = it->first, c = it->second;
        for(int j=0;j<=sum;j++) {
            if (dp[i-1][j] >= 0) {
                dp[i][j] = 0;
            } else if (j - b >= 0 && dp[i][j-b] != -1 && dp[i][j-b] < c) {
                dp[i][j] = dp[i][j-b] + 1;
                // usados[j] = 1;
            } else {
                dp[i][j] = -1;
            }
        }
    }
    int pos = 0;
    for(int i=0;i<=sum;i++) {
        if (dp[quant.size()][i] != -1) {
            int a = i;
            int b = sum - i;
            int c = abs(a-b);
            int diff = c;
            if ((zero || (a && b)) && (diff % gA)== 0) {
                pos = 1; 
                break;
            } 
        }
    }


    if (pos) cout <<"Y"<<endl;
    else cout <<"N"<<endl;

    return 0;
}