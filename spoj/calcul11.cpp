// https://br.spoj.com/problems/CALCUL11/
// ad-rock

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; scanf("%d ", &n);
    pair<int,int> ops[10];
    
    for(int i =0;i<10;i++){
        ops[i] = {0,i};
    }
    
    while(n--){
        char num, sig; scanf("%c %c ", &num, &sig);
        if (sig=='/')
            ops[num-'0'].first++;
        else
            ops[num-'0'].first--;
    }
    sort(ops, ops+10);
    int ans = 1;
    for (int i=0; i<10;i++){
        int vabs = abs(ops[i].first);
        for(int j=0;j<vabs;j++){
            if (vabs != ops[i].first)
                ans*=ops[i].second;
            else
                ans/=ops[i].second;
        }
    }
    
    cout<<ans<<endl;
    return 0;
}
