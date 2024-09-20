/**
 *     author: demot.r
 *     created: 2024-09-16 22:01:49
 *     source: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=submit_problem&problemid=353&category=0
 *     description: brute-force / ad-rock
**/
#include<bits/stdc++.h>
#define ll long long

using namespace std;

int gcd(int a, int b){
    if (b > a) return gcd(b, a);
    int aux;
    while(b != 0) {
        aux = b;
        b = a%b;
        a = aux;
    }

    return a;
}

const int maxn = 50;
int nums[maxn];

int main() {
	int n;
    while(1){
        cin>>n;
        if (!n) break;


        for(int i = 0;i<n;i++){
            cin>>nums[i];
        }
        int count = 0;
        int cc = (n*(n-1))/2;
        
        for(int i = 0 ; i < n; i++){
            for (int j  = i+1; j<n;j++){
                if (gcd(nums[i], nums[j]) == 1) count++;
                // cc++;
            }
        }
        double ans = 0;
        if (count){
            ans = sqrt((((6*cc)*1.0)/count * 1.0));
        }

        if (ans){
            cout<<fixed<<setprecision(6)<<ans<<endl;
        }else{
            cout<<"No estimate for this data set."<<endl;
        }    
    }

	return 0;
}
