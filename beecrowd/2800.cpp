// https://judge.beecrowd.com/pt/problems/view/2800
// SRD

#include<bits/stdc++.h>
using namespace std;

const int MAXNUM = 1e5 +1;
const int MAXBLOCKS = sqrt(MAXNUM) + 1;
int blocks[MAXBLOCKS][MAXNUM];

int nums[MAXNUM];
int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n, q;cin>>n>>q;
  int SQN = MAXBLOCKS;
  for (int i =0;i<n;i++){
    cin>>nums[i];
    blocks[i/SQN][nums[i]]++;
  }

  for(int i = 0;i<q;i++){
    int x,w,y,z;cin>>x>>w>>y;
    if (x==1){
      w--;
      blocks[w/SQN][nums[w]]--;
      blocks[w/SQN][y]++;
      nums[w] = y;
    }
    else{
      w--;
      y--;
      cin>>z;
      int cont = 0;
      int initBlockPos = w/SQN;
      int initInPos = w%SQN;
      int endBlockPos = y/SQN;
      int endInPos = y%SQN;
      if (initBlockPos == endBlockPos){
        for (int i = initInPos; i <= endInPos;i++){
          if (nums[initBlockPos*SQN+i] == z)
            cont++;
        }
      }
      else{
        for(int i = 0; i < SQN - initInPos; i++){
          if (nums[SQN*initBlockPos + i + initInPos] == z) cont++;
        }

        for (int i = 0 ; i <= endInPos; i++){
          if (nums[SQN*endBlockPos+endInPos-i] == z) cont++;
        }
        
        w = initBlockPos+1;
        y = endBlockPos;

        for (int i = initBlockPos+1; i < endBlockPos;i++){
          cont+=blocks[i][z];
        }

      }


      cout<<(y - w + 1) - cont<<endl;
    }
  }

}