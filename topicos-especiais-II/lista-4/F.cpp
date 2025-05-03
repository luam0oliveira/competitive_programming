#include <bits/stdc++.h>

using namespace std;

struct team {
  string name;
  int score, ord;

  bool operator<(team&other) {
    if (score == other.score) return ord > other.ord;
    return score < other.score; 
  }
};

int main() {
  int n;cin>>n;
  vector<team> teams(n);
  for(int i=0;i<n;i++) {
    team t;

    cin>>t.name;
    
    int sum = 0;
    int minim = 10, maxi = 0;
    cin>>t.score;
    t.ord = i;
    t.score*=10;
    for(int i=0;i<6;i++) {
      int a;cin>>a;
      sum+=a;
      minim = min(minim, a);
      maxi = max(maxi, a);
    }

    sum-=minim+maxi;
    t.score+=sum;
    teams[i] = t;
  }
  sort(teams.rbegin(), teams.rend());
  int comp = 0;
  for(int i=0;i<n;i++) {
    // cout << teams[i].name<<endl;
    if (teams[i].score == comp || i < 3) {
      cout << teams[i].name<<" "<<teams[i].score<<endl;
      comp = teams[i].score;
    } else {
      break;
    }
  }
}