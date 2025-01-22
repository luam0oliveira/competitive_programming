#include<bits/stdc++.h>
#include<bits/extc++.h>
#define ll long long
#define ii pair<int,int>
#define INF 1e9
#define EPS 1e-9
#define ALL(X) X.begin(), X.end()
#define LSOne(S) (S & -(S))
using namespace std;
using namespace __gnu_pbds;
// Template to use pbds
template<class T>
using Tree = tree<T, null_type, less<T>,splay_tree_tag, tree_order_statistics_node_update>;
// Template to use pbds
typedef vector<ii> vii;
int main() {
    int t;cin>>t;
    while(t--) {
        int n,l,r;cin>>n>>l>>r;
        l--;
        r--;
        ll sum = 0;
        vector<int> nums(n), interv;
        for(int i=0;i<n;i++) {
            cin>>nums[i];
            if (i >= l && i <= r){
                interv.push_back(nums[i]);
                sum += nums[i];
            }
        }
        sort(interv.rbegin(), interv.rend());
        sort(nums.begin(), nums.begin() + l);
        sort(nums.begin() + r + 1, nums.end());
        ll ans1 = sum, ans2 = sum;
        vector<int> candL, candR;
        int j = 0;
        for(int i=0;i<l;i++) {
            if (nums[i] < interv[j]){
                candL.push_back(i);
                ans1-=interv[j];
                ans1+=nums[i];
                j++;
                if (j >= interv.size()) break;
            }
        }
        j = 0;
        for(int i=r+1;i<n;i++) {
            if (nums[i] < interv[j]){
                candR.push_back(i);
                ans2-=interv[j];
                ans2+=nums[i];
                j++;
                if (j >= interv.size()) break;
            }
        }


        cout << min(ans1,ans2)<<endl;

        
    }
    return 0;
}