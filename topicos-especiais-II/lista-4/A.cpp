#include <bits/stdc++.h>
#define ll long long

using namespace std;

int calcLis(vector<pair<int,int>> &number, vector<double> &mult) {
  int k = 0, n = number.size();
  vector<double> maior(number.size());
  for(int i=0;i<n;i++) {
    int pos = lower_bound(maior.begin(), maior.begin() + k, number[i].second * mult[number[i].first]) - maior.begin();
    if (pos == k) {
      k++;
    }
    maior[pos] = number[i].second * mult[number[i].first];
  }
  return k;
}

int main() {
  int n;cin>>n;
  vector<pair<int,int>> vec; vec.reserve(n);
  for(int i=0;i<n;i++) {
    string s;cin>>s;
    int cd = 0;
    if (s[0] == 'W') cd = 1;
    else if (s[0] == 'E') cd = 2;
    else if (s[0] == 'R') cd = 3;
    else if (s[0] == 'C') cd = 4; 
    int nb = stoi(s.substr(1));
    vec.push_back({cd, nb});
  }

  vector<double> ord = {0.000001,1, 100001, 11000000000L, 11000000000000L};
  int ans = 1e6;

  do {
    int lis = calcLis(vec, ord);
    ans = min(ans,n - lis);
  } while (next_permutation(ord.begin(), ord.end() -1));

  cout << ans << endl;
}