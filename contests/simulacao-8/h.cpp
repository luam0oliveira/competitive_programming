/**
 *     author: demot.r
 *     created: 2024-11-16 10:51:19
 *     source: 
 *     description: solution of maicon
**/


#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n;
    string s;
    cin>>n>>s;
    int ans = 0, count = 1;

    if (n==2) {
        int ans1 =0, ans2 = 0;
        string s1, s2;
        for(int i=0;i <s.size();i++) {
            if (i&1) {
                s1 += '0';
                s2 += '1';
                ans1 += s[i] == '1';
                ans2 += s[i] == '0';
            } else {
                s1 += '1';
                s2 += '0';
                ans1 += s[i] == '0';
                ans2 += s[i] == '1';
            }
        }
        if (ans1 > ans2) {
            s = s2;
            ans = ans2;
        } else {
            s = s1;
            ans = ans1;
        }
    }else {
        for(int i=1;i<s.size();i++) {
            if (s[i-1] == s[i]) count++;
            else{
                count = 1;
            }

            if (count == n) {
                if (i + 1 < s.size() && s[i] != s[i+1]) {
                    s[i-1] = s[i-1] == '0' ? '1' : '0';
                } else {
                    s[i] = s[i] == '0' ? '1' : '0';
                }
                count = 1;
                ans++;
            }
        }
    }

    cout<<ans<<" "<<s<<endl;
    return 0;
}